#include "book.h"

const char *arr_names[N] = {"Грозовой перевал  ", "Война и мир       ", "Властелин колец   "};
const char *arr_authors[N] ={"Дуглас Аддамс    ", "Ф. М. Достоевский", "Уильям Шекспир   "};

void bubble_sort(struct book arr[]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (arr[j].year > arr[j + 1].year) { 
                struct book tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

struct book fill_struct() {
    struct book new;
    int year;

    int name_index = rand() % N;
    int author_index = rand() % N;

    strcpy(new.name, arr_names[name_index]);
    strcpy(new.author, arr_authors[author_index]);
    new.pages = 100 + rand() % 199;
    new.year = 1900 + rand() % 126;
    return new;  
}

void print_struct(struct book arr[]) {
    for (int i = 0; i < 40; i++) {
        printf(" ");
    }
    printf("{List of books}");
    for (int i = 0; i < 40; i++) {
        printf(" ");
    }
    printf("\n");

    for (int i = 0; i < N; i++) {
        printf("{--------|--------------------------|---------------------------|------------|-----------}\n");
        printf("|Book[%d] | Name: %s | Author: %s | Pages: %d | Year: %d|\n", i + 1, arr[i].name, 
            arr[i].author, arr[i].pages, arr[i].year);
    }
    printf("{--------|--------------------------|---------------------------|------------|-----------}\n");
}