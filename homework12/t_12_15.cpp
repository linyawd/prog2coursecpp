#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <vector>

double geometricMean(const std::vector<double>& numbers) {
    if (numbers.empty()) return 0.0;
    double product = 1.0;
    for (double num : numbers) {
        product *= num;
    }
    return std::pow(product, 1.0 / numbers.size());
}

std::vector<double> readNumbersFromFile(const std::string& filename) {
    std::vector<double> numbers;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Не вдалося відкрити файл " << filename << std::endl;
        return numbers;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        double number;
        while (iss >> number) {
            numbers.push_back(number);
        }
    }

    return numbers;
}

int main() {
    std::string filename = "/Users/lina/CLionProjects/proghome2/prog2coursecpp/homework12/input.txt";
    std::vector<double> numbers = readNumbersFromFile(filename);

    if (!numbers.empty()) {
        double result = geometricMean(numbers);
        std::cout << "Середнє геометричне чисел: " << result << std::endl;
    } else {
        std::cout << "Файл порожній або містить некоректні дані." << std::endl;
    }

    return 0;
}
