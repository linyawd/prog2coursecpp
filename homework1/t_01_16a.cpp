#include <stdio.h>
#include <math.h>

int main13() {
    const double e = 2.71828;

    printf("x----|  1  |  2  |  3  |  4  |  5  |\n");
    printf("-----|-----|-----|-----|-----|-----|\n");


    printf("F1(x)|");
    for (int x = 1; x < 6; x++) {
        double y1 = pow(e, -(x * x)); // e^(-x^2)
        printf("%5.2f|", y1);
    }

    return 0;
}

// x++  === x = x + 1 === x += 1
