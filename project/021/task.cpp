#include <iostream>
#include <cmath>
using namespace std;

int factorial(int x) {
    int res = 1;  // fix
    for (int i = 1; i <= x; i++) { // fix
        res *= i;
    }
    return res;
}

int main() {
    int res = factorial(20);
    cout << "result: " << res << endl;
    return 0;
}