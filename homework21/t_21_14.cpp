#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>


int monthToNumber(const std::string& month) {
    static std::map<std::string, int> monthMap = {
        {"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4},
        {"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8},
        {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}
    };
    return monthMap[month];
}


struct Date {
    int year;
    int month;
    int day;


    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }
};

int main() {
    std::ifstream inputFile("/Users/lina/CLionProjects/proghome2/prog2coursecpp/homework21/input14.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Помилка відкриття файлу!" << std::endl;
        return 1;
    }

    std::string line;
    std::getline(inputFile, line);
    inputFile.close();

    std::istringstream iss(line);
    std::string token;
    std::set<Date> uniqueDates;

    while (std::getline(iss, token, ',')) {
        std::istringstream dateStream(token);
        int day, year;
        std::string month;
        dateStream >> day >> month >> year;


        int monthNumber = monthToNumber(month);


        uniqueDates.insert({year, monthNumber, day});
    }


    for (const auto& date : uniqueDates) {
        std::cout << date.year << "/" << date.month << "/" << date.day << std::endl;
    }

    return 0;
}