#include <stdio.h>
#include <math.h>

double arctg(double x) {
    return atan(x);
}

double arctg_derivative(double x) {
    return 1 / (1 + x * x);
}

int main() {
    double x;

    printf("Введіть значення x: ");
    scanf("%lf", &x);

    printf("arctg(%.4lf) = %.4lf\n", x, arctg(x));
    printf("arctg'(%.4lf) = %.4lf\n", x, arctg_derivative(x));

    return 0;
}
