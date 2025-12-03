#include <stdio.h> 
int main(){
    unsigned int a;
    printf("Введите число:");
    scanf("%u", &a);
    if (a > 0){
        int first = 0;
        while (((a >> first) & 1) == 0){
            first++;
        }
        int last = 31;
        while (((a >> last) & 1) == 0){
            last--;
        }
        printf("Первый справа единичный бит: %d\n", first);
        printf("Последний справа единичный бит: %d\n", last);

        return 0;
    }
    else{
        printf("Введите число больше 0\n");
    }
}