#include <stdio.h>

void rotateBlock(double matrix[][100], int n) {
    int start = 0;
    int end = 2 * n;
    while (start < end) {
        for (int i = start; i < end; i++) {
            double temp = matrix[start][i];
            matrix[start][i] = matrix[2 * n - i][start];
            matrix[2 * n - i][start] = matrix[end][2 * n - i];
            matrix[end][2 * n - i] = matrix[i][end];
            matrix[i][end] = temp;
        }
        start++;
        end--;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int size = 2 * n + 1;
    double matrix[100][100];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    rotateBlock(matrix, n);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

