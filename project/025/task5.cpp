#include <iostream>
#include <cmath>

using namespace std;

int main() {
    cout << "Type any char" << endl;
    int a;
    cin >> a;

        if(a > 20){
            cout << "RISK OF OVERFLOW!! MAX 20 CHARS!!" << endl;
        }

    for (int i = 0; i <= a && i <= 20; i++)
    {
        cout << i << "! = " << tgamma(i + 1) << endl;
    }
    return 0;
}