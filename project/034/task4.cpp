#include <iostream>

using namespace std;

int main() {
    int a[6] = {1, 2, 3, 4, 5, 6};
    int& ref1 = *a;
    int& ref6 = *(a + 5);
    
    for(int* ptr = &ref1; ptr <= &ref6; ++ptr){
        *ptr = (*ptr) * (*ptr); 
    }

    for(int* ptr = &ref1; ptr <= &ref6; ++ptr) {
        cout << *ptr << " ";
    }

    return 0;
}