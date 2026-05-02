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
    int index;
};

struct node {
    struct book new;
    struct node *down;
    struct node *next;
};

struct book fill_struct() {
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
    printf(" |[%d]Book\n |Name: %s \n |Author: %4s ->\n |Pages: %d \n |Year: %d\n", cur_up->new.index, cur_up->new.name, 
    cur_up->new.author, cur_up->new.pages, cur_up->new.year);
    printf(" -------------------\n");
}

node_t *newNode(struct book new, int index) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->new = new;
    new_node->new.index = index;
    new_node->down = NULL;
    new_node->next = NULL;

    return new_node;
}

node_t* append(int n, int k) {
    node_t *new_up = NULL;
    node_t *prev_up = NULL;
    node_t *new_down = NULL;
    node_t *prev_down = NULL;
    int max_len;

    // if(n > k) {
    //     max_len = n;
    // } else {
    //     max_len = k;
    // }
    node_t *up = NULL;
    node_t *down = NULL;
    for(int i = n; i >= 2; i-=2) { 
            up = newNode(fill_struct(), i);
            int index_up = i;
            if(new_up == NULL) {
                new_up = up;
            }
            if (prev_up) prev_up->next = up;
            prev_up = up;
    for(int j = k; j >= 1; j-=1) {
            down = newNode(fill_struct(), i);
            int index_down = j;
            
            if (new_down == NULL) {
                new_down = down;
            }
            if (prev_down) {
                prev_down->next = down; 
            }
            prev_down = down;             
        }
        if (up && down) {
            up->down = down;
        }
    }
        
    return new_up;
}


void print_list(node_t *head) {
    node_t *cur_up = head;
    while (cur_up) {
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
    int k;
    struct book new_up;
    struct book new_down;
    node_t* head = NULL;

    printf("Введите количество элементов верхнего списка:");
    scanf("%d", &n);
    if (n <= 0) {
        return -1;
    }

    printf("Введите количество элементов нижнего списка:");
    scanf("%d", &k);
    if (k <= 0) {
        return -1;
    }
        
    head = append(n, k);

    print_list(head);

    printf("\nНажмите:\n 'd', чтобы двигаться вправо.\n 's', чтобы двигаться вниз.\n");
    node_t *list_ptr = head;
    while(list_ptr) {
        printf("\nТЕКУЩАЯ КНИГА %d: %s\n", list_ptr->new.index, list_ptr->new.name);
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
