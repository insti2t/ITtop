#include <iostream>
#include <cmath>

using namespace std;

int kg(int x){
    int cof;
    if(x <= 5){
        cof = 500;
    }
    else if(x >= 20) {
        cof = 1500;
    }
    else {
        cof = 500;
        int dop;
        dop = x / 5 * 50;
        if(dop = 1) {
            return cof;
        }
        else {
            cof = cof + dop;
        }
    }
    return cof;
}

double prc(int y) {
    double t = 0;
    if(y == 1){
        t = 1;
    }
    else if(y == 2) {
        t = 1.3;
    }
    else if(y == 3) {
        t = 1.5;
    }    
    else {
        t = 0;
        cout << "Неверный тип доставки" << endl;
    }
    return t;
}

int main() {
    setlocale(LC_ALL, "ru-RU");

    cout << "Введите вес посылки в кг" << endl;
    int x;
    cin >> x;

    cout << "Выберите тип доставки: 1 - обычная, 2 - экспресс, 3 - приоритетная" << endl;    
    int y;
    cin >> y;

    double itog = kg(x)*prc(y);

    cout <<  "Итоговая стоимость: " << itog << endl;

    return 0;
}