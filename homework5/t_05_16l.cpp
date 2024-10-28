#include <stdio.h>
#include <math.h>

int main() {
    double x, epsilon, term, sum = 1.0;
    int k = 1;

    printf("Введіть значення x: ");
    scanf("%lf", &x);

    printf("Введіть значення epsilon: ");
    scanf("%lf", &epsilon);

    term = 1.0 / 2.0;
    while (fabs(term) >= epsilon) {
        sum -= term;
        k++;
        term = (1.0 * k * (k + 1)) / (2.0 * 4 * (2 * k + 2)) * pow(x, 2 * k);
    }

    printf("Сума = %.10f\n", sum);

    return 0;
}
