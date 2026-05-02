#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void print_table(int fd) {
    char buf[1024];
    char b;
    int cnt = 0;
    ssize_t b_read;
    printf("____________________________________\n");
    printf("   Сострудник    |  ID   | Уровень |\n");
    printf("_________________|_______|_________|\n");
    while(read(fd, &b, 1) > 0) {
        if (b == '\n' || cnt == sizeof(buf) - 1){
            buf[cnt] = '\0';
            char *name = strtok(buf, ";");
            char *id = strtok(NULL, ";");
            char *level = strtok(NULL, ";");

            if(name && id && level) {
                printf("%-16s | %-5s | %-5s |\n", name, id, level);
            }
        cnt = 0;
        } else {
            buf[cnt++] = b;
        }
    }
    if(cnt > 0) {
        buf[cnt] = '\0';
        char *name = strtok(buf, ";");
        char *id = strtok(NULL, ";");
        char *level = strtok(NULL, ";");
        if(name && id && level) {
            printf("%-16s | %-5s | %-5s |\n", name, id, level);
        }
    }
    printf("_________________|_______|_________|\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Too few arguments: %s <file.csv>\n", argv[0]);
        return 1;
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        return 1;
    }
    print_table(fd);
    close(fd);   
    
}