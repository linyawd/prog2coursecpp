#include <stdio.h>
#include <math.h>

int main() {
    double A, B, C, r, S;

    printf("Введіть величини кутів трикутника (в градусах): ");
    scanf("%lf %lf %lf", &A, &B, &C);

    printf("Введіть радіус вписаного кола: ");
    scanf("%lf", &r);

    A = A * M_PI / 180.0;
    B = B * M_PI / 180.0;
    C = C * M_PI / 180.0;

    S = r * (tan(A / 2) + tan(B / 2) + tan(C / 2));

    printf("Площа трикутника: %.4lf\n", S);

    return 0;
}
