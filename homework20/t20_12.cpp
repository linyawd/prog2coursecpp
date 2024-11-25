#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    std::vector<int> V1, V2;
    int n1, n2, temp;

    std::cin >> n1;
    for (int i = 0; i < n1; ++i) {
        std::cin >> temp;
        V1.push_back(temp);
    }

    std::cin >> n2;
    for (int i = 0; i < n2; ++i) {
        std::cin >> temp;
        V2.push_back(temp);
    }

    std::set<int> unique_elements;
    unique_elements.insert(V1.begin(), V1.end());
    unique_elements.insert(V2.begin(), V2.end());

    std::vector<int> result(unique_elements.begin(), unique_elements.end());
    std::sort(result.rbegin(), result.rend());

    for (int num : result) {
        std::cout << num << " ";
    }

    return 0;
}
