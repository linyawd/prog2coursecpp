#include <iostream>
#include <list>
#include <algorithm>
#include <ctime>
#include <iterator>

clock_t clockGenerator() {
    return clock();
}

int main() {
    std::list<clock_t> clockList;
    std::generate_n(std::back_inserter(clockList), 10, clockGenerator);
    clockList.sort();
    clockList.unique();
    std::copy(clockList.begin(), clockList.end(), std::ostream_iterator<clock_t>(std::cout, " "));
    return 0;
}
