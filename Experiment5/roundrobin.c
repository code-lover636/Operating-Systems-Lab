#include <stdio.h>

int printTable(int n, int bt[n], int at[n], int tat[n], int wt[n]){
    int avgT=0, avgW=0;
    printf("Process ID:\tArrival Time:\tBurst Time:\tTurn Around Time:\tWait Time:\n");
    for(int i=0; i<n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", i+1, at[i], bt[i], tat[i], wt[i]);
        avgT += tat[i];
        avgW += wt[i];
    }
    printf("Average Turn Around Time: %f\n", (float)avgT/n);
    printf("Average Waiting Time: %f\n", (float)avgW/n);
}

int roundRobin(int n, int bt[n], int at[n], int quanta){
    int remainingTime[n], tat[n], wt[n], completed = 0, time=0, flag;
    for(int i=0; i<n; i++) remainingTime[i] = bt[i];

    while(completed < n){
        flag = 0;
        for(int i=0; i<n; i++){
            if(remainingTime[i] != 0  && at[i] <= time){
                flag = 1;
                if(remainingTime[i] <= quanta){
                    time += remainingTime[i];
                    remainingTime[i] = 0;
                    completed++;
                    printf(">>Completion time of P%d=%d\n", i, time);
                    tat[i] = time - at[i];
                    wt[i] = tat[i] - bt[i];
                }
                else{
                    remainingTime[i] -= quanta;
                    time += quanta;
                }
            }
        }
        if(!flag){
            time += quanta;
        }
    }

    printTable(n, bt, at, tat, wt);
}


int main(){
	int n, quanta;
	printf("Enter no. of process: ");
	scanf("%d", &n);
	printf("Enter time quanta: ");
	scanf("%d", &quanta);
	
	int bt[n], at[n];
	for(int i=0; i<n; i++){
        printf("Enter arrival time of process %d: ", i+1);
		scanf("%d", &at[i]);
		printf("Enter burst time of process %d: ", i+1);
		scanf("%d", &bt[i]);
	}



    roundRobin(n, bt, at, quanta);
}


