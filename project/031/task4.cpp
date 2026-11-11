#include <iostream>
#include <ctime>
#include <cstdlib> 


using namespace std;

int main() {
    setlocale(LC_ALL, "ru-RU.UTF-8");

    int arr[5][5] = {}; 
    int placed = 0; // счетчик расположенных
    
    srand(time(nullptr)); // для нач.значения генератору rand

    while (placed < 5) {
        int row = rand() % 5; // координата горизонтали
        int col = rand() % 5; // координата вертикали
        if (arr[row][col] == 0) {
            arr[row][col] = 1;
            placed++;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
             cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    bool conf = false;
    
    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 5; j++) {
            sum += arr[i][j];
        }
        if(sum >= 2) {
            cout << "Конфликт в строке " << i+1 << endl;
            conf = true;
        }
    }

    for (int i = 0; i < 5; i++) {
        int sum = 0;
        for (int j = 0; j < 5; j++) {
            sum += arr[j][i];
        }
        if(sum >= 2) {
            cout << "Конфликт в столбце " << i+1 << endl;
            conf = true;
        }
    }


    if (conf == false) {
        cout << "Расстановка корректна" << endl;
    }

    return 0;
}