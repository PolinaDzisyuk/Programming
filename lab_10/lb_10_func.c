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

double find_area(double area1, double area2, double area3){
    double max_area = 0.0;
    if (area1 > max_area){
        max_area = area1;
        if (area2 > max_area){
            max_area = area2;
            if (area3 > max_area){
                max_area = area3;
            }
        }
    }
    if (max_area == area1){
        printf("Наибольшая площадь у треугольника t\n");
        if (max_area == area2){
            printf("Наибольшая площадь у треугольника y\n");
            if (max_area == area3){
                printf("Наибольшая площадь у треугольника u\nS");
            }
        }
    }
    return max_area;
}