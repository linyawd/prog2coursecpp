#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

int findMinLength(const std::vector<std::string>& words) {
    int minLength = words[0].size();
    for (const auto& word : words) {
        if (word.size() < minLength) {
            minLength = word.size();
        }
    }
    return minLength;
}

int main() {
    std::string text;
    std::cout << "Введіть речення: ";
    std::getline(std::cin, text);

    std::istringstream stream(text);
    std::vector<std::string> words;
    std::string word;

    while (stream >> word) {
        words.push_back(word);
    }

    int minLength = findMinLength(words);
    std::vector<std::string> shortestWords;

    for (const auto& w : words) {
        if (w.size() == minLength) {
            shortestWords.push_back(w);
        }
    }

    std::cout << "Перше найкоротше слово: " << shortestWords.front() << std::endl;
    std::cout << "Останнє найкоротше слово: " << shortestWords.back() << std::endl;

    std::cout << "Всі найкоротші слова: ";
    for (const auto& w : shortestWords) {
        std::cout << w << " ";
    }
    std::cout << std::endl;

    return 0;
}
