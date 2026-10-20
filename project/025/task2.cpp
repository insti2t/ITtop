#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru-RU"); // dont work

    int pass = 1122;
    cout << "Password has 4 chars" << endl;

    int tru;
    int count = 0;
    do{
        cout << "Type your attempt: " << endl;
        cin >> tru;
        if(tru == pass){
            ++count;
            cout << "Hack complete!" << endl;
            cout << "Count attempts: " << count << endl;
        }
        else {
            ++count;
            cout << "Try again!" << endl;
        }
        


    } while (tru != pass);
    return 0;
}