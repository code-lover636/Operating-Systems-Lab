#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    char file[100];
    struct stat stats;

    printf("Enter the file name: ");
    scanf("%s", file);

    if (stat(file, &stats)){
        printf("Unable to get file properties.\n");
        exit(EXIT_FAILURE);
    }

    printf("\nFile permissions: ");
    if (stats.st_mode & S_IRUSR) printf("read ");
    if (stats.st_mode & S_IWUSR) printf("write ");
    if (stats.st_mode & S_IXUSR) printf("execute");

    printf("\nFile size: %ld bytes\n", stats.st_size);

    struct tm dt = *(gmtime(&stats.st_ctime));
    printf("Created on: %d-%d-%d %d:%d:%d\n",
           dt.tm_mday, dt.tm_mon + 1, dt.tm_year + 1900,
           dt.tm_hour, dt.tm_min, dt.tm_sec);

    dt = *(gmtime(&stats.st_mtime));
    printf("Modified on: %d-%d-%d %d:%d:%d\n",
           dt.tm_mday, dt.tm_mon + 1, dt.tm_year + 1900,
           dt.tm_hour, dt.tm_min, dt.tm_sec);
}