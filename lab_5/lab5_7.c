#include <stdio.h>
#define N 6
int findmax(int arr[], int size);
int findmin(int arr[], int size);
int average(int arr[], int size);
int main(void) {
    int array[N] = {1234, 3000, 1000, 1008, 3, -1};
    int maxr = findmax(array, N);
    int minr = findmin(array, N);
    int sr = average(array, N);
    printf("Максимум: %d\n", maxr);
    printf("Минимум: %d\n", minr);
    printf("Среднее (без max и min): %d\n", sr);
}
int findmax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
int findmin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {    
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}
int average(int arr[], int size) {
    int max = findmax(arr, size);
    int min = findmin(arr, size);
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] != max && arr[i] != min) {
        sum += arr[i];
        cnt++;
        }
    }
    if (cnt > 0) {
        return sum / cnt;
    }
    else {
        return 0;
    }
}
