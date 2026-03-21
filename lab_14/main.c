#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct node node_t;
const char *arr_names[] = {"Грозовой перевал", "Война и мир", "Властелин колец", "Унесенные ветром", "The C Programming Language", "О дивный новый мир"};
const char *arr_authors[] ={"Дуглас Аддамс", "Ф. М. Достоевский", "Уильям Шекспир", "Владимир Набоков", "Эрнест Хемингуэй", "Франц Кафка"};

struct book {
    char name[128];
    char author[128];
    int pages;
    int year;
};

struct node {
    struct book new;
    struct node *next;
};

node_t *newNode(struct book new) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->new = new;   
    new_node->next = NULL;

    return new_node;
}

struct book fill_struct(const char *arr_names[], const char *arr_authors[]) {
    struct book new;
    int year;

    int name_index = rand() % 6;
    int author_index = rand() % 6;

    strcpy(new.name, arr_names[name_index]);
    strcpy(new.author, arr_authors[author_index]);
    new.pages = 100 + rand() % 199;
    new.year = 2000 + rand() % 26;
    return new;  
}

node_t* appendBack(node_t* head, struct book new) {
    node_t* new_node = newNode(new);
    if (head == NULL) {
        return new_node;
    }
    node_t* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = new_node;
    return head;
}

void prrint_list(node_t *head) {
    node_t* cur = head;
    while (cur) {
        printf("%s -> ", cur->new.name);
        
        printf("%s -> ", cur->new.author);
        
        printf("%d -> ", cur->new.pages);
        
        printf("%d -> ", cur->new.year);
        printf("\n");
        cur = cur->next;
    }
    printf("NULL\n");
}

void free_list(node_t *head) {
    if (head->next == NULL) {
        free(head);
    }

    node_t *second_last = head;
    while(second_last->next->next != NULL) {
        free(second_last);
    }
    free(head);
}

int main() {
    srand(time(NULL));
    int n;
    char arr[]={};
    node_t *list;
    struct book new;
    node_t* head = NULL;

    printf("Введите количество элементов списка:");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        new = fill_struct(arr_names, arr_authors);
        head = appendBack(head, new);
    }   

    prrint_list(head);
}