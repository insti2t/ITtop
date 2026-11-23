#include <iostream>

using namespace std;

int main() {
    int a = 10;
    int b = 20;
    int &refa = a;
    int &refb = b;
    
    refa += 5;
    refb -= 3;

    cout << a << " a; " << refa << " refa" << endl;
    cout << b << " b; " << refb << " refb" << endl;
    cout << &a << " a; " << &refa << " refa" << endl;
    cout << &b << " b; " << &refb << " refb" << endl;


    if(&a == &refa) {
        cout << "true" << endl;
    }

    
    if(&b == &refb) {
        cout << "true" << endl;
    }
}