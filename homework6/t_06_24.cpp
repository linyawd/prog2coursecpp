#include <stdio.h>

int main() {
    unsigned int num;
    scanf("%u", &num);

    int youngest = -1;
    int oldest = -1;

    for (int i = 0; i < 32; i++) {
        if ((num >> i) & 1) {
            if (youngest == -1) youngest = i;
            oldest = i;
        }
    }

    if (youngest == -1) {
        printf("У числі немає значущих бітів.\n");
    } else {
        printf("Наймолодший значущий біт: %d\n", youngest);
        printf("Найстарший значущий біт: %d\n", oldest);
    }

    return 0;
}
