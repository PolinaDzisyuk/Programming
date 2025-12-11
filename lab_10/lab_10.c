#include <stdio.h>
#include <math.h>

struct triangle fill_struct(int a, int b, int c);
double find_area(struct triangle x);

struct triangle {
    int a;
    int b;
    int c;
};

struct triangle fill_struct(int a, int b, int c) {
    struct triangle new;
    new.a = a;
    new.b = b;
    new.c = c;
    return new;
}

double find_area(struct triangle x) {
    double p = (x.a + x.b + x.c) / 2.0;
    double s = sqrt(p * (p - x.a) * (p - x.b) * (p - x.c));
    return s;
}

int main(void) {
    struct triangle t = fill_struct(1, 2, 3);

    struct triangle y = fill_struct(4, 8, 10);

    struct triangle u = fill_struct(6, 7, 8);

    double area = find_area(y);

    printf("%d %d %d\n", y.a, y.b, y.c);
    printf("%.2f\n", area);
}
