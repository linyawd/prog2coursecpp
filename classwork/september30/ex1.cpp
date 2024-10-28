#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cout << "Введіть натуральне число n: ";
    std::cin >> n;

    std::vector<double> arr(n);
    std::cout << "Введіть " << n << " дійсних чисел: " << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    double sum_squares = 0;
    for (int i = 0; i < n; i++) {
        sum_squares += std::pow(arr[i], 2);
    }

    std::cout << "Сума квадратів елементів масиву: " << sum_squares << std::endl;

    return 0;
}
