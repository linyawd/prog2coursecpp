#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>

bool isValidDate(int day, int month, int year) {
    if (year < 1 || month < 1 || month > 12 || day < 1) return false;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) daysInMonth[1] = 29;
    return day <= daysInMonth[month - 1];
}

void processDates(const std::string& input) {
    std::istringstream iss(input);
    std::string word;
    std::regex datePattern("\\b\\d{8}\\b");

    while (iss >> word) {
        if (std::regex_match(word, datePattern)) {
            int day = std::stoi(word.substr(0, 2));
            int month = std::stoi(word.substr(2, 2));
            int year = std::stoi(word.substr(4, 4));

            if (isValidDate(day, month, year)) {
                std::cout << "Коректна дата: " << word << " -> " << day << "-" << month << "-" << year << std::endl;
            } else {
                std::cout << "Некоректна дата: " << word << " -> " << day << "-" << month << "-" << year << std::endl;
            }
        }
    }
}

int main() {
    std::string input;
    std::cout << "Введіть рядок: ";
    std::getline(std::cin, input);
    processDates(input);
    return 0;
}
