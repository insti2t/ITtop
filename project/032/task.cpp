#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru-RU.UTF-8");
    // Обьявление и ввод
    const int N = 10;
    double arr[N];
    cout << "Введите элементы: " << endl;
    for(size_t i = 0; i != N; ++i) {
        cout << "arr[" << i << "]: ";
        cin >> *(arr + i);
    }
    // пузырьковая сортировка
    for (size_t i = N; i != 0; --i) 
        for (size_t j = 0; j != i - 1; ++j) 
            if (*(arr + j) > *(arr + j + 1)) 
                swap(*(arr + j), *(arr + j + 1));
    
    // вывод элементов массива
    for(size_t i = 0; i != N; ++i)
        cout << *(arr + i) << " ";
    cout << endl;
    return 0;    
}