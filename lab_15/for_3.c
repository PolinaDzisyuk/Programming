#include <stdio.h>
#include <string.h>

void print_table(FILE *file) {
    char text[128];
    printf("____________________________________\n");
    printf("   Сострудник    |  ID   | Уровень |\n");
    printf("_________________|_______|_________|\n");
    while(fgets(text, sizeof(text), file)) {
        char *name = strtok(text, ";");
        char *id = strtok(NULL, ";");
        char *level = strtok(NULL, ";");

        if(name && id && level) {
            printf("%-16s | %-5s | %-5s\n", name, id, level);
        }
    }
    printf("_________________|_______|________|\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Too few arguments: %s <file.csv>\n", argv[0]);
        return 1;
    }

    FILE *my_file = fopen(argv[1], "r");
    if (my_file == NULL) {
        printf("Не удалось открыть файл для чтения\n");
        return 1;
    }
    print_table(my_file);

    fclose(my_file);   
}