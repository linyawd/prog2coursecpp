#include <stdio.h>
#include <math.h>

int main2() {
    double x;
    printf("Enter x: ");
    scanf("%lf",&x);
    if (x == 0) {
        printf("infinity\n");
    } else {
        double y;
        y = log10(x);
        printf("y=%.3lf\n",y);
    }

    return 0;
}

