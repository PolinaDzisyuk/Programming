#include "book.h"

int main() {
    struct timeval start, end;
    long sec, m_sec;
    double total_time;
    struct book arr[N];
    struct book *arr1 = malloc(A * sizeof(struct book));
    struct book *arr2 = malloc(B * sizeof(struct book));
    struct book *arr3 = malloc(C * sizeof(struct book));
    
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        arr[i] = fill_struct();
    }

    print_struct(arr);

    for (int i = 0; i < A; i++) {
        arr1[i] = fill_struct();
    }

    for (int i = 0; i < B; i++) {
        arr2[i] = fill_struct();
    }

    for (int i = 0; i < C; i++) {
        arr3[i] = fill_struct();
    }

    gettimeofday(&start, NULL);
    bubble_sort(arr1);
    gettimeofday(&end, NULL);

    sec = end.tv_sec - start.tv_sec;
    m_sec = end.tv_usec - start.tv_usec;
    if (m_sec < 0) {
        m_sec += 1000000;
        sec -= 1;
    }
    total_time = sec + m_sec / 1000000.0;
    printf("Time N[100]:%.6f секунд\n", total_time);
    printf("Размер данных N[100]: %d элементов (%.2f МБ)\n", 
        A, (A * sizeof(struct book)) / (1024.0 * 1024.0));
    printf("{--------------------------------------------------------}\n");

    gettimeofday(&start, NULL);
    bubble_sort(arr2);
    gettimeofday(&end, NULL);

    sec = end.tv_sec - start.tv_sec;
    m_sec = end.tv_usec - start.tv_usec;
    if (m_sec < 0) {
        m_sec += 1000000;
        sec -= 1;
    }
    total_time = sec + m_sec / 1000000.0;
    printf("Time N[10000]:%.6f секунд\n", total_time);
    printf("Размер данных N[10000]: %d элементов (%.2f МБ)\n", 
        B, (B * sizeof(struct book)) / (1024.0 * 1024.0));
    printf("{--------------------------------------------------------}\n");

    gettimeofday(&start, NULL);
    bubble_sort(arr3);
    gettimeofday(&end, NULL);

    sec = end.tv_sec - start.tv_sec;
    m_sec = end.tv_usec - start.tv_usec;
    if (m_sec < 0) {
        m_sec += 1000000;
        sec -= 1;
    }
    total_time = sec + m_sec / 1000000.0;
    printf("Time N[100000]:%.6f секунд\n", total_time);
    printf("Размер данных N[100000]: %d элементов %.2f МБ)\n", 
        C, (C * sizeof(struct book)) / (1024.0 * 1024.0));
    printf("{--------------------------------------------------------}\n");

    free(arr1);
    free(arr2);
    free(arr3);
}