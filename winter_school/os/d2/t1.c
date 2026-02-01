#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

void process(char *s) {
    int size;
    int size_txt;
    int j;
    char txt[10000];
    size = strlen(s);

    j = 0;
    int st = 0;

    for (int i = 0; i < size - 1; i++) {
        if (s[i] == 'a') {
            st = 1;
        }
        if (st) {
            txt[j++] = s[i];
            if (s[i] == 'k') {
                break;
            }
        }
    }

    txt[j] = '\0';
    strcpy(s, txt);
}

int main() {
    int fd[2];  
    pipe(fd); 
    pid_t pid = fork(); 

    if (pid > 0) {
        close(fd[0]);
        FILE *f = fopen("text.txt", "r");  
        if (!f) { perror("text"); exit(1); }  
        char c;
        while ((c = fgetc(f)) != EOF) {
            write(fd[1], &c, 1);                 
        }
        c = 26;  
        write(fd[1], &c, 1); 
        close(fd[1]);  
        fclose(f); 
    } else {
        close(fd[1]);
        char buf[5000];  
        int len = 0;  
        char c;  
        while (read(fd[0], &c, 1) == 1) {
            if ((unsigned char)c == 26) break;  
            buf[len++] = c; 
        }
        buf[len] = '\0';
        process(buf);
        FILE *out = fopen("out.txt", "w");
        if (out) {
            fputs(buf, out); 
            fclose(out);
        }
        close(fd[0]);
    }
    return 0;  

}