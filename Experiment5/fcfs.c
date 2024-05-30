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


int fcfs(int n, int bt[n], int at[n]){
	int completed=0, time=0, tat[n], wt[n];

	while(completed<n){
		for(int i=0; i<n; i++){
			if(at[i]<=time){
				time += bt[i];
				tat[i] = time - at[i];
				wt[i] = tat[i] - bt[i];
				completed++;
			}
			else
				time++;
		}
	}
	printTable(n, bt, at, tat, wt);
}

int main(){
	int n;
	printf("Enter no. of process: ");
	scanf("%d", &n);
	
	int bt[n], at[n];
	for(int i=0; i<n; i++){
		printf("Enter arrival time of process %d: ", i+1);
		scanf("%d", &at[i]);

		printf("Enter burst time of process %d: ", i+1);
		scanf("%d", &bt[i]);
	}

	fcfs(n, bt, at);
}


