#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

void processFile(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);

    if (!inFile) {
        std::cerr << "Не вдалося відкрити вхідний файл " << inputFile << std::endl;
        return;
    }
    if (!outFile) {
        std::cerr << "Не вдалося відкрити вихідний файл " << outputFile << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::ostringstream processedLine;
        std::string word;


        while (iss >> word) {

            for (char& ch : word) {
                if (ch == '0') {
                    ch = '1';
                } else if (ch == '1') {
                    ch = '0';
                }
            }


            std::reverse(word.begin(), word.end());


            processedLine << word << " ";
        }


        std::string result = processedLine.str();
        if (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        outFile << result << std::endl;
    }

    inFile.close();
    outFile.close();
}

int main() {
    std::string inputFile = "/Users/lina/CLionProjects/proghome2/prog2coursecpp/homework14/input.txt";
    std::string outputFile = "/Users/lina/CLionProjects/proghome2/prog2coursecpp/homework14/output.txt";

    processFile(inputFile, outputFile);

    std::cout << "Обробка файлу завершена. Результати записано у " << outputFile << std::endl;

    return 0;
}
