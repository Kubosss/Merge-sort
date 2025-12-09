#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

/**
 * @file MergeSort.h
 * @brief Deklaracja szablonu klasy MergeSort do sortowania wektorów.
 *
 * Klasa realizuje stabilny algorytm sortowania typu merge sort (scalanie).
 * Definicje metod znajduj¹ siê w pliku implementacyjnym `MergeSort.cpp`.
 *
 * @tparam T Typ elementów przechowywanych w wektorze; musi wspieraæ operator<=.
 */
template <typename T>
class MergeSort {
private:
    /**
     * @brief Scalanie dwóch posortowanych podtablic w jedn¹ posortowan¹.
     *
     * Metoda scala elementy z przedzia³ów [left, mid] oraz [mid+1, right]
     * wewn¹trz dostarczonego wektora `arr` w porz¹dku niemalej¹cym.
     *
     * Wymagania:
     * - Indeksy `left`, `mid`, `right` musz¹ spe³niaæ: 0 <= left <= mid < right < arr.size()
     * - Elementy typu T musz¹ mieæ zdefiniowany operator<=
     *
     * Z³o¿onoœæ czasowa: O(n) gdzie n = right - left + 1
     * Z³o¿onoœæ pamiêciowa: O(n) dodatkowej pamiêci (tymczasowe wektory L i R)
     *
     * Stabilnoœæ: algorytm zachowuje stabilnoœæ (elementy równe zachowuj¹
     * oryginaln¹ kolejnoœæ wzglêdem siebie).
     *
     * @param arr Referencja do wektora, którego elementy maj¹ byæ scalone.
     * @param left Indeks pocz¹tku pierwszego podzbioru (w³¹cznie).
     * @param mid Indeks koñca pierwszego podzbioru (w³¹cznie).
     * @param right Indeks koñca drugiego podzbioru (w³¹cznie).
     */
    void merge(std::vector<T>& arr, int left, int mid, int right);

    /**
     * @brief Rekurencyjna metoda dziel¹ca oraz wywo³uj¹ca scalanie.
     *
     * Metoda implementuje podejœcie "dziel i zwyciê¿aj":
     * 1. Dzieli zakres [left, right] na dwie po³owy.
     * 2. Rekurencyjnie sortuje obie po³owy.
     * 3. Scala obie posortowane po³owy wywo³uj¹c `merge`.
     *
     * Warunki i uwagi:
     * - Jeœli left >= right, zakres zawiera 0 lub 1 element i jest traktowany
     *   jako ju¿ posortowany (warunek zakoñczenia rekursji).
     * - Maksymalna g³êbokoœæ rekurencji wynosi O(log n).
     *
     * @param arr Referencja do wektora poddawanego sortowaniu.
     * @param left Indeks pocz¹tku przetwarzanego zakresu.
     * @param right Indeks koñca przetwarzanego zakresu.
     */
    void sortRecursive(std::vector<T>& arr, int left, int right);

public:
    /**
     * @brief Konstruktor domyœlny klasy MergeSort.
     *
     * Obiekt klasy nie przechowuje stanu pomiêdzy wywo³aniami sortowania,
     * dlatego konstruktor domyœlny jest wystarczaj¹cy.
     */
    MergeSort() = default;

    /**
     * @brief Publiczna metoda sortuj¹ca wektor.
     *
     * Sprawdza czy wektor nie jest pusty, po czym wywo³uje metodê rekurencyjn¹
     * rozpoczynaj¹c sortowanie ca³ego zakresu.
     *
     * Z³o¿onoœæ czasowa: O(n log n) w najgorszym i œrednim przypadku.
     * Z³o¿onoœæ pamiêciowa: O(n) dodatkowej pamiêci.
     *
     * @param arr Referencja do wektora, który ma zostaæ posortowany w miejscu.
     */
    void sort(std::vector<T>& arr);
};

#endif // MERGESORT_H