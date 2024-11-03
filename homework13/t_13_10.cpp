#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

int countWordsWithSameStartAndEnd(const std::string& input) {
    std::istringstream iss(input);
    std::string word;
    int count = 0;

    while (iss >> word) {
        char first = std::tolower(word.front());
        char last = std::tolower(word.back());
        if (first == last) {
            count++;
        }
    }
    return count;
}

int main() {
    std::string input;
    std::cout << "Введіть рядок: ";
    std::getline(std::cin, input);
    int result = countWordsWithSameStartAndEnd(input);
    std::cout << "Кількість слів, що починаються і закінчуються однією й тією ж літерою: " << result << std::endl;
    return 0;
}

