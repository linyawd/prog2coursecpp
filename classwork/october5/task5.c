#include <stdio.h>
#include <string.h>

#define MAX_N 100

typedef struct {
    char name[50];
    int height;
} Mountain;

void inputMountains(Mountain mountains[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" назва гори %d: ", i + 1);
        scanf("%s", mountains[i].name);
        printf("висота гори %d: ", i + 1);
        scanf("%d", &mountains[i].height);
    }
}

void printMountains(Mountain mountains[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Гора: %s, Висота: %d\n", mountains[i].name, mountains[i].height);
    }
}

char* findHighestMountain(Mountain mountains[], int n) {
    int maxHeight = -1;
    char* highestMountain = NULL;
    for (int i = 0; i < n; i++) {
        if (mountains[i].height > maxHeight) {
            maxHeight = mountains[i].height;
            highestMountain = mountains[i].name;
        }
    }
    return highestMountain;
}

int findMountainHeight(Mountain mountains[], int n, char* name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(mountains[i].name, name) == 0) {
            return mountains[i].height;
        }
    }
    return -1;  // Вершина не знайдена
}

int main() {
    int n;
    Mountain mountains[MAX_N];

    printf("Введіть к-сть гір: ");
    scanf("%d", &n);

    inputMountains(mountains, n);
    printMountains(mountains, n);

    char* highestMountain = findHighestMountain(mountains, n);
    printf("Найвища вершина: %s\n", highestMountain);

    char searchName[50];
    printf("назва гори для пошуку висоти: ");
    scanf("%s", searchName);
    int height = findMountainHeight(mountains, n, searchName);
    if (height != -1) {
        printf("Висота вершини %s: %d\n", searchName, height);
    } else {
        printf("Вершина з назвою %s не знайдена.\n", searchName);
    }

    return 0;
}
