#include <iostream>
using namespace std;

int main() {
    int arr[5] = {12, 7, 9, 3, 5};
    double num;
    int count = 0;

    cout << "Введіть число: ";
    cin >> num;


    for (int i = 0; i < 5; ++i) {
        if (arr[i] < num) {
            ++count;
        }
    }

    cout << "Кількість чисел менших за " << num << ": " << count << endl;

    return 0;
}
