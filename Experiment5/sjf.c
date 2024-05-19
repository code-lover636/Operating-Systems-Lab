// #include <stdio.h>
// #include <string.h>
// #include <limits.h>

// int shortestProcess(int n, int bt[n], int at[n], int flag[n]){
//     int sht = 0, time = 0;

//     for(int i = 0; i<n; i++){
//         if(flag[i] != 0)
//             continue;
//         sht = i;
//         break;
//     }

//     for(int i=0; i<n; i++){
//         if(flag[i]==0){
//             if(bt[sht]>=bt[i] && time >= at[i]){
//                 sht = i;
//                 time += bt[sht];
//             }
//             else
//                 time++;

//         }
//     }
//     flag[sht] = 1;
//     return sht;
// }

// int ganttChart(int n, int bt[n], int at[n]){
//     int chart[100], cur=0, flag[n], m=n;
//     memset(flag, 0, sizeof(flag));

//     while(m>0){
//         int sht = shortestProcess(n, bt, at, flag);
//         for(int i=0; i<bt[sht]; i++){
//             chart[cur++] = sht+1;
//         }
//         m--;
//     }

//     printf("\nGANT CHART: ");
//     for(int i=0; i<cur; i++){
//         printf("%d,\t", chart[i]);
//     }
//     printf("\n");

// }

// int main(){
// 	int n;
// 	printf("Enter no. of process: ");
// 	scanf("%d", &n);
	
// 	int bt[n], at[n];
// 	for(int i=0; i<n; i++){
// 		printf("Enter burst time of process %d: ", i+1);
// 		scanf("%d", &bt[i]);
		
// 		printf("Enter arrival time of process %d: ", i+1);
// 		scanf("%d", &at[i]);
// 	}

// 	ganttChart(n, bt, at);
// }



#include <stdio.h>

// Structure to represent a process
struct Process {
    int pid;      // Process ID
    int bt;       // Burst Time
    int wt;       // Waiting Time
    int tat;      // Turnaround Time
};

// Function to swap two processes
void swap(struct Process *a, struct Process *b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort processes by burst time
void sortProcessesByBurstTime(struct Process proc[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (proc[j].bt > proc[j + 1].bt) {
                swap(&proc[j], &proc[j + 1]);
            }
        }
    }
}

// Function to calculate waiting time for all processes
void calculateWaitingTime(struct Process proc[], int n) {
    proc[0].wt = 0;  // Waiting time for first process is 0
    for (int i = 1; i < n; i++) {
        proc[i].wt = proc[i - 1].bt + proc[i - 1].wt;
    }
}

// Function to calculate turnaround time for all processes
void calculateTurnaroundTime(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].tat = proc[i].bt + proc[i].wt;
    }
}

// Function to calculate average time
void calculateAverageTime(struct Process proc[], int n) {
    calculateWaitingTime(proc, n);
    calculateTurnaroundTime(proc, n);

    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += proc[i].wt;
        total_tat += proc[i].tat;
        printf("Process %d: Burst Time = %d, Waiting Time = %d, Turnaround Time = %d\n",
               proc[i].pid, proc[i].bt, proc[i].wt, proc[i].tat);
    }

    printf("Average Waiting Time = %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time = %.2f\n", (float)total_tat / n);
}

int main() {
    struct Process proc[] = {{1, 6}, {2, 8}, {3, 7}, {4, 3}};
    int n = sizeof(proc) / sizeof(proc[0]);

    // Sort processes by burst time
    sortProcessesByBurstTime(proc, n);

    printf("Order of execution after sorting by burst time:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d (Burst Time = %d)\n", proc[i].pid, proc[i].bt);
    }

    // Calculate average waiting time and average turnaround time
    calculateAverageTime(proc, n);

    return 0;
}
