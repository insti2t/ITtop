#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 10;
double arr[SIZE];

int main() {
    //ВВОД
    cout << "Введите элементы" << endl;
    for (size_t i=0; i != SIZE; ++i) {
        cout << "№ " << i << ": ";
        cin >> arr[i];
    }

    //Поиск наибольшего элемента, его индекса
    //и суммы элементов
    double max_element = arr[0];
    size_t index_of_max = 0;
    double sum_of_el = 0.0;
    for (size_t i=0; i != SIZE; ++i) {
        if (arr[i] > max_element) {
            max_element = arr[i];
            index_of_max = i;
        }
        sum_of_el += arr[i];
    }
    cout << "Наибольший элемент: " << max_element 
        << ", его индекс: " << index_of_max 
        << endl << "Сумма элементов: "
        << sum_of_el << endl;

    //Сортировка пузырьком
    for(size_t i = SIZE; i != 0; --i)
        for(size_t j = 0; j != i - 1; ++j)
            if(arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);

    //Вывод отсортированного массива на экран (консоль)
    cout << "Отсортированный массив: \n";
    for (double element : arr)
        cout << element << " ";
        cout << endl;
}