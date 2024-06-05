#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *filename = "my_file.txt";
    int fd;

    fd = open(filename, O_CREAT | O_WRONLY, 0644);
    if (fd == -1) {
        perror("Error creating/opening file");
        exit(EXIT_FAILURE);
    }

    const char *data = "Hello, world!";
    ssize_t bytes_written = write(fd, data, strlen(data));
    if (bytes_written > 0)
        printf("Wrote %ld bytes to the file.\n", bytes_written);

    close(fd);

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    char buffer[100];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read > 0) {
        printf("Read %ld bytes from the file: %s\n", bytes_read, buffer);
    }

    close(fd);
}