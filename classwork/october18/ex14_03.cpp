#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    std::ifstream inputFile("/Users/lina/CLionProjects/proghome2/prog2coursecpp/classwork/october18/input2.txt");
    std::ofstream outputFile("/Users/lina/CLionProjects/proghome2/prog2coursecpp/classwork/october18/output.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Помилка відкриття вхідного файлу" << std::endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Помилка відкриття вихідного файлу" << std::endl;
        return 1;
    }

    std::string word;
    while (inputFile >> word) {

        std::string punctuation;
        while (!word.empty() && ispunct(word.back())) {
            punctuation.push_back(word.back());
            word.pop_back();
        }


        std::reverse(word.begin(), word.end());


        outputFile << word << punctuation << " ";
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Розшифрування завершено, результат у файлі output.txt" << std::endl;
    return 0;
}
