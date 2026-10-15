#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru-RU");
    int a;
    int b;
    int c;
    cout << "Введите 3 целых числа последовательно" << endl;
    cin >> a;
    cin >> b;
    cin >> c;
    if((a + b > c) && (a + c > b) && (c + b > a)) {
        if(a == b == c){
            cout << "Треугольник равносторонний" << endl;
        }
        else if((a == b) || (a != c)) {
            cout << "Треугольник равнобедренный" << endl;            
        }
        else if((a != b) || (b != c)) {
            cout << "Треугольник разносторонний" << endl;  
        }
        else {
            cout << "Треунольник невозможен" << endl;
        }
        return 0;
    }
    else{
        cout << "Треунольник невозможен" << endl;
        return 0;
    }
    return 0;
}