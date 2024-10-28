#include <stdio.h>

#define MAX_SIZE 20

// Введення вектора
void input_vector(double vec[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%lf", &vec[i]);
    }
}

// Виведення вектора
void output_vector(double vec[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", vec[i]);
    }
    printf("\n");
}

// Сума двох векторів
void sum_vectors(double v1[], double v2[], double res[], int n) {
    for (int i = 0; i < n; i++) {
        res[i] = v1[i] + v2[i];
    }
}

// Скалярний добуток
double dot_product(double v1[], double v2[], int n) {
    double result = 0;
    for (int i = 0; i < n; i++) {
        result += v1[i] * v2[i];
    }
    return result;
}

int main() {
    int n;
    double v1[MAX_SIZE], v2[MAX_SIZE], res[MAX_SIZE];

    // Введення розміру вектора
    scanf("%d", &n);

    // Введення векторів
    input_vector(v1, n);
    input_vector(v2, n);

    // Сума векторів
    sum_vectors(v1, v2, res, n);
    output_vector(res, n);

    // Скалярний добуток
    printf("%.2lf\n", dot_product(v1, v2, n));

    return 0;
}
