#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

template <typename T>
class BlackBox {
private:
    std::vector<T> elements;
    static const int MAX_SIZE = 100;

public:
    
    BlackBox() {
        std::srand(std::time(0));
    }


    BlackBox(T* array, int size) {
        std::srand(std::time(0));
        for (int i = 0; i < size && elements.size() < MAX_SIZE; ++i) {
            elements.push_back(array[i]);
        }
    }


    void push(const T& item) {
        if (elements.size() < MAX_SIZE) {
            elements.push_back(item);
        } else {
            throw std::overflow_error("BlackBox переповнено");
        }
    }


    T pop() {
        if (elements.empty()) {
            throw std::underflow_error("BlackBox порожній");
        }
        int index = std::rand() % elements.size();
        T item = elements[index];
        elements.erase(elements.begin() + index);
        return item;
    }


    T xpop() const {
        if (elements.empty()) {
            throw std::underflow_error("BlackBox порожній");
        }
        int index = std::rand() % elements.size();
        return elements[index];
    }
};

int main() {

    BlackBox<int> box;
    box.push(10);
    box.push(20);
    box.push(30);

    try {
        std::cout << "Випадковий елемент (xpop): " << box.xpop() << std::endl;
        std::cout << "Видалений випадковий елемент (pop): " << box.pop() << std::endl;
        std::cout << "Випадковий елемент (xpop): " << box.xpop() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }

    return 0;
}

