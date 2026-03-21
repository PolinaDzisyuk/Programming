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
    int numb;
};

struct node {
    struct book new;
    struct node *down;
    struct node *next;
};

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

void print_struct(node_t *node) {
    node_t *cur_up = node;
    printf(" -------------------\n");
    printf(" | Book\n |Name: %s \n |Author: %4s ->\n |Pages: %d \n |Year: %d\n", cur_up->new.name, 
    cur_up->new.author, cur_up->new.pages, cur_up->new.year);
    printf(" -------------------\n");
}

node_t *newNode(struct book new) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->new = new;
    new_node->down = NULL;
    new_node->next = NULL;

    return new_node;
}

node_t* append(node_t* head) {
    node_t *new_up = newNode(fill_struct(arr_names, arr_authors));
    node_t *new_down = newNode(fill_struct(arr_names, arr_authors));
    new_up->down = new_down;

    if (head == NULL) {
        return new_up;
    }
     
    new_up->next = head;
    if (head->down) {
        new_down->next = head->down;
    }

    return new_up;
}

void print_list(node_t *head) {
    node_t *cur_up = head;
    int cnt = 0;
    while (cur_up) {
        // printf("%s -> ", cur_up->new.name);
        print_struct(cur_up);
        cur_up = cur_up->next;
    }
    printf("NULL\n");

    node_t *cur_down;
    if (head != NULL && head->down != NULL) {
        cur_down = head->down;
    } else {
        cur_down = NULL;
    }
    while (cur_down) {
        // printf("%s -> ", cur_down->new.name);
        print_struct(cur_down);
        cur_down = cur_down->next;
    }
    printf("NULL\n");
}

void free_list(node_t *node) {
    if (node == NULL) {
        return;
    }
    node_t *next_n = node->next;

    if (node->down) {
        free(node->down);
    }
    free(node);
    free_list(next_n);
}

int main() {
    srand(time(NULL));
    int n;
    struct book new_up;
    struct book new_down;
    node_t* head = NULL;

    printf("Введите количество элементов списка:");
    scanf("%d", &n);
    if (n <= 0) {
        return -1;
    }

    for(int i = 0; i < n; i++) {
        head = append(head);
    }

    print_list(head);

    printf("\nНажмите:\n 'd', чтобы двигаться вправо.\n 's', чтобы двигаться вниз.\n");
    node_t *list_ptr = head;
    while(list_ptr) {
        printf("\nТЕКУЩАЯ КНИГА: %s\n", list_ptr->new.name);
        printf("\nАВТОР: %s\n", list_ptr->new.author);
        char key = ' ';
        scanf(" %c", &key);
        printf("Key entered: '%c'\n", key);

        if(key == 'd') {
            if (list_ptr->next) {
                list_ptr = list_ptr->next;
            } else {
                if (list_ptr->down) {
                    printf("Хотите переместиться вниз?: next->NULL\n");
                    char answer;
                    scanf(" %c", &answer);
                    if (answer == 's') {
                        list_ptr = list_ptr->down;
                    }
                } else {
                printf("Перемещение невозможно: next->NULL\n");
                char answer;
                printf("Хотите вернуться в начало списка? y/n\n");
                scanf(" %c", &answer);
                if (answer == 'y') {
                    list_ptr = head;
                } else {
                    break;
                }
                }
            }
        } else if(key == 's') {
            if (list_ptr->down) {
                list_ptr = list_ptr->down;
            } else {
                printf("Перемещение невозможно: down->NULL\n");
                char answer;
                printf("Хотите вернуться в начало списка? y/n\n");
                scanf(" %c", &answer);
                if (answer == 'y') {
                    list_ptr = head;
                } else {
                    break;
                }
            }

        } else {
            printf("Неверный ввод\n");
        }
    }
    
    free_list(head);
}
