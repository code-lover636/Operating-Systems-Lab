#include <stdio.h>
#include <stdlib.h> 
#include <dirent.h> 

int main() { 
    DIR *dir = opendir("."); 

    if (dir==NULL){
        printf("Cannot access directory.\n");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry; 
    printf("Directory contents:\n");
    while ((entry = readdir(dir)) != NULL) 
        printf("%s\n", entry->d_name); 

    closedir(dir); 
}