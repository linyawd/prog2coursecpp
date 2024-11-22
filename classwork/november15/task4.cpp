#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cout << "Введіть кількість рядків (n): ";
    cin >> n;
    cout << "Введіть кількість стовпців (m): ";
    cin >> m;


    vector<list<int>> matrix(n);
    for (int i = 0; i < n; ++i) {
        cout << "Введіть елементи рядка " << i + 1 << ": ";
        for (int j = 0; j < m; ++j) {
            int value;
            cin >> value;
            matrix[i].push_back(value);
        }
    }


    auto maxElement = [](const list<int>& row) {
        return *max_element(row.begin(), row.end());
    };


    sort(matrix.begin(), matrix.end(), [&](const list<int>& a, const list<int>& b) {
        return maxElement(a) > maxElement(b);
    });


    cout << "Матриця після сортування рядків за спаданням максимальних елементів:" << endl;
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}
