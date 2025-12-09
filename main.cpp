#include <iostream>
#include <vector>
#include "MergeSort.h"

/**
 * @file main.cpp
 * @brief Prosty przykład użycia klasy MergeSort z demonstracją działania.
 *
 * Plik zawiera funkcję pomocniczą `printArray` do wypisywania zawartości
 * wektora oraz funkcję `main`, która demonstruje sortowanie wektorów typów
 * `int` oraz `double` przy użyciu szablonu `MergeSort<T>`.
 *
 * Cel:
 * - Zaprezentować użycie klasy `MergeSort` w praktycznym przykładzie.
 * - Umożliwić szybkie ręczne testy oraz obserwację stabilności i poprawności
 *   sortowania.
 */

/**
 * @brief Wypisuje elementy wektora na standardowe wyjście.
 *
 * Funkcja pomocnicza używana jedynie dla celów demonstracyjnych w `main`.
 * Elementy są wypisywane w jednej linii, rozdzielone spacjami, a następnie
 * kończone znakiem nowej linii.
 *
 * @tparam T Typ elementów wektora; powinien mieć zdefiniowany operator<<.
 * @param arr Stała referencja do wektora do wypisania.
 */
template <typename T>
void printArray(const std::vector<T>& arr) {
    for (const auto& val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Punkt wejścia programu demonstrujący Merge Sort.
 *
 * Program:
 * 1. Tworzy przykładowe wektory `int` i `double`.
 * 2. Wypisuje zawartość przed sortowaniem.
 * 3. Wywołuje `MergeSort<T>::sort` aby posortować wektory w miejscu.
 * 4. Wypisuje zawartość po sortowaniu.
 *
 * Uwaga:
 * - Program jest demonstracją i nie obsługuje wejścia z linii poleceń.
 * - Aby testować inne typy, należy dodać jawne instancje szablonu w
 *   `MergeSort.cpp` (np. `template class MergeSort<float>;`) lub przenieść
 *   definicje do nagłówka.
 *
 * @return Zwraca 0 w przypadku poprawnego zakończenia.
 */
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