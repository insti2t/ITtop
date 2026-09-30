#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;
using Clock = chrono::high_resolution_clock;
using Duration = chrono::duration<double, milli>;

// 0(1): Константное время - это доступ по индексу
double constant_time(const vector<int>& v) {
    if (v.empty()) return 0;
    volatile int x = v[0]; // volatile чтобы компилятор не оптимизировал чтение
    return x;
}
    
// 0(log n): бинарный поиск (массив должен быть отсорчен)
bool logarithmic_time(const vector<int>& v, int target) {
    int l = 0, r = static_cast<int>(v.size()) - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (v[mid] == target) return true;
        else if (v[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}

// 0(n): линейный проход - сумма элементов
long long linear_time(const vector<int>& v) {
    long long sum = 0;
    for (int x : v) sum += x;
    return sum;
}

// 0(n log n): сортировка (в среднем и худшем случае - 0(n log n))
void n_log_n_time(vector<int>& v) {
    sort(v.begin(), v.end());
}

// 0(n^2): проверка дубликатов (два вложенных цикла)
bool quadratic_time(const vector<int>& v) {
    size_t n = v.size();
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            if (v[i] == v[j]) return true;
        }
    }
    return false;
}

template <typename Func>
double measure(Func&& func) {
    auto start = Clock::now();
    func();
    auto end = Clock::now();
    Duration diff = end - start;
    return diff.count(); // время в миллисекундах
}

int main() {
    vector<size_t> sizes = {10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};

cout << fixed << setprecision(3);
cout << left << setw(10) << "N"
    << setw(15) << "O(1)"
    << setw(15) << "O(log n)"
    << setw(15) << "O(n)"
    << setw(15) << "O(n log n)"
    << setw(15) << "O(n^2)" << "\n";

    for (size_t n : sizes) {
        vector<int> data1(1);
        int r1 = rand() % (n - 0 + 1) + 0;
        for (int i = 0; i < n; ++i) data1.push_back(r1);

        double t_const = measure([&]() { constant_time(data1); } );

        vector<int> data2(n);
        for (int i = 0; i < n; ++i) data2.push_back(i);

        double t_log = measure([&]() { logarithmic_time(data2, 0); } );

        vector<int> data3(n);
        int r3 = rand() % (n - 0 + 1) + 0;
        for (int i = 0; i < n; ++i) data3.push_back(r3);

        double t_lin = measure([&]() { linear_time(data3); } );

        vector<int> data4(n);
        int r4 = rand() % (n - 0 + 1) + 0;
        for (int i = 0; i < n; ++i) data4.push_back(r4);

        double t_nlogn = measure([&]() { n_log_n_time(data4); } );

        vector<int> data5(n);
        for (int i = 0; i < n; ++i) data5[i] = i;

        double t_quad = measure([&]() { quadratic_time(data5); } );

        cout << left << setw(10) << n
            << setw(15) << t_const
            << setw(15)  << t_log
            << setw(15)  << t_lin
            << setw(15)  << t_nlogn
            << setw(15)  << t_quad << "\n";
    }
    return 0;
}