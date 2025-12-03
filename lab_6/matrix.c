#include <stdio.h>
int det(int size, int mat[size][size + 1]);
int cramer(int size, int mat[size][size + 1]);
int main(void) {
    int N;
    printf("Введите размер матрицы N (от 1 до 3):\n");
    scanf("%d", &N);
     if (N < 1 || N > 3) {
        printf("Ошибка. Размер должен быть от 1 до 3\n");
    }
    int matrix[N][N + 1];
    printf("Введите элементы матрицы %dx%d:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N + 1; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\n Матрица %dx%d:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N + 1; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    int determinator = det(N, matrix);
    printf("Определитель матрицы: %f\n", determinator);
}
int det(int size, int mat[size][size + 1]) {
    if (size == 1) {
        return mat[0][0];
    } 
    else if (size == 2) {
            return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    }
    else if (size == 3) {
        return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1])
             - mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0])
             + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
    }
    return 0;
}
int cramer(int size, int mat[size][size + 1]) [
    if (size == 1) {
        return mat[0][0];
    }
    else if (size == 2) {
            int x = mat[0][2] * mat[1][1] - mat[1][2] * mat[0][1];
            int y = mat[0][2] * mat[1][1] - mat[1][2] * mat[0][1];
    }
]
