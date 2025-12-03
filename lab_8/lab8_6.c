#include <stdio.h>
#include <stdlib.h>
#define N 3
void print_array(int **arr);
void multiply(int **arr, int size, int a);
int sumMatrix(int **arr, int size);

void print_array(int **arr) {  
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
}

int *find_min(int **arr, int size) {
    int *min = &arr[0][0];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i][j] < *min) {
                min = &arr[i][j];
            }
        }
    }
    return min;
}

void multiply(int **arr, int size, int a) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr[i][j] = arr[i][j] * a;
        }
    }
}

int sumMatrix(int **arr, int size) {
    int total_sum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            total_sum = total_sum + arr[i][j];
        }
    }
    return total_sum;
}

int main(void) {
    int **arr = malloc(N * sizeof(*arr));
    int summa_m;
    if (arr == NULL){
        return -1;
    }
    for (int i = 0; i < N; i++) {
        arr[i] = malloc(N * sizeof(**arr));
        if (arr[i] != NULL){
        printf("Введите элементы матрицы %dx%d:\n", N, N);
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
            }
        }
    }
    int *min = find_min(arr, N);
    int min_r = 0;
    int min_c = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == *min) {
                *min = arr[i][j];
                min_r = i;
                min_c = j;
            }
        }
    }
    printf("Исходный массив:\n");
    print_array(arr);
    printf("Массив с минимальным элементом в верхнем правом углу:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int current_row = (min_r + i) % N;
            int current_col = (min_c + j + 1) % N;
            printf("%4d", arr[current_row][current_col]);
        }
        printf("\n");
    }
    int a;
    printf("Введите число:");
    scanf("%d", &a);
    multiply(arr, N, a);
    summa_m = sumMatrix(arr, N);
    printf("Сумма элементов массива:%d\n", summa_m);
    for (int i = 0; i < N; i++) {
        free(arr[i]);
        arr[i] = NULL;
    }
    free(arr);
    arr = NULL;
}
