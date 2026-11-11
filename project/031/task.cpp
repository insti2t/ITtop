#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru-RU.UTF-8");
    int arr[10];
    int sum = 0;
    int count = 0;
    double avg = 0;

    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
        avg += arr[i];
        if (arr[i] % 2 == 0) {
            sum += arr[i];
        }
        else {
            count += 1;
        }
    }

    cout << "Среднее арифметическое: " << avg/10 << endl;
    cout << "Сумма четных: " << sum << endl;
    cout << "Кол-во нечетных: " << count << endl;
    return 0;
}