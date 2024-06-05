#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int P, int R, int m[P][R]){
    for(int i=0;i<P;i++){
	    for(int j=0;j<R;j++)
		    printf("%d\t",m[i][j]);
	    printf("\n");
    }
}

void calcNeed(int P, int R, int max[P][R], int need[P][R], int allocate[P][R]){
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - allocate[i][j];
    
    printf("Need Matrix: \n");
    print(P, R, need);
    printf("\n");
}

void bankersAlgorithm(int P, int R, int available[R], int max[P][R], int allocate[P][R], int need[P][R]) {
    int work[R], finish[P], count = 0, found, flag;
    memset(finish, 0, sizeof(finish));    
    for (int i = 0; i < R; i++) work[i] = available[i];    

    while (count < P) {
        found = 0;
        for (int i = 0; i < P; i++) {
            if (!finish[i]){
                flag = 1;

                for (int j = 0; j < R; j++)
                    if (need[i][j] > work[j]){ 
                        flag = 0;
                        break;
                    }

                if (flag) {                   
                    printf("P%d ", i);
                        
                    for (int k = 0; k < R; k++) 
                        work[k] += allocate[i][k];
                    finish[i] = 1;
                    found = 1;
                    count++;
                }
            }
        }
        if (found == 0){
            printf("\nUnsafe state\n");
            return;
        }
       
    }	
    printf("\nSafe state\n");
}


int compare(int R, int matrix[R], int request[R]){
    for(int j=0; j<R; j++)
        if(matrix[j] < request[j])
            return 0;
    return 1;
}

int request(int P, int R, int available[R], int max[P][R], int allocate[P][R], int need[P][R]){
    int id, request[R];
    printf("New Request: Enter process ID (1-n): ");
    scanf("%d", &id);
    id--;

    printf("Enter request vector: ");
    for(int i=0; i<R; i++)
        scanf("%d", &request[i]);

    //Compare with need matrix
    if( !compare(R, need[id], request) ){
        printf("Invalid request vector. Process has exceeded its maximum claim.\n");
        exit(0);
    }

    //Compare with available vector
    if( compare(R, available, request) ){     
        //Needi = Needi - request
        for(int i=0; i<R; i++) need[id][i] -= request[i];
        //allocatei = allocatei + request
        for(int i=0; i<R; i++) allocate[id][i] += request[i];
        //available = available - request
        for(int i=0; i<R; i++) available[i] -= request[i];
        bankersAlgorithm(P, R, available, max, allocate, need);
    }

}


int main() {
    int P, R;
    printf("Enter no. of processes: ");
    scanf("%d", &P);
    printf("Enter no. of resources: ");
    scanf("%d", &R);

    int available[R], max[P][R], allocate[P][R], need[P][R];

    printf("Enter available vector: ");
    for(int i=0; i<R; i++)
        scanf("%d", &available[i]);

    printf("Enter max matrix:\n");
    for(int i=0; i<P; i++)
        for (int j=0; j<R; j++)
            scanf("%d", &max[i][j]);

    printf("Enter allocate matrix:\n");
    for(int i=0; i<P; i++)
        for (int j=0; j<R; j++)
            scanf("%d", &allocate[i][j]);

    calcNeed(P, R, max, need, allocate);
    bankersAlgorithm(P, R, available, max, allocate, need);
    request(P, R, available, max, allocate, need);

}