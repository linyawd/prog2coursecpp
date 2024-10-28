#include <stdio.h>

int main() {
    int k;
    double x, result = 1, term = 1;

    printf("Введіть значення x: ");
    scanf("%lf", &x);

    printf("Введіть кількість елементів k: ");
    scanf("%d", &k);

    for (int i = 1; i <= k; i++) {
        term *= x / i;
        result = term / i;
        printf("x_%d = %.10f\n", i, result);
    }

    return 0;
}
