#include <stdio.h>
#include <string.h>

struct employee {
    char name[128];
    char id[128];
    char level[128];
    int found;
};

struct employee list[1000];
int count = 0;

void print_table(FILE *file) {
    char text[1000];
    rewind(file);

    printf("_____________________________________\n");
    printf("|   Сострудник    |  ID   | Уровень |\n");
    printf("|_________________|_______|_________|\n");
    while(fgets(text, sizeof(text), file) && count < 100) {
        text[strcspn(text, "\r\n")] = 0;
        char *name = strtok(text, ";");
        char *id = strtok(NULL, ";");
        char *level = strtok(NULL, ";");
        if(name && id && level) {
            strncpy(list[count].name, name, 127);
            strncpy(list[count].id, id, 127);
            strncpy(list[count].level, level, 127);
            printf("|%-16s | %-5s | %-5s |\n", name, id, level);
            count++;
        }
    }
    printf("|_________________|_______|_________|\n");
}

void id_search(char *file_n, char *ID) {
    FILE *file = fopen(file_n, "rb");
    if (file == NULL) {
        printf("Ошибка открытия бинарного файла для поиска\n");
        return;
    }
    struct employee new;
    new.found = 0;
    char text[128];
    rewind(file);
    while(fread(&new, sizeof(struct employee), 1, file)==1) {
        if (strcmp(new.id, ID) == 0) {
            printf("\nСотрудник найден!\n");
            printf("Имя:  %s\n", new.name);
            printf("ID:  %s\n", new.id);
            printf("Уровень: %s\n", new.level);
            new.found = 1;
            break;
        }
    }
    if (new.found == 0) {
        printf("Сотрудник с ID %s не найден.\n", ID); 
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Too few arguments: %s <file.csv> <db.rle>\n", argv[0]);
        return 1;
    }

    FILE *my_file = fopen(argv[1], "r");
    if (my_file == NULL) {
        printf("Не удалось открыть файл для чтения\n");
        return 1;
    }

    print_table(my_file);

    FILE *file = fopen(argv[2], "wb");
    if (file == NULL) {
        printf("Не удалось открыть файл для записи\n");
        return 1;
    } else {
        fwrite(list, sizeof(struct employee), count, file);
        fclose(file);
    }

    printf("Введите ID сотрудника:\n");
    char search_id[6];
    scanf("%5s", search_id);
    
    id_search(argv[2], search_id);
    fclose(my_file);
    
}