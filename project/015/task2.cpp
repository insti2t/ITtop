#include <iostream>
#include <cmath>

using namespace std;

double sub_fn(double a, double b) {
    if (b == 0) return 0;
    int l3 = floor(a / b - 5);
    if (l3 == 0) return 0;
    double num = 1 / (l3 * 23);
    return num;
}

void cycle() {
    double res = 0;
    for (int i = 1; i < 10000; i++) {
        double a = log(i);
        double b = log(4);
        res += sub_fn(a, b);
        cout << i << endl;
    }
    cout << res;
}

int main() {
    cycle();
}