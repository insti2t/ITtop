#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru-RU.UTF-8");
    srand(time(nullptr));

    int arr[8] = {};
    for (int i = 0; i < 8; i++) {
        *(arr + i) = rand() % 100; 
        cout << *(arr + i) << " ";
    }

    cout << endl << "Сорт" << endl;
    
    swap(*(arr), *(arr + 7));
    swap(*(arr + 1), *(arr + 6)); 
    swap(*(arr + 2), *(arr + 5));
    swap(*(arr + 3), *(arr + 4));
    
    for (int o = 0; o < 8; o++) {
        cout << *(arr + o) << " ";
    }
    return 0;

}