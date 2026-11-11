#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru-RU.UTF-8");
    srand(time(nullptr));

    int arr[15] = {};
    for (int i = 0; i < 15; i++) {
        arr[i] = rand() % 21 + 10;
        cout << arr[i] << endl;
    }

    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 14; j++){
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << "Лучшие: " << arr[0] << " " << arr[1] << " " << arr[2] << endl;

    int field[3][5] = {};
    int counter = 0;
    int sum = 0;
    
    for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 5; j++) {
        field[i][j] = arr[counter];
        sum += arr[counter];
        counter++;
        cout << field[i][j] << " ";
        }
    cout << endl;
    }   
    cout << "avg: " << sum/counter << endl;

    return 0;
}