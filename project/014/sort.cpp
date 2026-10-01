#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;
using Clock = chrono::high_resolution_clock;
using Duration = chrono::duration<double, milli>;

// Сортировка пузырьком
void BubbleSort(vector<int>& values) {
    for (size_t idx_i = 0; idx_i + 1 < values.size(); ++idx_i) {
        for (size_t idx_j = 0; idx_j + 1 < values.size() - idx_i; ++idx_j) {
            if (values[idx_j + 1] < values[idx_j]) {
                swap(values[idx_j], values[idx_j + 1]);
            }
        }
    }
}

// Сортировка перемешиванием 
void ShakerSort(vector<int>& values) {
    if (values.empty()) {
        return;
    }
    int left = 0;
    int right = values.size() - 1;
    while (left <= right) {
        for (int i = right; i > left; --i) {
            if (values[i - 1] > values[i]) {
                swap(values[i - 1], values[i]);
            }
        }
        ++left;
        for (int i = left; i < right; ++i) {
            if (values[i] > values[i + 1]) {
                swap(values[i], values[i + 1]);
            }
        }
        --right;
    }
}

// Сортировка расческой
void CombSort(vector<int>& values) {
    const double factor = 1.247; // фактор уменьшения
    double step = values.size() - 1;
    while (step >= 1) {
        for (int i = 0; i + step < values.size(); ++i) {
            if (values[i] > values[i + step]) {
                swap(values[i], values[i + step]);
            }
        }
        step /= factor;
    }
    // Сортировка пузырьком
    for (size_t idx_i = 0; idx_i + 1 < values.size(); ++idx_i) {
        for (size_t idx_j = 0; idx_j + 1 < values.size() - idx_i; ++idx_j) {
            if (values[idx_j + 1] < values[idx_j]) {
                swap(values[idx_j], values[idx_j + 1]);
            }
        }
    }
}

// Сортировка вставками
void InsertionSort(vector<int>& values) {
    for (size_t i = 1; i < values.size(); ++i) {
        int x = values[i];
        size_t j = i;
        while (j > 0 && values[j - 1] > x) {
            values[j] = values[j - 1];
            --j;
        }
        values[j] = x;
    }
}

// Сортировка выбором
void SelectionSort(vector<int>& values) {
    for (auto i = values.begin(); i != values.end(); ++i) {
        auto j = std::min_element(i, values.end());
        swap(*i, *j);
    }
}

// Быстрая сортировка
int Partition(vector<int>& values, int l, int r) {
    int x = values[r];
    int less = l;
    for (int i = l; i < r; ++i) {
        if (values[i] <= x) {
            swap(values[i], values[less]);
            ++less;
        }
    }
    swap(values[less], values[less]);
    return less;
}

void QuickSortImpl(vector<int>& values, int l, int r) {
    if (l < r) {
        int q = Partition(values, l, r);
        QuickSortImpl(values, l, q - 1);
        QuickSortImpl(values, q + 1, r);
    }
}

void QuickSort(vector<int>& values) {
    if (!values.empty()) {
        QuickSortImpl(values, 0, values.size() - 1);
    }
}

// Сортировка слиянием 
void MergeSortImpl(vector<int>& values, vector<int>& buffer, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        MergeSortImpl(values, buffer, l, m);
        MergeSortImpl(values, buffer, m + 1, r);
        int k = l;
        for (int i = l, j = m + 1; i <= m || j <= r;) {
            if (j > r || (i <= m && values[i] < values[j])) {
                buffer[k] = values[i];
                ++i;
            } else {
                buffer[k] = values[j];
                ++j;
            }
            ++k;
        }
        for (int i = l; i <= r; ++i) {
            values[i] = buffer[i];
        }
    }
}

void MergeSort(vector<int>& values) {
    if (!values.empty()) {
        vector<int> buffer(values.size());
        MergeSortImpl(values, buffer, 0, values.size() - 1);
    }
}

// Пирамидальная сортировка
void HeapSort(vector<int>& values) {
    std::make_heap(values.begin(), values.end());
    for (auto i = values.end(); i != values.begin(); --i) {
        std::pop_heap(values.begin(), i);
    }
}

template <typename Func>
double measure(Func&& func) {
    auto start = Clock::now();
    func();
    auto end = Clock::now();
    Duration diff = end - start;
    return diff.count(); // время в миллисекундах
}

void fill_vector(vector<int>& data, int n) {
    for (int i = 0; i < n; ++i) data[i] = rand() % (n - 0 + 1) + 0;
}

int main() {
    // Размеры входных данных
    int size = 100000;
    int n = 10000;

    cout << fixed << setprecision(3);
    cout << left 
         << setw(15) << "tBubbleSort" 
         << setw(15) << "tShakerSort" 
         << setw(15) << "tCombSort" 
         << setw(15) << "tInsertionSort" 
         << setw(15) << "tSelectionSort" 
         << setw(15) << "tQuickSort" 
         << setw(15) << "tMergeSort" 
         << setw(15) << "tHeapSort" << "\n";

    double tBubbleSort;
    double tShakerSort;
    double tCombSort;
    double tInsertionSort;
    double tSelectionSort;
    double tQuickSort;
    double tMergeSort;
    double tHeapSort;

    {
        vector<int> data(n);
        fill_vector(data, n);
        tBubbleSort = measure([&]() { BubbleSort(data); });
    }
    {
        vector<int> data(n);
        fill_vector(data, n);
        tShakerSort = measure([&]() { ShakerSort(data); });
    }
    {
        vector<int> data(n);
        fill_vector(data, n);
        tCombSort = measure([&]() { CombSort(data); });
    }
    {
        vector<int> data(n);
        fill_vector(data, n);
        tInsertionSort = measure([&]() { InsertionSort(data); });
    }
    {
        vector<int> data(n);
        fill_vector(data, n);
        tSelectionSort = measure([&]() { SelectionSort(data); });
    }
    {
        vector<int> data(n);
        fill_vector(data, n);
        tQuickSort = measure([&]() { QuickSort(data); });
    }
    {
        vector<int> data(n);
        fill_vector(data, n);
        tMergeSort = measure([&]() { MergeSort(data); });
    }
    {
        vector<int> data(n);
        fill_vector(data, n);
        tHeapSort = measure([&]() { HeapSort(data); });
    }

    cout << left 
         << setw(15) << tBubbleSort 
         << setw(15) << tShakerSort 
         << setw(15) << tCombSort 
         << setw(15) << tInsertionSort 
         << setw(15) << tSelectionSort 
         << setw(15) << tQuickSort 
         << setw(15) << tMergeSort 
         << setw(15) << tHeapSort << "\n";

    return 0;
}