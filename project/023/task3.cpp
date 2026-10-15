#include <iostream>
#include <cmath>

using namespace std;

int ost(int year) {
    int a;
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
        a = 29;
    }
    else {
        a = 28;
    }
    return a;
}


int main() {
    setlocale(LC_ALL, "ru-RU");

    cout << "Введите число месяца от 1 до 12" << endl;
    int month;
    cin >> month;

    cout << "Введите год" << endl;
    int year;
    cin >> year;

    switch (month)
    {
    case 1:
    cout << "Январь" << endl; 
    cout << "В нем " << 31 << " день" << endl;   
        break;
    case 2:
    cout << "Февраль" << endl; 
    cout << "В нем " << ost(year) << " дней" << endl;   
        break;
    case 3:
    cout << "Март" << endl; 
    cout << "В нем " << 31 << " день" << endl;   
        break;
    case 4:
    cout << "Апрель" << endl; 
    cout << "В нем " << 30 << " дней" << endl;   
        break;
    case 5:
    cout << "Май" << endl; 
    cout << "В нем " << 31 << " день" << endl;   
        break;
    case 6:
    cout << "Июнь" << endl; 
    cout << "В нем " << 30 << " дней" << endl;   
        break;
    case 7:
    cout << "Июль" << endl; 
    cout << "В нем " << 31 << " день" << endl;   
        break;
    case 8:
    cout << "Август" << endl; 
    cout << "В нем " << 31 << " день" << endl;   
        break;
    case 9:
    cout << "Сентябрь" << endl; 
    cout << "В нем " << 30 << " дней" << endl;   
        break;
    case 10:
    cout << "Октябрь" << endl; 
    cout << "В нем " << 31 << " день" << endl;   
        break;
    case 11:
    cout << "Ноябрь" << endl; 
    cout << "В нем " << 30 << " дней" << endl;   
        break;
    case 12:
    cout << "Декабрь" << endl; 
    cout << "В нем " << 31 << " день" << endl;   
        break;
    
    default:
    cout << "Нет такого месяца" << endl;
        break;
    }
    return 0;
}