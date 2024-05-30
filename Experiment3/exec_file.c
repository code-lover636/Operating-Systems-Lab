#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){
	pid_t pid = fork();
	
	if(pid<0){
		perror("child Process Creation Failed\n");
		exit(EXIT_FAILURE);
	}
	else if(pid==0){
		printf("Child process created successfully.\n");
		char *args[] = {"./hello", NULL};
		execvp(args[0], args);
	}
}
