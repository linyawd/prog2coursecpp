#include <stdio.h>

int main() {
    int m, n;


    printf("Введіть кількість рядків (менше 25): ");
    scanf("%d", &m);
    printf("Введіть кількість стовпців (менше 25): ");
    scanf("%d", &n);


    if (m > 25 || n > 25 || m <= 0 || n <= 0) {
        printf("Некоректні розміри матриці!\n");
        return 1;
    }


    double matrix[25][25];


    for (int i = 0; i < m; i++) {
        printf("Введіть елементи %d-го рядка (розділені пробілами): ", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }


    printf("Введена матриця:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
