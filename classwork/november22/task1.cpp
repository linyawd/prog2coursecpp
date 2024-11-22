
#include <iostream>
#include <vector>
#include <algorithm>

class BoolVector {
private:
    std::vector<bool> data;

public:
    BoolVector(const std::vector<bool>& vec) : data(vec) {}

    BoolVector conjunction(const BoolVector& other) const {
        std::vector<bool> result(data.size());
        std::transform(data.begin(), data.end(), other.data.begin(), result.begin(), [](bool a, bool b) {
            return a && b;
        });
        return BoolVector(result);
    }

    BoolVector disjunction(const BoolVector& other) const {
        std::vector<bool> result(data.size());
        std::transform(data.begin(), data.end(), other.data.begin(), result.begin(), [](bool a, bool b) {
            return a || b;
        });
        return BoolVector(result);
    }

    BoolVector negation() const {
        std::vector<bool> result(data.size());
        std::transform(data.begin(), data.end(), result.begin(), [](bool a) {
            return !a;
        });
        return BoolVector(result);
    }

    int countOnes() const {
        return std::count(data.begin(), data.end(), true);
    }

    int countZeros() const {
        return std::count(data.begin(), data.end(), false);
    }

    void print() const {
        for (bool b : data) {
            std::cout << b << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    BoolVector vec1({1, 0, 1, 1, 0});
    BoolVector vec2({0, 1, 1, 0, 1});

    BoolVector conj = vec1.conjunction(vec2);
    BoolVector disj = vec1.disjunction(vec2);
    BoolVector neg = vec1.negation();

    std::cout << "Conjunction: ";
    conj.print();

    std::cout << "Disjunction: ";
    disj.print();

    std::cout << "Negation: ";
    neg.print();

    std::cout << "Count of ones in vec1: " << vec1.countOnes() << std::endl;
    std::cout << "Count of zeros in vec1: " << vec1.countZeros() << std::endl;

    return 0;
}
