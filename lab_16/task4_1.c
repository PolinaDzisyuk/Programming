#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
pthread_mutex_t mutex_parent;
pthread_mutex_t mutex_child[4];

const char *strings[4][4] = {
    {"кофе", "чай", "какао", "молоко"},
    {"дождь", "солнце", "облака", "туман"},
    {"красный", "зелёный", "синий", "жёлтый"},
    {"день", "ночь", "утро", "вечер"}
};

void cleanup(void *arg) {
    printf("Очистка: %s\n", (char *)arg);
    pthread_mutex_unlock(&mutex_parent);
}

void *routine(void *arg) {
    int id = *(int *)arg;
    pthread_cleanup_push(cleanup, "Дочерний поток завершил работу");
    pthread_mutex_lock(&mutex_child[id]);
    printf("Дочерний поток:%s\n", strings[id][0]);
    sleep(1);
    pthread_mutex_unlock(&mutex_parent);
    pthread_cleanup_pop(1);
    return NULL;
}

int main(void) {
    int n = 4;
    int id[n] = {};
    pthread_t tid[n];
    pthread_mutex_init(&mutex_parent, NULL);

    for(int i = 0; i < n; i++) {
        id[i] = i;
    }
    for(int i = 0; i < n; i++){
        pthread_mutex_init(&mutex_child[i], NULL);
    }
    for (int i = 0; i < 4; i++) {
        pthread_create(&tid[i], NULL, routine, &id[i]);
        pthread_mutex_lock(&mutex_child[i]);
        pthread_mutex_lock(&mutex_parent);
        printf("Родительский поток:%s\n", strings[1][i]);
        // sleep(1);
        pthread_mutex_unlock(&mutex_child[i]);
    } 
    sleep(2);
    for(int i = 0; i < n; i++){
        pthread_cancel(tid[i]);
        pthread_join(tid[i], NULL);
    }
    printf("Потоки завершили работу\n");

    return 0;
}