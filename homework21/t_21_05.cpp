#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>

int main() {
    std::string str = "Hello, World!";


    std::transform(str.begin(), str.end(), str.begin(), ::toupper);


    std::cout << str << std::endl;

    return 0;
}
