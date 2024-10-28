#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void fillArray(double** array, int rows, int cols, int random) {
    if (random) {
        srand(time(NULL));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                array[i][j] = (rand() % 2001 - 1000) / 10.0;
            }
        }
    } else {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                scanf("%lf", &array[i][j]);
            }
        }
    }
}

void printArray(double** array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", array[i][j]);
        }
        printf("\n");
    }
}

int findRowWithMinElement(double** array, int rows, int cols) {
    int minRow = 0;
    double minValue = fabs(array[0][0]);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (fabs(array[i][j]) < minValue) {
                minValue = fabs(array[i][j]);
                minRow = i;
            }
        }
    }
    return minRow;
}

void deleteRow(double** array, int* rows, int cols, int rowToDelete) {
    for (int i = rowToDelete; i < *rows - 1; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = array[i + 1][j];
        }
    }
    *rows -= 1;
}

int main() {
    int N, M, random;
    printf("Введіть кількість рядків і стовпців: ");
    scanf("%d %d", &N, &M);

    double** array = (double**)malloc(N * sizeof(double*));
    for (int i = 0; i < N; i++) {
        array[i] = (double*)malloc(M * sizeof(double));
    }

    printf("Введіть 1 для заповнення випадковими числами або 0 для введення з консолі: ");
    scanf("%d", &random);
    fillArray(array, N, M, random);

    printf("Початкова матриця:\n");
    printArray(array, N, M);

    int minRow = findRowWithMinElement(array, N, M);
    deleteRow(array, &N, M, minRow);

    printf("Матриця після видалення рядка:\n");
    printArray(array, N, M);

    for (int i = 0; i < N; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}
