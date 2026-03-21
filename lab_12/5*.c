#include "book.h"

const char *arr_names[N] = {"Грозовой перевал  ", "Война и мир       ", "Властелин колец   "};
const char *arr_authors[N] ={"Дуглас Аддамс    ", "Ф. М. Достоевский", "Уильям Шекспир   "};

int compare_book(struct book a, struct book b) {
    return a.year - b.year;
}

int compare_film(struct film a, struct film b) {
    return a.year - b.year;
}

void bubble_sort_b(struct book arr[], int (*compare)(struct book, struct book)) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (compare(arr[j], arr[j + 1]) > 0) { 
                struct book tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void bubble_sort_f(struct film arr[], int (*compare)(struct film, struct film)) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (compare(arr[j], arr[j + 1]) > 0) { 
                struct film tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

struct book fill_book() {
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

struct film fill_film() {
    struct film new;
    int year;

    int name_index = rand() % N;
    int author_index = rand() % N;

    strcpy(new.name, arr_names[name_index]);
    strcpy(new.author, arr_authors[author_index]);
    new.hours = rand() % 4;
    new.year = 1900 + rand() % 126;
    return new;  
}

void print_all(struct book arr[], struct film arr1[]) {
    for (int i = 0; i < 40; i++) {
        printf(" ");
    }
    printf("{List of books and films}");
    for (int i = 0; i < 40; i++) {
        printf(" ");
    }
    printf("\n");

    for (int i = 0; i < N; i++) {
        printf("{--------|--------------------------|---------------------------|------------|-----------}\n");
        printf("|Book[%d] | Name: %s | Author: %s | Pages: %d | Year: %d|\n", i + 1, arr[i].name, 
            arr[i].author, arr[i].pages, arr[i].year);
        printf("{--------|--------------------------|---------------------------|------------|-----------}\n");
        printf("|film[%d] | Name: %s | Author: %s | hours: %d   | Year: %d|\n", i + 1, arr1[i].name, 
                arr1[i].author, arr1[i].hours, arr1[i].year);
        }
    printf("{--------|--------------------------|---------------------------|------------|-----------}\n");
}


int main() {
    struct timeval start, end;
    long sec, m_sec;
    double total_time;
    struct book arr[N];
    struct film arr1[N];
    
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        arr[i] = fill_book();
        arr1[i] = fill_film();
    }

    bubble_sort_b(arr, compare_book);

    bubble_sort_f(arr1, compare_film);
    print_all(arr, arr1);

}