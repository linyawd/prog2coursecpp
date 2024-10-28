#include <stdio.h>

int main() {
    int n;
    double S_n = 0.0;
    double a_k_1 = 1, a_k_2 = 0, b_k_1 = 1, b_k;

    printf("Введіть значення n: ");
    scanf("%d", &n);

    for (int k = 1; k <= n; k++) {
        double a_k, term;

        a_k = a_k_1 - a_k_2 + b_k_1;
        b_k = b_k_1 + a_k_1;

        term = a_k / (1 + b_k);
        S_n += term;

        a_k_2 = a_k_1;
        a_k_1 = a_k;
        b_k_1 = b_k;
    }

    printf("S_n = %.10f\n", S_n);

    return 0;
}
