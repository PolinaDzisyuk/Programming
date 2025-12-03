#include <stdio.h>
int main(void) {
    int N;
    printf("Введите размер системы (2 или 3):\n");
    scanf("%d", &N);
    if (N == 2) {
        float a, b, c, d, e, f;
        printf("Введите коэффициенты системы: ax + by = e\n");
        printf("cx + dy = f\n");
        printf("a b e: ");
        scanf("%f %f %f", &a, &b, &e);
        printf("c d f: ");
        scanf("%f %f %f", &c, &d, &f);
        
        float det = a*d - c*b;
        if (det == 0) {
            printf("Нет единственного решения.\n");
        }
        
        float det_x = e*d - f*b;
        float det_y = a*f - c*e;
        
        float x = det_x / det;
        float y = det_y / det;
        
        printf("Ответ: x = %.1f, y = %.1f\n", x, y);
        
    } else if (N == 3) {
        int a1, a2, a3, b1, b2, b3, c1, c2, c3, d1, d2, d3;
        printf("Введите коэффициенты системы:\n");
        printf("a1 a2 a3 d1: ");
        scanf("%d %d %d %d", &a1, &a2, &a3, &d1);
        printf("b1 b2 b3 d2: ");
        scanf("%d %d %d %d", &b1, &b2, &b3, &d2);
        printf("c1 c2 c3 d3: ");
        scanf("%d %d %d %d", &c1, &c2, &c3, &d3);
        int det = a1*(b2*c3 - b3*c2) - a2*(b1*c3 - b3*c1) + a3*(b1*c2 - b2*c1);
        
        if (det == 0) {
            printf("Нет единственного решения!\n");
            return 0;
        }
        int det_x = d1*(b2*c3 - b3*c2) - a2*(d2*c3 - b3*d3) + a3*(d2*c2 - b2*d3);
        int det_y = a1*(d2*c3 - b3*d3) - d1*(b1*c3 - b3*c1) + a3*(b1*d3 - d2*c1);
        int det_z = a1*(b2*d3 - d2*c2) - a2*(b1*d3 - d2*c1) + d1*(b1*c2 - b2*c1);
        
        float x = det_x / det;
        float y = det_y / det;
        float z = det_z / det;
        
        printf("x = %.1f, y = %.1f, z = %.1f\n", x, y, z);
        
    } else {
        printf("Только 2 или 3!\n");
    }
    return 0;
}