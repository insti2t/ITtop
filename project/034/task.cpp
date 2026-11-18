#include <iostream>

using namespace std;

int main() {
    int a = 1, b = 2;
    int* gg = &a;
    cout << "Значение a: " << *gg << ", адрес a: " << gg << endl;
    gg = &b;
    cout << "Значение b: " << *gg << ", адрес b: " << gg << endl;
}