#include <stdio.h> 
#include <stdlib.h> 
 
// Проблема: segmentation fault 
 
void init(int *arr, int n) {  
    for (int i = 0; i < n; ++i) {  
        arr[i] = i;     
    } 
} 
 
int main() { 
    int *arr = malloc(10 * sizeof(int)); 
    int n = 10; 
 
    init(arr, n); 
    for (int i = 0; i < n; ++i) { 
        printf("%d\n", arr[i]); 
    } 
    free(arr); 
    return 0; 
} 