#include <stdio.h>
#include <math.h>

int is_point_in_cylinder(double x, double y, double z, double r, double h) {
    if (z >= 0 && z <= h) {
        double distance = sqrt(x * x + y * y);
        if (distance <= r) {
            return 1;
        }
    }
    return 0;
}

int main() {
    double x, y, z, r, h;

    printf("Введіть координати точки (x, y, z): ");
    scanf("%lf %lf %lf", &x, &y, &z);

    printf("Введіть радіус основи циліндра r та висоту h: ");
    scanf("%lf %lf", &r, &h);

    if (is_point_in_cylinder(x, y, z, r, h)) {
        printf("Точка належить циліндру\n");
    } else {
        printf("Точка не належить циліндру\n");
    }

    return 0;
}
