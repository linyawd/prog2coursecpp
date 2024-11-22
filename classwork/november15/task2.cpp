#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


vector<double> inputVector(int d) {
    vector<double> vec(d);
    cout << "Введіть " << d << " компонент вектору: ";
    for (int i = 0; i < d; i++) {
        cin >> vec[i];
    }
    return vec;
}

// Функція для обчислення норми вектораle calculateNorm(const vector<double>& vec) {
    double sum = 0;
    for (double val : vec) {
        sum += val * val;
    }
    return sqrt(sum);
}

// Основна програма
int main() {
    int n, d;
    cout << "Введіть кількість векторів (n): ";
    cin >> n;
    cout << "Введіть розмірність векторів (d): ";
    cin >> d;

    vector<vector<double>> vectors(n);
    double sumOfNorms = 0;

    // Введення векторів та обчислення їх норм
    for (int i = 0; i < n; i++) {
        cout << "Введення вектору " << i + 1 << ":" << endl;
        vectors[i] = inputVector(d);
        sumOfNorms += calculateNorm(vectors[i]);
    }

    // Виведення суми норм векторів
    cout << "Сума норм векторів: " << sumOfNorms << endl;

    return 0;
}
