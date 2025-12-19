#include "lb10.h"

struct triangle fill_struct_3(int a, int b, int c) {
    struct triangle new;
    new.a = a;
    new.b = b;
    new.c = c;
    return new;
}

void fill_struct(struct triangle *ptr) {
    int a;
    printf("Введите стороны треугольника:\n");
    scanf("%d", &a);
    int b;
    scanf("%d", &b);
    int c;
    scanf("%d", &c);
    ptr ->a = a;
    ptr ->b = b;
    ptr ->c = c;
}

double calculate_area(struct triangle x) {
    double p = (x.a + x.b + x.c) / 2.0;
    double s = sqrt(p * (p - x.a) * (p - x.b) * (p - x.c));
    return s;
}

double find_area(double area[], int size){
    double max_area = area[0];
    for (int i = 0; i < 3; i++){
        if (area[i] > max_area) {
            max_area = area[i];
        }
    }
    return max_area;
}