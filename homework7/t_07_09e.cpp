#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    double array[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf", &array[i]);
    }

    double max_abs = fabs(array[0]);
    for (int i = 1; i < n; i++) {
        if (fabs(array[i]) > max_abs) {
            max_abs = fabs(array[i]);
        }
    }

    printf("Максимальне абсолютне значення: %.2f\n", max_abs);

    return 0;
}
