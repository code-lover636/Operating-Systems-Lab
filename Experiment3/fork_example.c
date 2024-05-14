#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){
	pid_t pid;
	pid = fork();
	
	if(pid<0){
		perror("Child Process Creation Failed\n");
		exit(EXIT_FAILURE);
	}
	else if(pid==0){
		printf("Child process created successfully.\n");
		printf("Child process id: %d\n", getpid());
	}
	else{
		printf("Parent process id: %d\n", getpid());
	}
}
