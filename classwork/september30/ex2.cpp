#include <iostream>
#include <cmath>
#include <vector>

int countSquaresCubes(const std::vector<int>& arr, int& squares, int& cubes) {
    squares = 0;
    cubes = 0;

    for (int num : arr) {
        int sqrt_num = static_cast<int>(std::sqrt(num));
        int cbrt_num = static_cast<int>(std::cbrt(num));

        if (sqrt_num * sqrt_num == num) {
            squares++;
        }

        if (cbrt_num * cbrt_num * cbrt_num == num) {
            cubes++;
        }
    }

    return arr.size();
}

int main() {
    const int max_size = 100;
    std::vector<int> arr;
    int num;

    std::cout << "Введіть ціле число (нуль для завершення):" << std::endl;
    while (std::cin >> num && num != 0 && arr.size() < max_size) {
        arr.push_back(num);
    }

    int squares, cubes;
    int size = countSquaresCubes(arr, squares, cubes);

    std::cout << "Кількість елементів у масиві: " << size << std::endl;
    std::cout << "Кількість повних квадратів: " << squares << std::endl;
    std::cout << "Кількість повних кубів: " << cubes << std::endl;

    return 0;
}
