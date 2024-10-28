#include <stdio.h>
#include <stdlib.h>



struct Point {
    double x;
    double y;
};

struct Rectangle {
    struct Point topLeft;
    struct Point bottomRight;
};

struct Polynomial {
    int degree;
    double* coefficients;
};

// ввід

void inputRectangle(struct Rectangle* rect) {
    printf("координати верхньої лівої вершини (x y): ");
    scanf("%lf %lf", &rect->topLeft.x, &rect->topLeft.y);
    printf("координати нижньої правої вершини (x y): ");
    scanf("%lf %lf", &rect->bottomRight.x, &rect->bottomRight.y);
}

//вивід
void printRectangle(struct Rectangle rect) {
    printf("Прямокутник:\n");
    printf("Верхня ліва вершина: (%.2f, %.2f)\n", rect.topLeft.x, rect.topLeft.y);
    printf("Нижня права вершина: (%.2f, %.2f)\n", rect.bottomRight.x, rect.bottomRight.y);
}

//ввід
void inputPolynomial(struct Polynomial* poly) {
    printf("Введіть ступінь поліному: ");
    scanf("%d", &poly->degree);

    poly->coefficients = (double*) malloc((poly->degree + 1) * sizeof(double));
    printf("Введіть коефіцієнти поліному (від старшого до молодшого):\n");
    for (int i = 0; i <= poly->degree; i++) {
        printf("Коефіцієнт при x^%d: ", poly->degree - i);
        scanf("%lf", &poly->coefficients[i]);
    }
}

// вивід
void printPolynomial(struct Polynomial poly) {
    printf("Поліном: ");
    for (int i = 0; i <= poly.degree; i++) {
        printf("%.2lf", poly.coefficients[i]);
        if (i < poly.degree) {
            printf("x^%d + ", poly.degree - i);
        }
    }
    printf("\n");
}




int main() {
    struct Rectangle rect;
    struct Polynomial poly;


    inputRectangle(&rect);
    printRectangle(rect);


    inputPolynomial(&poly);
    printPolynomial(poly);

    // Звільнення пам'яті для коефіцієнтів полінома
    free(poly.coefficients);

    return 0;
}
