#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>

int main() {

    std::ifstream inputFile("/Users/lina/CLionProjects/proghome2/prog2coursecpp/classwork/november18/input1.txt");
    std::ofstream outputFile("/Users/lina/CLionProjects/proghome2/prog2coursecpp/classwork/november18/output1.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Не вдалося відкрити файл!" << std::endl;
        return 1;
    }

    std::map<std::string, int> wordCount;
    std::string line, word;

    while (std::getline(inputFile, line)) {
        std::istringstream stream(line);
        while (stream >> word) {
            ++wordCount[word];
        }
    }


    for (const auto& pair : wordCount) {
        outputFile << pair.first << ": " << pair.second << std::endl;
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Результати збережено у файлі output1.txt" << std::endl;
    return 0;
}
