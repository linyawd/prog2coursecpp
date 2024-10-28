#include <iostream>
#include <cstdlib>

using namespace std;

void print(int*a, int n) {
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {

    int n;
    cin >> n;

    int* a = (int*)malloc(n * sizeof(*a));

    free (a);
    return 0;


}