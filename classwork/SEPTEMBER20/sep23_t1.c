#include <stdio.h>

int main() {
    int arr[5] = {12, 7, 9, 3, 5};
    double num;
    int count = 0;

    printf("Введіть дійсне число: ");
    scanf("%lf", &num);


    for (int i = 0; i < 5; ++i) {
        if (arr[i] < num) {
            ++count;
        }
    }

    printf("Кількість чисел менших за %.lf: %d\n", num, count);

    return 0;
}
