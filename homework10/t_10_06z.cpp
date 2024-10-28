#include <stdio.h>

typedef struct {
    double length;
    double width;
    double height;
} Parallelepiped;

void inputParallelepiped(Parallelepiped* p) {
    printf("Введіть довжину, ширину і висоту паралелепіпеда: ");
    scanf("%lf %lf %lf", &p->length, &p->width, &p->height);
}

void outputParallelepiped(const Parallelepiped* p) {
    printf("Паралелепіпед - Довжина: %.2f, Ширина: %.2f, Висота: %.2f\n", p->length, p->width, p->height);
}

int main() {
    Parallelepiped p;
    inputParallelepiped(&p);
    outputParallelepiped(&p);

    return 0;
}
