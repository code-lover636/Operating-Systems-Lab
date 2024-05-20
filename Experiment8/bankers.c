#include <stdio.h>
#include <string.h>

void print(int P, int R, int m[][R]){
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
    
    printf("Resource need\n");
    print(P, R, need);
}

void bankerAlgorithm(int P, int R, int available[], int max[][R], int allocate[][R]) {
    int need[P][R], work[R], finish[P], count = 0, found, flag;
    memset(finish, 0, sizeof(finish));
    
    calcNeed(P, R, max, need, allocate);
    
    for (int i = 0; i < R; i++)
        work[i] = available[i];
        

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
                    printf("Available Resources");
                    for (int k = 0; k < R; k++)
                        printf("-%d",work[k]);
                        
                    printf("\nprocess-p%d can be allocated resources",i);
                    for (int k = 0; k < R; k++)
                        printf("-%d",need[i][k]);
                        
                       
                    
                    for (int k = 0; k < R; k++) 
                        work[k] += allocate[i][k];
                        
                    printf("\n");
                    finish[i] = 1;
                    found = 1;
                    count++;
                }
            }
        }
        if (found == 0) 
            printf("Unsafe state\n");
       
    }	
    printf("Safe state\n");
}


int main() {
    int P, R;
    printf("Enter no. of processes: ");
    scanf("%d", &P);
    printf("Enter no. of resources: ");
    scanf("%d", &R);

    int available[R], max[P][R], allocate[P][R];

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

    bankerAlgorithm(P, R, available, max, allocate);

}