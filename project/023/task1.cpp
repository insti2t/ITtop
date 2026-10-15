#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru-RU");

    cout << "Введите целое число" << endl;
    int x;
    cin >> x;
    
    if(x > 0) {
        cout << "Число положительное" << endl;
    }
    else if(x < 0 )
        cout << "Число отрицательное" << endl;
    else
        cout << "Это ноль" << endl;
    return 0;
}