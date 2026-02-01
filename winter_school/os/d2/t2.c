#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h> 
#include <stdio.h> 
#include <sys/stat.h> 
#define FIFO "chanel"

int main () {
    int fd, n;

    if ((fd = open(FIFO, O_WRONLY)) < 0) {
        printf("-\n");
        exit(1);
    }
    if (write(fd, "Здравствуй, Мир!\n\0", 36) != 36) {
        printf("error\n"); exit(1);
    } else {
        close(fd);
        printf("Привет\n"); exit(0);
    }
}

