// C Program Implementation 
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a process
typedef struct {
    int name;      // Process name (1,2,3 ...)
    int arrival;    // Arrival time
    int burst;      // Burst time
    int remaining;  // Remaining burst time
    int status;  // in queue or not
    int completion;//completion time
    int waiting; // waiting time
    int turnaround; // turn around time
} Process;

// Structure to represent a node in the waiting queue
typedef struct Node {
    Process process;
    struct Node* next;
} Node;
Node *front=NULL;
Node *rear=NULL;

// Function to enqueue a process into the waiting queue
void enqueue(Process process) {
    Node* newNode = (Node*)malloc(sizeof(Node));
 
    newNode->process = process;
    newNode->next = NULL;

    if (front == NULL) {
        front=rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Function to dequeue a process from the waiting queue
Process dequeue() {
   
    Node* temp = front;
    Process process = temp->process;
    front = front->next;
    free(temp);
    return process;
}
void printqueue()
{
    Node *temp=front;
    while(temp!=NULL)
    {
        printf("%d-->",temp->process.name);
        temp=temp->next;
        
    }
    printf("NULL\n");
}
int main() {
    // Define the processes
    Process processes[] = {
        {1, 0, 5, 5,0,-1,-1,-1},  
        {2, 1, 6, 6,0,-1,-1,-1},  
        {3, 2, 3, 3,0,-1,-1,-1},
        {4, 3, 1, 1,0,-1,-1,-1},  
        {5, 4, 5, 5,0,-1,-1,-1},  
        {6, 6, 4, 4,0,-1,-1,-1}
        
    };
    int n = sizeof(processes) / sizeof(Process); // Number of processes

    // Time quantum
    int quantum = 4;

    // Initialize variables
    int currenttime = 0;
    int completed = 0;
   
    printf("Time  |  Process\n");
    printf("------+-------------------\n");

    // Loop until all processes are completed
     enqueue(processes[0]);
     processes[0].status=1;
    while (completed < n ) {
        // Enqueue processes that arrive at the current time
        
       //  printqueue();
        // Execute processes in the waiting queue
        if (front != NULL) {
            Process currentProcess = dequeue();
            int execution_time = (currentProcess.remaining < quantum) ? currentProcess.remaining : quantum;
            currentProcess.remaining -= execution_time;
            currenttime += execution_time;
            for (int i = 0; i < n; i++) {
                if (processes[i].arrival <= currenttime && processes[i].status!=1) {
                    enqueue(processes[i]);
                    processes[i].status=1;
                }
            }
            printf("%-5d |  P%d\n", currenttime, currentProcess.name);
            if (currentProcess.remaining <= 0) {
                completed++;
                for(int i=0;i<n;i++) if (processes[i].name==currentProcess.name)
                           {processes[i].completion=currenttime;break;}
            } else {
                currentProcess.status=1;
                enqueue(currentProcess);
            }
        } else {
            currenttime++; // Move to the next time unit if no process is ready to execute
        }
    }

    float avwt=0.0;
    float avtat=0.0;
    printf("Process ArrivalTime BurstTime  CompletionTime  TurnAroundTime WaitingTime\n");
    for(int i=0;i<n;i++)
    {
    processes[i].turnaround=processes[i].completion-processes[i].arrival;
    processes[i].waiting=processes[i].turnaround-processes[i].burst;
    printf("P%d%10d%10d%20d%10d%20d\n",processes[i].name,processes[i].arrival,processes[i].burst,processes[i].completion,processes[i].turnaround,processes[i].waiting);
    avwt=avwt+processes[i].waiting;
    avtat=avtat+processes[i].turnaround;
    }
    printf("Average Waiting Time=%f\n",avwt/n);
    printf("Average Turn Around Time=%f\n",avtat/n);
      return 0;  
}