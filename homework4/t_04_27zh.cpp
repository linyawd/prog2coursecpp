#include <stdio.h>
#include <math.h>

int main() {
    int k, m;
    double epsilon, term, pi = 0.0;
    double previous_pi;

    printf("точність epsilon: ");
    scanf("%lf", &epsilon);

    for (k = 1; ; k++) {
        double inner_sum = 0.0;
        for (m = 1; ; m++) {
            term = 1.0 / pow(4 * m - 2, k);
            inner_sum += term;

            if (term < epsilon) {
                break;
            }
        }

        previous_pi = pi;
        pi += 8 * inner_sum;

        if (fabs(pi - previous_pi) < epsilon) {
            break;
        }
    }

    printf("Значення pi: %.15f\n", pi);

    return 0;
}
