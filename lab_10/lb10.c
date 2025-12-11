#include "lb10.h"
#include "lb_10_func.c"

int main(void) {
    struct triangle *ptr1 = malloc(sizeof(struct triangle));
    if (ptr1 == NULL){
        return -1;
    }
    fill_struct(ptr1);

    struct triangle *ptr2 = malloc(sizeof(struct triangle));
    if (ptr1 == NULL){
        return -1;
    }
    fill_struct(ptr2);

    struct triangle *ptr3 = malloc(sizeof(struct triangle));
    if (ptr1 == NULL){
        return -1;
    }
    fill_struct(ptr3);
    
    double area_1 = calculate_area(*ptr1);
    double area_2 = calculate_area(*ptr2);
    double area_3 = calculate_area(*ptr3);

    double max_area = find_area(area_1, area_2, area_3);
    
    printf("Треугольник t: %d %d %d\n", ptr1->a, ptr1->b, ptr1->c);
    printf("Треугольник y: %d %d %d\n", ptr2->a, ptr2->b, ptr2->c);
    printf("Треугольник u: %d %d %d\n", ptr3->a, ptr3->b, ptr3->c);

    printf("Площадь треугольника t: %.2f\n", area_1);
    printf("Площадь треугольника y: %.2f\n", area_2);
    printf("Площадь треугольника u: %.2f\n", area_3);

    printf("Наибольшая площадь: %.2f\n", max_area);

    free(ptr1);
    free(ptr2);
    free(ptr3);
}