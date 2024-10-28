#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    FILE *file = fopen("/Users/lina/CLionProjects/proghome2/prog2coursecpp/homework11/t_11_07d.cpp", "rb");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    float number, max_abs_value = 0;
    while (fread(&number, sizeof(float), 1, file) == 1) {
        if (fabs(number) > max_abs_value) {
            max_abs_value = fabs(number);
        }
    }

    fclose(file);

    printf("Largest absolute value: %.2f\n", max_abs_value);
    return 0;
}
