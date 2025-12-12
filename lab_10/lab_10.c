#include <stdio.h>
#include <math.h>

struct triangle fill_struct_3(int a, int b, int c);
double find_area(struct triangle x);

struct triangle {
    int a;
    int b;
    int c;
};

struct triangle fill_struct_3(int a, int b, int c) {
    struct triangle new;
    new.a = a;
    new.b = b;
    new.c = c;
    return new;
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
                printf("Наибольшая площадь у треугольника u\n");
            }
        }
    }
    return max_area;
}


int main(void) {
    struct triangle t = fill_struct_3(1, 2, 3);

    struct triangle y = fill_struct_3(4, 8, 10);

    struct triangle u = fill_struct_3(6, 7, 8);

    double area1 = calculate_area(t);
    double area2 = calculate_area(y);
    double area3 = calculate_area(y);

    double max_area = find_area(area1, area2, area3);

    printf("Треугольник t: %d %d %d\n", t.a, t.b, t.c);
    printf("Треугольник y:%d %d %d\n", y.a, y.b, y.c);
    printf("Треугольник u:%d %d %d\n", u.a, u.b, u.c);

    printf("Площадь треугольника t: %.2f\n", area1);
    printf("Площадь треугольника y: %.2f\n", area2);
    printf("Площадь треугольника u:%.2f\n", area3);
}
