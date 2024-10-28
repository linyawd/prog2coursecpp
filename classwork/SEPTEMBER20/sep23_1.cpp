#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;


void test() {


    uint32_t x = 0x0F070301;
    cout << bitset<32>(x) << endl;
    uint8_t* ptr = (uint8_t*)&x;
    for (int i = -3; i < 4; i++)
        cout << bitset<8> (*(ptr + i)) << ' ';
    cout << endl;

}
void endian () {

}

int main() {

    //test();
    return 0;
}