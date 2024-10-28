#include <stdio.h>

int main() {
    unsigned int m, i, j;
    scanf("%u %u %u", &m, &i, &j);

    unsigned int bit_i = (m >> i) & 1;
    unsigned int bit_j = (m >> j) & 1;

    if (bit_i != bit_j) {
        m ^= (1 << i);
        m ^= (1 << j);
    }

    printf("Десятковий формат: %u\n", m);
    printf("Шістнадцятковий формат: %X\n", m);

    return 0;
}
