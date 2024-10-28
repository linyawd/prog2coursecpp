#include <stdio.h>

int main() {
    int arr[50], num, size = 0, even_count = 0, odd_count = 0;


    printf("Введіть числа (0 для завершення):\n");
    while (size < 50) {
        scanf("%d", &num);
        if (num == 0) {
            break;
        }
        arr[size++] = num;
    }


    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }


    printf("Парних: %d, Непарних: %d\n", even_count, odd_count);

    return 0;
}
