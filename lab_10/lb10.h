#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle {
    int a;
    int b;
    int c;
};

void fill_struct(struct triangle *ptr);
double calculate_area(struct triangle x);
double find_area(double area1, double area2, double area3);