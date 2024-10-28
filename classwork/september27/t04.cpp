#include <stdio.h>

#define MAX 25


double determinant(double matrix[MAX][MAX], int size) {
    double det = 0;
    double temp[MAX][MAX];
    int sign = 1;


    if (size == 1) {
        return matrix[0][0];
    }


    if (size == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }


    for (int k = 0; k < size; k++) {

        int subi = 0;
        for (int i = 1; i < size; i++) {
            int subj = 0;
            for (int j = 0; j < size; j++) {
                if (j == k)
                    continue;
                temp[subi][subj] = matrix[i][j];
                subj++;
            }
            subi++;
        }


        det += sign * matrix[0][k] * determinant(temp, size - 1);
        sign = -sign;
    }

    return det;
}

int main() {
    double matrix[MAX][MAX];
    int size;


    printf("Введіть розмір квадратної матриці: ");
    scanf("%d", &size);


    printf("Введіть елементи матриці:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }


    double det = determinant(matrix, size);


    printf("Детермінант матриці: %.2lf\n", det);

    return 0;
}
