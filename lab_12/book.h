#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#define N 3
#define A 100
#define B 10000
#define C 100000

struct book {
    char name[128];
    char author[128];
    int pages;
    int year;
};

struct film {
    char name[128];
    char author[128];
    int hours;
    int year;
};


struct book fill_struct();
void bubble_sort(struct book arr[]);
void print_struct(struct book arr[]);
void print_all(struct book arr[], struct film arr1[]);