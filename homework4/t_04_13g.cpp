#include <stdio.h>
#include <math.h>

int main() {
    int n;
    double x, result = 0;

    printf("Введіть значення n: ");
    scanf("%d", &n);

    printf("Введіть значення x: ");
    scanf("%lf", &x);

    for (int i = 0; i < n; i++) {
        result += (n - i) * pow(x, n - i - 1);
    }

    printf("Результат: %.10f\n", result);

    return 0;
}
