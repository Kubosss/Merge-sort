#include "MergeSort.h"
#include <vector>

// Implementacja metody merge
template <typename T>
void MergeSort<T>::merge(std::vector<T>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<T> L(n1);
    std::vector<T> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Implementacja metody rekurencyjnej
template <typename T>
void MergeSort<T>::sortRecursive(std::vector<T>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        sortRecursive(arr, left, mid);
        sortRecursive(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Implementacja metody publicznej sort
template <typename T>
void MergeSort<T>::sort(std::vector<T>& arr) {
    if (arr.empty()) return;
    sortRecursive(arr, 0, arr.size() - 1);
}

// ============================================================
// JAWNA INSTANCJACJA (EXPLICIT INSTANTIATION)
// To jest konieczne, aby linker widzia³ te typy przy podziale na .h i .cpp
// ============================================================
template class MergeSort<int>;
template class MergeSort<double>;
// Jeœli bêdziesz potrzebowa³ float, dopisz: template class MergeSort<float>;