#include <iostream>
#include <string>
#include <stdexcept>
#include <cassert>

int charToDigit(char ch, int base) {
    int digit;

    if ('0' <= ch && ch <= '9') {
        digit = ch - '0';
    } else if ('A' <= ch && ch <= 'F') {
        digit = ch - 'A' + 10;
    } else if ('a' <= ch && ch <= 'f') {
        digit = ch - 'a' + 10;
    } else {
        throw std::invalid_argument("Невірний символ у числі.");
    }


    assert(digit < base && "Символ не є дійсною цифрою для цієї системи числення.");

    return digit;
}

int convertToDecimal(const std::string& str, int base) {
    if (base < 2 || base > 16) {
        throw std::invalid_argument("Основа системи числення повинна бути в межах від 2 до 16.");
    }

    int result = 0;
    for (char ch : str) {
        int digit = charToDigit(ch, base);
        result = result * base + digit;
    }

    return result;
}

int main() {
    std::string input;
    int base;

    std::cout << "Введіть число: ";
    std::cin >> input;
    std::cout << "Введіть основу системи числення: ";
    std::cin >> base;

    try {
        int decimalValue = convertToDecimal(input, base);
        std::cout << "Десяткове значення: " << decimalValue << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }

    return 0;
}
