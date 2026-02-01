#include <stdio.h>
#include <stddef.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <getopt.h> 

extern char ** environ;

int main(int argc, char **argv) {
    int a;
    int b;
    int res;
    pid_t p;
    int c;
    int i;
    char *shell;
    int r;

    if ((shell = getenv("HOME")) != NULL) {
        printf("%s\n", shell);
    }

    printf("Количество аргументов:%d\n", argc);
    printf("argv[0] = %s\n", argv[0]);

    for (i = 1; i < argc; i ++) {
        printf("argv[%d] = %s\n", i, argv[i]); 
    }

    printf ("Запущена программа: %s\n", argv[0]); 
    printf ("Число параметров: %d\n", argc-1);
    
    p = getpid();
    printf("PID:%d\n", p);

    printf("Введите количество аргументов для вывода\n:");
    scanf("%d", &r);

    for (i = 0; i < r; i ++)  {
        if (environ[i] != NULL) {
            printf("environ[%d] : %s\n",i, environ[i]);
        }
 
    }

    printf("Введите число:\n");
    scanf("%d", &a);

    printf("Введите число:\n");
    scanf("%d", &b);
    
    res = a * b;
    printf("Произведение: %d\n", res);


    // printf("argv[1]:%s\n", argv[1]);
    // printf("argv[2]:%s\n", argv[2]);
    // for (int i = 0; i < 10; i++) {
    //     printf("%s\n", envp[i]);
    // }

    while (1) {
    c = getopt (argc, argv, "abc:d:012"); 
    if (c == -1) break; 
    switch (c){ 
    case '0':      printf ("опция  0\n"); 
    break; 
    case '1':      printf ("опция  1\n"); 
    break; 
    case '2':      
    break; 
    printf ("опция  2\n"); 
    case 'a': printf ("опция a\n");                  
    break; 
    case 'b': printf ("опция b\n"); 
    break; 
    case 'c': printf ("опция с  со значением '%s'\n", 
    optarg);                 
    break; 
    case 'd': printf ("опция  d со значением '%s'\n", 
    optarg); 
        break; 
    case '?': break; 
    default: printf ("результат 0%o ??\n", c); 
        } 
    }
    if (optind < argc){ 
        printf ("элементы ARGV, не параметры: "); 
        while (optind < argc)
            printf ("%s ", argv[optind++]); 
            printf ("\n"); 
    } 
    exit (0); 

    printf ("Запуск программы ls\n"); 
    execl ("/bin/ls", "ls", "-l", (char *)0); 
    perror ("Ошибка вызова execl"); 
    return (1);

    return 0;
}
