#include <stdio.h>
#include <math.h>

int main() {
    double number, result;

    printf("Введіть число від 0 до 10000: ");
    scanf("%lf", &number);

    result = pow(number, 8);

    printf("Результат: %.20lf\n", result);

    return 0;
}

