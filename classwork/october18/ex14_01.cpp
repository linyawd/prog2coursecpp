#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
int main() {
    std::ifstream file("/Users/lina/CLionProjects/proghome2/prog2coursecpp/classwork/october18/input.txt");

    if (!file.is_open()) {
        std::cerr << "Помилка відкриття файлу" << std::endl;
        return 1;
    }

    std::string expression;
    std::getline(file, expression);
    file.close();

    std::stringstream ss(expression);
    double result = 0;
    double num;
    char op = '+';

    while (ss >> num) {
        if (op == '+') {
            result += num;
        } else if (op == '-') {
            result -= num;
        }
        ss >> op;
    }

    std::cout << "Результат: " << result << std::endl;
    return 0;
}