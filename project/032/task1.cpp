#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru-RU.UTF-8");
    int a = 1, b = 2;
    int &ref_a = a, &ref_b = b;
    cout << ref_a << endl;
    cout << ref_b << endl;
    cout << ref_a + ref_b << endl;
    ref_a = 10;
    cout << a << endl;
    cout << ref_a << endl;
    return 0;    
}