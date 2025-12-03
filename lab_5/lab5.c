#include <stdio.h>
#include <stdlib.h>
#define N 6
int main(void) {
    double energy = 0.0;
    short int array[N * 2] = {12340, -3000, 1000, 1000, -3, -1, 500, -2500, 0, 3276, -100, 200};
    int maxr = array[0];
    printf("Значения сигнала:\n");
    for(int i = 0; i < N; i++) {
        int re = array[i * 2];
        float im = array[i * 2 + 1];
        printf("s[%d] = %d + j*(%.1f)\n", i, re, im);
    }
    for (int i = 0; i < N; i++) {
        int re = array[i * 2];
        int im = array[i * 2 + 1];
        energy += re * re + im * im;
    }
    printf("Энергия сигнала: %.1f\n", energy);
    for (int i = 0; i < N; i++) {
        int re = array[i * 2];
        if (re > maxr) {
            maxr = re;
        }
    }
    printf("Максимальный элемент реальной части: %d\n", maxr);   
    return 0;
}