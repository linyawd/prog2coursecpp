#include <iostream>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);

    size_t first_dot = s.find('.');
    size_t last_dot = s.rfind('.');

    if (first_dot == std::string::npos) {
        s.erase(0, s.find_first_not_of(' '));
    } else if (first_dot == last_dot) {
        s.erase(0, first_dot + 1);
    } else {
        s.erase(first_dot, last_dot - first_dot + 1);
    }

    std::cout << s << std::endl;
    return 0;
}
