#include <stdio.h>
#include <string.h>

void bestFit(int block[], int m, int process[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (block[j] >= process[i]) {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (block[bestIdx] > block[j])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            block[bestIdx] -= process[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++) {
        printf(" %d\t\t%d\t\t", i + 1, process[i]);
        if (allocation[i] != -1)
            printf("%d", allocation[i] + 1);
        else
            printf("Not Allocated");
        printf("\n");
    }
    printf("Free Blocks\n");
    for (int i = 0; i < m; i++) printf("%d->",block[i]);
    printf("\n");
}
int main() {
    int m, n;
    printf("Enter no of blocks: ");
    scanf("%d", &m);
    printf("Enter no of processes: ");
    scanf("%d", &n);
    
    int process[n], block[m];
    
    for(int i=0; i<m; i++){
    	printf("Enter block size: ");
    	scanf("%d", &block[i]);
    }
    
    for(int i=0; i<n; i++){
    	printf("Enter process size: ");
    	scanf("%d", &process[i]);
    }
    bestFit(block, m, process, n);
    return 0;
}
