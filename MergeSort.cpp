#include "MergeSort.h"
#include <vector>

/**
 * @file MergeSort.cpp
 * @brief Implementacje metod szablonu MergeSort.
 *
 * UWAGA: Ze wzglêdu na implementacjê w osobnym pliku .cpp, na koñcu pliku
 * znajduj¹ siê jawne instancjacje szablonu dla typów u¿ywanych w projekcie
 * (np. int, double). Dziêki temu linker widzi wygenerowane instancje.
 */

 /**
  * @brief Scalanie dwóch posortowanych fragmentów wektora.
  *
  * Implementacja:
  * - Tworzy tymczasowe wektory `L` i `R` zawieraj¹ce elementy z przedzia³ów
  *   [left, mid] oraz [mid+1, right].
  * - Nastêpnie przechodzi po obu wektorach tymczasowych i kopiuje mniejszy
  *   element z powrotem do `arr`, zachowuj¹c stabilnoœæ (jeœli elementy s¹
  *   równe, preferowany jest element z lewej czêœci).
  *
  * Przyk³ad:
  * @code
  * std::vector<int> v = {1,3,5, 2,4,6};
  * merge(v, 0, 2, 5); // wynik: {1,2,3,4,5,6}
  * @endcode
  *
  * @tparam T Typ elementów (musi wspieraæ operator<=).
  * @param arr Referencja do wektora, w którym wykonujemy scalanie.
  * @param left Indeks pocz¹tku pierwszego podzbioru (w³¹cznie).
  * @param mid Indeks koñca pierwszego podzbioru (w³¹cznie).
  * @param right Indeks koñca drugiego podzbioru (w³¹cznie).
  */
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

    // Scalanie: porównujemy elementy i kopiujemy mniejszy,
    // przy równych wartoœciach wybieramy lew¹ stronê (stabilnoœæ).
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

    // Skopiuj pozosta³e elementy z L (jeœli istniej¹)
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Skopiuj pozosta³e elementy z R (jeœli istniej¹)
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/**
 * @brief Rekurencyjne sortowanie przez scalanie.
 *
 * Metoda dzieli zakres [left, right] na dwie czêœci, sortuje je rekurencyjnie
 * i scala wyniki. Gdy left >= right oznacza to zakres o d³ugoœci 0 lub 1 —
 * traktowany jako ju¿ posortowany.
 *
 * @tparam T Typ elementów.
 * @param arr Referencja do wektora sortowanego.
 * @param left Indeks pocz¹tku zakresu do posortowania.
 * @param right Indeks koñca zakresu do posortowania.
 */
template <typename T>
void MergeSort<T>::sortRecursive(std::vector<T>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        sortRecursive(arr, left, mid);
        sortRecursive(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

/**
 * @brief Publiczna metoda uruchamiaj¹ca sortowanie.
 *
 * Sprawdza przypadek pustego wektora (nie ma nic do zrobienia), a nastêpnie
 * inicjuje rekurencyjne sortowanie ca³ego zakresu.
 *
 * @tparam T Typ elementów.
 * @param arr Referencja do wektora, który zostanie posortowany.
 */
template <typename T>
void MergeSort<T>::sort(std::vector<T>& arr) {
    if (arr.empty()) return;
    sortRecursive(arr, 0, static_cast<int>(arr.size()) - 1);
}

// ============================================================
// JAWNA INSTANCJACJA (EXPLICIT INSTANTIATION)
// To jest konieczne, aby linker widzia³ te typy przy podziale na .h i .cpp
// Dodaj kolejne instancje, jeœli bêdziesz u¿ywaæ MergeSort z innymi typami.
// ============================================================
template class MergeSort<int>;
template class MergeSort<double>;
// Jeœli bêdziesz potrzebowa³ float, dopisz: template class MergeSort<float>;