#include <stdio.h>
#include <string.h>

void firstFit(int block[], int m, int process[], int n) {
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (block[j] >= process[i]) {
                allocation[i] = j;
                block[j] -= process[i];
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, process[i]);
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
    firstFit(block, m, process, n);
}