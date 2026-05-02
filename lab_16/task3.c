#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
// const char *strings[4][4] = {
//     {"кофе", "чай", "какао", "молоко"},
//     {"дождь", "солнце", "облака", "туман"},
//     {"красный", "зелёный", "синий", "жёлтый"},
//     {"день", "ночь", "утро", "вечер"}
// };

// void cleanup(void *arg) {
//     printf("Очистка: %s\n", (char *)arg);
// }

// void *routine(void *arg) {
//     pthread_cleanup_push(cleanup, "Дочерний поток завершил работу");
//     char **str = (char **)arg;
//     for (int i = 0; i < 4; i++) {
//         printf("Дочерний поток:%s\n", str[i]);
//         sleep(1);
//     }
//     pthread_cleanup_pop(0);
//     return NULL;
// }

void *sleepsort(void *arg) {
    int sec = (int*)arg;
    sleep(sec);
    printf("%d\n", sec);
    fflush(stdout);
    return NULL;
}

int main(void) {
    int n = 26;
    pthread_t tid[n];
    int arr[n] = {};
    for (int i = 0; i < n; i++) {
            arr[i] = n - i;   
    }

    for(int i = 0; i < n; i++){
        pthread_create(&tid[i], NULL, sleepsort, (void*)arr[i]);
    }
    // sleep(2);
    // for(int i = 0; i < n; i++){        
    //     pthread_cancel(tid[i]);
    // }
    
    
    for(int i = 0; i < n; i++){
        pthread_join(tid[i], NULL);
    }
    

    // for (int i = 1; i <= 5; i++) {
    //     printf("Родительский поток:%d\n", i);
    //     sleep(1);
    // }
    
    printf("Потоки завершили работу\n");

    return 0;
}