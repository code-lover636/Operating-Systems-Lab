#include <stdio.h>

int findWaitingTime(int n, int bt[], int wt[], int at[]){
	wt[0] = at[0];
	for(int i=1; i<n; i++){
		wt[i] = at[i-1] + wt[i-1] + bt[i-1] - at[i];
	}
	
}

int findTurnAroundTime(int n, int bt[], int wt[], int at[], int tat[]){
	for(int i=0; i<n; i++){
		tat[i] = wt[i] + bt[i];
	}
}

int findAverageTime(int n, int bt[], int at[]){
	int wt[n], tat[n], total_wt = 0, total_tat = 0;
	findWaitingTime(n, bt, wt, at);
	findTurnAroundTime(n, bt, wt, at, tat);
	
	printf("%s\t%s\t%s\t%s\n", "AT", "BT", "TAT", "WT");
	for(int i=0; i<n; i++){
		total_wt += wt[i];
		total_tat += tat[i];
		
		printf("%d\t%d\t%d\t%d\n", at[i], bt[i], tat[i], wt[i]);
	}
	
	printf("\nAverage waiting time: %.2f", (float)total_wt/n );
	printf("\nAverage turn around time: %.2f\n ", (float)total_tat/n );
}


int main(){
	int n;
	printf("Enter no. of process: ");
	scanf("%d", &n);
	
	int bt[n], at[n];
	for(int i=0; i<n; i++){
		printf("Enter burst time of process %d: ", i+1);
		scanf("%d", &bt[i]);
		
		printf("Enter arrival time of process %d: ", i+1);
		scanf("%d", &at[i]);
	}

	findAverageTime(n, bt, at);
}


