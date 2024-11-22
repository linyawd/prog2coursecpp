#include <iostream>
#include <list>
#include <cmath>
#include <limits>

class NumberList {
private:
    std::list<int> numbers;

public:
    void add(int number) {
        numbers.push_back(number);
    }

    void remove(int number) {
        numbers.remove(number);
    }

    int findClosest(int target) {
        if (numbers.empty()) {
            throw std::runtime_error("List is empty");
        }

        int closest = *numbers.begin();
        int minDifference = std::abs(target - closest);

        for (int num : numbers) {
            int difference = std::abs(target - num);
            if (difference < minDifference) {
                minDifference = difference;
                closest = num;
            }
        }

        return closest;
    }

    void print() {
        for (int num : numbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    NumberList nl;
    nl.add(10);
    nl.add(20);
    nl.add(30);
    nl.remove(20);
    std::cout << "Closest to 25: " << nl.findClosest(25) << std::endl;
    nl.print();
    return 0;
}
