#include <iostream>
#include <vector>
#include <algorithm>

template<typename InputIt, typename OutputIt, typename UnaryPredicate, typename UnaryOperation>
OutputIt transform_if(InputIt first, InputIt last, OutputIt d_first, UnaryPredicate pred, UnaryOperation op) {
    while (first != last) {
        if (pred(*first)) {
            *d_first++ = op(*first);
        }
        ++first;
    }
    return d_first;
}

int main() {
    std::vector<int> input = {1, 2, 3, 4, 5, 6};
    std::vector<int> output;

    auto is_even = [](int x) { return x % 2 == 0; };
    auto square = [](int x) { return x * x; };

    transform_if(input.begin(), input.end(), std::back_inserter(output), is_even, square);

    for (int x : output) {
        std::cout << x << " ";
    }

    return 0;
}