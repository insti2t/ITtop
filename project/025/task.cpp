#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru-RU");
    int x;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
    double y = 0; // счетчик
    double c = 0; //
    while (x != 0)
    {
        cout << "Введите целое число" << endl;
        cin >> x;
        ++y;
        c += x;
    }
    if(y > 0){
        cout << "Среднее арифметическое число: " << c / y << endl;
        return 0;
    }
    else {
        cout << "Ввод отсутсвовал" << endl;
        return 0;
    } 
    return 0;
}