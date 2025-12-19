#include "lb10.h"

int main(void) {
    struct triangle **ptr = malloc(3 * sizeof(struct triangle*));
    if (ptr == NULL){
        return -1;
    }
    for (int i = 0; i < 3; i++) {
        ptr[i] = malloc(sizeof(struct triangle));
        if (ptr == NULL){
            return -1;
        }
    }

    for (int i = 0; i < 3; i++) {
        fill_struct(ptr[i]);
        printf("Треугольник : %d %d %d\n", ptr[i]->a, ptr[i]->b, ptr[i]->c);
    }
    
    double area[3];
    for (int i = 0; i < 3; i++) {
        area[i] = calculate_area(*ptr[i]);
        printf("Площадь треугольника : %.2f\n", area[i]);
    }

    double max_area = find_area(area, 3);

    printf("Наибольшая площадь: %.2f\n", max_area);

    for (int i = 0; i < 2; i++) {
        free(ptr[i]);
    }
    free(ptr);
}