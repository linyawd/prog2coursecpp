#include <stdio.h>

int main() {
    int n;
    double S_n = 0.0;
    double a_k_1 = 0, a_k_2 = 1;

    printf("Введіть значення n: ");
    scanf("%d", &n);

    for (int k = 1; k <= n; k++) {
        double a_k;

        if (k == 1) {
            a_k = a_k_1;
        } else if (k == 2) {
            a_k = a_k_2;
        } else {
            a_k = a_k_1 + k * a_k_2;
            a_k_1 = a_k_2;
            a_k_2 = a_k;
        }

        S_n += (1 << k) * a_k;
    }

    printf("S_n = %.10f\n", S_n);

    return 0;
}
