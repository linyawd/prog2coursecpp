#include <stdio.h>

int sum_of_digits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int N;
    scanf("%d", &N);
    int array[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (sum_of_digits(array[i]) % 7 == 0) {
            count++;
        }
    }

    printf("Кількість чисел, сума цифр яких ділиться на 7: %d\n", count);

    return 0;
}
