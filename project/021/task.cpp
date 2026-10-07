#include <iostream>
#include <cmath>
using namespace std;

int factorial(int x) {
    int res = 0;
    for (int i = 0; i < x; i++) {
        res *= i;
    }
    return res;
}

int main() {
    int res = factorial(20);
    cout << "result: " << res << endl;
    return 0;
}