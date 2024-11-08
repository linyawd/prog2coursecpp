#include <iostream>
#include <stack>
#include <vector>
using namespace std;


template <typename T>
class MyStack {
private:
    vector<T> elements;

public:
    void push(const T& value) {
        elements.push_back(value);
    }

    void pop() {
        if (!elements.empty()) {
            elements.pop_back();
        }
    }

    T top() const {
        if (!elements.empty()) {
            return elements.back();
        }
        throw out_of_range("Stack is empty");
    }

    bool empty() const {
        return elements.empty();
    }

    size_t size() const {
        return elements.size();
    }
};


template <typename StackType>
void inputNumbers(StackType& stack, vector<int>& result) {
    int number;
    while (true) {
        cin >> number;
        if (number == 0) break;
        stack.push(number);
    }


    while (!stack.empty()) {
        result.push_back(stack.top());
        stack.pop();
    }
}

int main() {
    MyStack<int> myStack;
    vector<int> myResult;

    cout << "Введіть числа (0 для завершення): ";
    inputNumbers(myStack, myResult);

    cout << "Результат (власний стек): ";
    for (int num : myResult) {
        cout << num << " ";
    }
    cout << endl;


    stack<int> stdStack;
    vector<int> stdResult;

    cout << "Введіть числа для стандартного стека (0 для завершення): ";
    inputNumbers(stdStack, stdResult);

    cout << "Результат (стандартний стек): ";
    for (int num : stdResult) {
        cout << num << " ";
    }
    cout << endl;



    return 0;
}
