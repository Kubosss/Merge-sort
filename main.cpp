#include <iostream>
#include <vector>
#include "MergeSort.h"

// Funkcja pomocnicza do wyświetlania wektora
template <typename T>
void printArray(const std::vector<T>& arr) {
    for (const auto& val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "=== DEMONSTRACJA ALGORYTMU MERGE SORT ===" << std::endl;

    // --- Przypadek 1: Liczby całkowite (int) ---
    std::cout << "\n1. Sortowanie tablicy int:" << std::endl;
    std::vector<int> tablicaInt = { 12, 7, 14, 9, 10, 11, -5, 0 };
    MergeSort<int> sorterInt;

    std::cout << "Przed: ";
    printArray(tablicaInt);

    sorterInt.sort(tablicaInt);

    std::cout << "Po:    ";
    printArray(tablicaInt);

    // --- Przypadek 2: Liczby zmiennoprzecinkowe (double) ---
    std::cout << "\n2. Sortowanie tablicy double:" << std::endl;
    std::vector<double> tablicaDouble = { 3.14, 1.59, 2.65, 5.35, 0.11, -2.5 };
    MergeSort<double> sorterDouble;

    std::cout << "Przed: ";
    printArray(tablicaDouble);

    sorterDouble.sort(tablicaDouble);

    std::cout << "Po:    ";
    printArray(tablicaDouble);

    return 0;
}