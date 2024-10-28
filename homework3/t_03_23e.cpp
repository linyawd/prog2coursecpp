#include <stdio.h>
#include <math.h>

double softExponential(double a, double x) {
    if (a < 0) {
        return -log(1 - a * (x + a)) / a;
    } else if (a == 0) {
        return x;
    } else {
        return (exp(a * x) - 1) / a + a;
    }
}

double softExponential_derivative(double a, double x) {
    if (a < 0) {
        return 1 / (1 - a * (x + a));
    } else if (a == 0) {
        return 1;
    } else {
        return exp(a * x);
    }
}

int main() {
    double a, x;

    printf("Введіть значення a і x: ");
    scanf("%lf %lf", &a, &x);

    printf("softExponential(%.4lf, %.4lf) = %.4lf\n", a, x, softExponential(a, x));
    printf("softExponential'(%.4lf, %.4lf) = %.4lf\n", a, x, softExponential_derivative(a, x));

    return 0;
}
