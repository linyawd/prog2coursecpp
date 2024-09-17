#include <iostream>
#include <cstdio>
using namespace std;

int fiba(int a) {

    int f0 = 0;
    int f1 = 1;
    int f2;
    int i = 0;
    for (; f0 < a; i++) {
        f2 = f1 + f0;
        f0 = f1;
        f1 = f2;

    }
    return i;
}

int main() {

    int a;
    cin >> a;
    cout << fiba(a) << endl;
    return 0;
}

