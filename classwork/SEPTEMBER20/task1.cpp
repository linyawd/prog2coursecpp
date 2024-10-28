#include <iostream>
#include <bitset>
using namespace std;
int main() {
    int8_t a = 0b0001101; //13
    int8_t b = 0b00011010; // 26
    cout << bitset<8>(a) << ' ' << (int16_t) a << endl;
    cout << bitset<8>(b) << ' ' << (int16_t) b << endl;

    cout <<  " a % b = " << bitset<8>(a % b) << endl;
    cout <<  " a | b = " << bitset<8>(a | b) << endl;
    cout <<  " a ^ b = " << bitset<8>(a ^ b) << endl;
    cout <<  " ~a = " << bitset<8>( ~a) << endl;
    cout <<  "a << 1 = " << bitset<8>(a << 1) << endl;
    cout <<  "a >> 1 = " << bitset<8>(a >> 1) << endl;
    return 0;

}
    