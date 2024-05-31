#include <stdio.h>
#include <string.h>

void calcFirstFit(int no_of_blocks, int blocks[no_of_blocks], int no_of_process, int processes[no_of_process]) {
    int allocation[no_of_process];
    memset(allocation, -1, sizeof(allocation));

    for (int i = 0; i < no_of_process; i++) {
        for (int j = 0; j < no_of_blocks; j++) {
            if (blocks[j] >= processes[i]) {
                allocation[i] = j;
                blocks[j] -= processes[i];
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < no_of_process; i++) {
        printf("%d\t\t%d\t\t", i + 1, processes[i]);
        if (allocation[i] != -1)
            printf("%d", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }

    printf("\nFragments: ");
    for (int i = 0; i < no_of_blocks; i++)
        printf("%d->",blocks[i]);
    printf("\n");
}

int main() {
    int no_of_blocks, no_of_process;
    printf("Enter no of blocks: ");
    scanf("%d", &no_of_blocks);
    printf("Enter no of processes: ");
    scanf("%d", &no_of_process);
    
    int processes[no_of_process], blocks[no_of_blocks];
    
    for(int i=0; i<no_of_blocks; i++){
    	printf("Enter block%d size: ", i+1);
    	scanf("%d", &blocks[i]);
    }
    
    for(int i=0; i<no_of_process; i++){
    	printf("Enter process%d size: ", i+1);
    	scanf("%d", &processes[i]);
    }
    calcFirstFit(no_of_blocks, blocks, no_of_process, processes);
}