#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 10;
double arr[SIZE];

int main() {
    const size_t ROWS = 3, COLS = 3;
    int matr[ROWS][COLS];
    //ввод
    for(size_t i = 0; i != ROWS; ++i)
        for(size_t j = 0; j != COLS; ++j){
            cout << "Элемент " << "," << j << ": ";
            cin >> matr[i][j];
        }

    //вычисление суммы элементов последней строки
    int sum = 0;
    for(size_t j = 0; j != COLS; ++j)
    sum += matr[2][j];
    cout << "Сумма элементов последней строки: " << sum << endl;

    //вычисление определителя
    int det = matr[0][0] * matr[1][1] * matr[2][2]
        + matr[0][1] * matr[1][2] * matr[2][2]
        + matr[1][0] * matr[2][1] * matr[0][2]
        - matr[2][0] * matr[1][1] * matr[0][2]
        - matr[2][1] * matr[1][2] * matr[0][0]
        - matr[1][0] * matr[0][1] * matr[2][2];
        cout << "Определитель: " << det << endl;

    // Транспонирование
    for(size_t i = 0; i != ROWS; ++i)
        for(size_t j = 0; j != i; ++j)
            swap(matr[i][j], matr[j][i]);

    // Вывод транспонированной матрицы
    for(size_t i = 0; i != ROWS; ++i)
        for(size_t j = 0; j != COLS; ++j){
            cout << matr[i][j];
            if(j != 2)
                cout << "\t";
            else
                cout << endl;
    }
}