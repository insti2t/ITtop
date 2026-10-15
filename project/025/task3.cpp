#include <iostream>

using namespace std;

int main(){
    cout << "Type char 1 to 10" << endl;
    int x;
    cin >> x;
    int o;

    for (int i = 0; i < 11; i++) 
    {
        if(i == 11){
            break;
        }
        else {
        cout << x << " * " << i << " = " << x*i << endl;
        o += x*i;
        }
    }
    return 0;
}