#include <iostream>
#include <vector>
#include <map>

int main() {
    std::vector<int> V;
    std::map<int, std::vector<int>> M;
    int n, temp;

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> temp;
        V.push_back(temp);
    }

    for (int num : V) {
        int last_digit = abs(num) % 10;
        M[last_digit].push_back(num);
    }

    for (const auto& pair : M) {
        std::cout << pair.first << ": ";
        for (int val : pair.second) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
