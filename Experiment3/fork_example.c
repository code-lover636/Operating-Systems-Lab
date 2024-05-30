#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
	pid_t pid = fork();
	
	if(pid<0){
		perror("Child Process Creation Failed\n");
		exit(EXIT_FAILURE);
	}
	else if(!pid){
		printf("Child process id: %d\n", getpid());
		printf("Waiting for child process to complete...\n");
		sleep(2);  // Simulate some work in the child process
		exit(0);
	}
	else{
		printf("Parent process id: %d\n", getpid());
		wait(NULL);  // Wait for the child process to complete
        printf("Child process completed. Parent process continuing.\n");
	}
}
