#include <stdio.h>
#include <unistd.h>

void main(){ 
    fork(); 
    fork(); 

    printf("HELLO\n"); 
    fork();

    printf("WELCOME\n"); 
}