#include "lb10.h"
#include "lb_10_func.c"

int main(void) {
    struct triangle t = fill_struct(1, 2, 3);

    struct triangle y = fill_struct(4, 8, 10);

    struct triangle u = fill_struct(6, 7, 8);

    double area = find_area(y);

    printf("%d %d %d\n", y.a, y.b, y.c);
    printf("%.2f\n", area);
}