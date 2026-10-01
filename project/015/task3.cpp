#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float num; // если кто то введет число с точкой, то цикл никогда не завершиться. 
    cin >> num;
    int a = 0;
    while (true)
    {
        if (num <= a) { // нужно хотя бы заменить == на <=
        break;
    }
    a++;
    cout << a << endl;
    }

    return 0;
}

// логическая вроде ошибка. он сравнивает float и int, ну а если обязательно сравнить их, то хотя бы не == , а <=, и то мы не получим точное число, ведь int не выведет точку