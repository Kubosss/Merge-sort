#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

template <typename T>
class MergeSort {
private:
    // Deklaracja metody scalaj¹cej
    void merge(std::vector<T>& arr, int left, int mid, int right);

    // Deklaracja metody rekurencyjnej
    void sortRecursive(std::vector<T>& arr, int left, int right);

public:
    // Konstruktor
    MergeSort() = default;

    // G³ówna metoda sortuj¹ca
    void sort(std::vector<T>& arr);
};

#endif // MERGESORT_H