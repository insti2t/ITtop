#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru-RU");
    double a;
    double b;
    double c;
    cout << "Введите 3 оценки последовательно по предметам от 0 до 100" << endl;
    cin >> a;
    cin >> b;
    cin >> c;
    if((a <= 100 && a > 0) && (b <= 100 && b > 0) && (c <= 100 && c > 0)) {
            double score = (a + b + c) / 3;
            string grade = (score >= 90) ? "ботаник" :
                (score >= 75) ? "норм чел" :
                (score >= 60) ? "троечник" : "дебил" ;

            cout << fixed << setprecision(1);
            cout << "Средний бал: " << score << " и ты " << grade << endl;
            return 0;
        }
    else{
        cout << "Ошибка в значениях ОЦЕНКА!" << endl;
        return 0;
    }
    return 0;
}
