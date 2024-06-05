#include <stdio.h>
#include <stdlib.h>

int scanShedule(int no_of_requests, int requests[no_of_requests], int current){
    int seek_time = 0, start_index=0, counter;

    while(requests[start_index]<=current)
        start_index++;
    counter = start_index;
    start_index++;

    while(start_index < no_of_requests){
        seek_time += abs(requests[start_index] - current);
        current = requests[start_index];
        start_index++;
    }
    seek_time += abs(199 - requests[start_index-1]);
    current = 199;
    // while(counter>0){
    for(int i=0; i<counter; i++){
        // counter--;
        // seek_time += abs(requests[counter] - current);
        seek_time += abs(requests[i] - current);
        current = requests[i];
    }

    return seek_time;
}

int main() {
    int no_of_requests, current;
    printf("Enter the number of disk requests: ");
    scanf("%d", &no_of_requests);
    no_of_requests += 1;
    int requests[no_of_requests];
    requests[0] = 0;

    printf("Enter initial head position: ");
    scanf("%d", &current);

    printf("Enter %d disk requests: ", no_of_requests-1);
    for (int i = 1; i < no_of_requests; i++)
        scanf("%d", &requests[i]);
    
    // Sort the request array
    for (int i=0; i < no_of_requests - 1; i++) {
        for (int j = 0; j < no_of_requests - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    printf("No. of head movement = %d\n", scanShedule(no_of_requests, requests, current));
}

