#include <stdio.h>
#include <math.h>

void print_table_exp() {
    printf("x----| 1  | 2  | 3  | 4  | 5  |\n");
    printf("-----|----|----|----|----|----|\n");
    printf("F(x) |");
    for (int x = 1; x <= 5; x++) {
        double y = exp(-x * x);
        printf(" %.2f |", y);
    }
    printf("\n");
}

void print_table_sqrt() {
    printf("x----| 1  | 2  | 3  | 4  | 5  |\n");
    printf("-----|----|----|----|----|----|\n");
    printf("F(x) |");
    for (int x = 1; x <= 5; x++) {
        double y = sqrt(x);
        printf(" %.2f |", y);
    }
    printf("\n");
}

int main() {

    printf("Таблиця для F(x) = e^(-x^2):\n");
    print_table_exp();


    printf("\nТаблиця для F(x) = sqrt(x):\n");
    print_table_sqrt();

    return 0;
}
