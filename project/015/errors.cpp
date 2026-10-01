#include <iostream>
#include <cmath>

using namespace std;

void syntax() {
    int a = 30;
    cout << "вывод числа: " << a; // нет ; 
}

void logic() {
    int counter = 1;
    while(true) {
        if (counter >= 100) { // меняем == на >=
            break;
        } // завершает цикл сразу же после условия, т.е. +2 не выполняеться
        counter += 2;
    }
    cout << counter;
}

void run_time() {
    int a = 100;
    double b = a * 0; // для деления на 0 нужен double или float
    cout << a / b;
}

int main () {
    syntax();
    cout << "\n";
    logic();
    cout << "\n";
    run_time();
    return 0;
}