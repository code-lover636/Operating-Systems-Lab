#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int in = 0, out = 0, buffer[BUFFER_SIZE];
sem_t mutex, empty, full;

void *producer(void *arg){
    for (int i = 0; i < BUFFER_SIZE; i++) {
        sem_wait(&empty);
        sem_wait(&mutex);

        int item = rand() % 100;
        buffer[in] = item;
        printf("in: %d\tout: %d\nProducer: %d\n\n", in, out, item);
        in = (in + 1) % BUFFER_SIZE;

        sem_post(&mutex);
        sem_post(&full);
        sleep(1);
    }
    pthread_exit(NULL);
}

void *consumer(){

    for (int i = 0; i < BUFFER_SIZE; i++) {
        sem_wait(&full);
        sem_wait(&mutex);

        int item = buffer[out];
        printf("in: %d\tout: %d\nConsumer: %d\n\n", in, out, item);
        out = (out + 1) % BUFFER_SIZE;

        sem_post(&mutex);
        sem_post(&empty);

        sleep(1);
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t producerTh, consumerTh;

    // Enter no of producer and consumer threads
    int p_num, c_num;
    printf("Enter no of producers: ");
    scanf("%d", &p_num);
    printf("Enter no of consumers: ");
    scanf("%d", &c_num);

    printf("\nBuffer size = 5\n\n");

    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    // Create threads
    for(int i=0; i<p_num; i++)
        pthread_create(&producerTh, NULL, producer, NULL);

    for(int i=0; i<c_num; i++)
        pthread_create(&consumerTh, NULL, consumer, NULL);

    // Wait for thread to finish
    for(int i=0; i<p_num; i++)
        pthread_join(producerTh, NULL);

    for(int i=0; i<c_num; i++)
        pthread_join(consumerTh, NULL);

}