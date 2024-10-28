#include <stdio.h>

#define MAX 25


void printMatrix(int matrix[MAX][MAX], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


void transposeMatrix(int matrix[MAX][MAX], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

int main() {
    int matrix[MAX][MAX];
    int size;


    printf("Введіть розмір квадратної матриці: ");
    scanf("%d", &size);


    printf("Введіть елементи матриці:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }


    printf("Оригінальна матриця:\n");
    printMatrix(matrix, size);


    transposeMatrix(matrix, size);


    printf("Транспонована матриця:\n");
    printMatrix(matrix, size);

    return 0;
}
