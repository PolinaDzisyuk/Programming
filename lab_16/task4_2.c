#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct {
    int start;
    int end;
    int size;
    int **matrix_A, **matrix_B, **matrix_C;
} th_data;

void print_array(int **matrix, int size) {  
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void matrix_multiply(int **matrix_A, int **matrix_B, int **matrix_C, int size, int start, int end) {
    printf("Размер %d\n", size);
    printf("Старт %d\n", start);
    printf("Конец %d\n", end);
    for(int i = start; i < end; i++) {
        for(int j = 0; j < size; j++) {
            matrix_C[i][j] = 0;
            for(int k = 0; k < size; k++)
                matrix_C[i][j] += matrix_A[i][k] * matrix_B[k][j];
        }
    }
}

void *routine(void *arg) {
    th_data *data = (th_data *)arg;
    matrix_multiply(data->matrix_A, data->matrix_B, data->matrix_C, data->size, data->start, data->end);
    return NULL;
}

int main(int argc, char *argv[]) {
    struct timeval start, end;
    long sec, m_sec;
    double total_time;

    if (argc < 3) {
        printf("Too few arguments:: %s <matrix_size> <threads_count>", argv[0]);
        return -1;
    }
    int size = atoi(argv[1]);
    int threads_count = atoi(argv[2]);
    pthread_t tid[threads_count];
    th_data new_data[threads_count];
    int rows_per_thred = size / threads_count;
    int **matrix_A = malloc(size * sizeof(*matrix_A));
    int **matrix_B = malloc(size* sizeof(*matrix_B));
    int **matrix_C = malloc(size* sizeof(*matrix_C));
    if (matrix_A == NULL || matrix_B == NULL){
        return -1;
    }

    for (int i = 0; i < size; i++) {
        matrix_A[i] = malloc(size * sizeof(int));
        matrix_B[i] = malloc(size * sizeof(int));
        matrix_C[i] = malloc(size * sizeof(int));
        if (matrix_A[i] != NULL){
        for (int j = 0; j < size; j++) {
            matrix_A[i][j] = 1;
            matrix_B[i][j] = 1;
            matrix_C[i][j] = 0;
            }
        }
    }

    gettimeofday(&start, NULL);
    for (int i = 0; i < threads_count; i++) {
        new_data[i].start = i * rows_per_thred;
        new_data[i].end = (i + 1) * rows_per_thred;
        new_data[i].size = size;
        new_data[i].matrix_A = matrix_A;
        new_data[i].matrix_B = matrix_B;
        new_data[i].matrix_C = matrix_C;
        pthread_create(&tid[i], NULL, routine, &new_data[i]);
    }

    for(int i = 0; i < threads_count; i++){
        pthread_join(tid[i], NULL);
    }
    gettimeofday(&end, NULL);

    sec = end.tv_sec - start.tv_sec;
    m_sec = end.tv_usec - start.tv_usec;
    if (m_sec < 0) {
        m_sec += 1000000;
        sec -= 1;
    }
    total_time = sec + m_sec / 1000000.0;

    if(size <= 5){
        print_array(matrix_A, size);
        printf("\n");
        print_array(matrix_B, size);
        printf("\n");
        print_array(matrix_C, size);
    }
    printf("%.6f секунд\n", total_time);

    printf("Потоки завершили работу\n");
}