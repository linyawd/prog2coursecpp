#include <stdio.h>

int main() {

    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int N, M;


    printf("Введіть число N: ");
    scanf("%d", &N);

    printf("Введіть число M: ");
    scanf("%d", &M);


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == M) {
                matrix[i][j] = N;
            }
        }
    }


    printf("Оновлена матриця:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}