#include "pch.h" 
#include "../MergeSort.cpp"
#include <vector>
#include <algorithm>
#include <random>

/**
 * \file test.cpp
 * \brief Zestaw testów jednostkowych dla klasy `MergeSort<T>` przy u¿yciu Google Test.
 *
 * \details
 * Plik zawiera komplet testów sprawdzaj¹cych poprawnoœæ implementacji algorytmu sortowania przez scalanie
 * (`MergeSort<T>`) dla typów `int` i `double`. Testy obejmuj¹:
 *  - przypadki podstawowe (ju¿ posortowane, odwrotnie posortowane, losowe dane),
 *  - ró¿ne typy danych (int, double),
 *  - przypadki brzegowe (pusta tablica, pojedynczy element),
 *  - duplikaty i mieszane znaki,
 *  - test z du¿¹ tablic¹ (150 elementów).
 *
 * \note
 * - W tym przyk³adzie plik Ÿród³owy implementacji `MergeSort` jest includowany bezpoœrednio
 *   przez `#include "../MergeSort.cpp"`. Jest to podejœcie akceptowalne w zadaniach edukacyjnych,
 *   ale w projekcie produkcyjnym lepsze jest kompilowanie `MergeSort.cpp` w bibliotece i linkowanie jej.
 * - Jeœli implementacja `MergeSort` zostanie przeniesiona do innego projektu, upewnij siê, ¿e
 *   odpowiednie explicite instantiations lub definicje szablonu s¹ dostêpne dla typów u¿ywanych w testach.
 *
 * \author GitHub Copilot
 * \date grudnia 09, 2025
 */

/**
 * \test AlreadySorted
 * \brief Sprawdza, ¿e sortowanie pozostawia ju¿ posortowan¹ tablicê bez zmian.
 *
 * \pre arr zawiera {1,2,3,4,5}
 * \post arr pozostaje posortowana i równa expected
 * \remarks Test weryfikuje podstawow¹ poprawnoœæ sortowania i brak negatywnego wp³ywu na ju¿ posortowane dane.
 */
TEST(MergeSortTest, AlreadySorted) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * \test ReverseSorted
 * \brief Sprawdza, ¿e sortowanie poprawnie porz¹dkuje tablicê posortowan¹ malej¹co.
 *
 * \pre arr zawiera {5,4,3,2,1}
 * \post arr bêdzie posortowany rosn¹co
 */
TEST(MergeSortTest, ReverseSorted) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * \test RandomArray
 * \brief Weryfikuje, ¿e losowa tablica zostaje posortowana rosn¹co.
 *
 * \post std::is_sorted(arr.begin(), arr.end()) == true
 */
TEST(MergeSortTest, RandomArray) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 10, 2, 8, 1, 5 };
    sorter.sort(arr);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));
}

/**
 * \test NegativeNumbers
 * \brief Testuje sortowanie wartoœci ujemnych i mieszanych dodatnich/ujemnych.
 *
 * \pre arr zawiera wartoœci ujemne i dodatnie
 * \post arr jest posortowany rosn¹co, uwzglêdniaj¹c liczby ujemne
 */
TEST(MergeSortTest, NegativeNumbers) {
    MergeSort<int> sorter;
    std::vector<int> arr = { -5, -1, -10, -2 };
    std::vector<int> expected = { -10, -5, -2, -1 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * \test DoubleType
 * \brief Weryfikuje dzia³anie `MergeSort` dla typu `double`.
 *
 * \pre arr zawiera liczby zmiennoprzecinkowe (double)
 * \post arr jest posortowany rosn¹co z zachowaniem precyzji porównañ
 *
 * \note Porównania na typach zmiennoprzecinkowych zak³adaj¹, ¿e wartoœci w testach s¹ dok³adnie reprezentowalne.
 */
TEST(MergeSortTest, DoubleType) {
    MergeSort<double> sorter;
    std::vector<double> arr = { 3.5, 1.1, -2.2, 0.0 };
    std::vector<double> expected = { -2.2, 0.0, 1.1, 3.5 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * \test EmptyArray
 * \brief Upewnia siê, ¿e sortowanie pustej tablicy nie powoduje wyj¹tku i pozostawia j¹ pust¹.
 *
 * \post brak wyj¹tków, arr.empty() == true
 */
TEST(MergeSortTest, EmptyArray) {
    MergeSort<int> sorter;
    std::vector<int> arr = {};
    ASSERT_NO_THROW(sorter.sort(arr)); // Testuje czy nie rzuca wyj¹tku
    EXPECT_TRUE(arr.empty());
}

/**
 * \test SingleElement
 * \brief Sprawdza zachowanie dla tablicy zawieraj¹cej jeden element.
 *
 * \pre arr ma pojedynczy element
 * \post arr pozostaje niezmienione
 */
TEST(MergeSortTest, SingleElement) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 42 };
    std::vector<int> expected = { 42 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * \test Duplicates
 * \brief Testuje stabilnoœæ i poprawnoœæ sortowania przy duplikatach elementów.
 *
 * \pre arr zawiera powtarzaj¹ce siê wartoœci
 * \post arr jest poprawnie uporz¹dkowany rosn¹co, wszystkie duplikaty zachowane
 */
TEST(MergeSortTest, Duplicates) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 3, 1, 3, 2, 1 };
    std::vector<int> expected = { 1, 1, 2, 3, 3 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * \test MixedSignAndDuplicates
 * \brief Testuje przypadek mieszanych znaków oraz duplikatów w jednym zbiorze danych.
 *
 * \post arr jest posortowany rosn¹co, duplikaty zachowane i poprawnie umiejscowione
 */
TEST(MergeSortTest, MixedSignAndDuplicates) {
    MergeSort<int> sorter;
    std::vector<int> arr = { -2, 2, 0, -2, 5, 0 };
    std::vector<int> expected = { -2, -2, 0, 0, 2, 5 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

/**
 * \test LargeArray
 * \brief Test wydajnoœci/skalowalnoœci dla wiêkszego zbioru (150 elementów).
 *
 * \details
 * Generujemy 150 elementów w porz¹dku malej¹cym i oczekujemy, ¿e:
 * - rozmiar tablicy pozostanie 150,
 * - tablica bêdzie posortowana rosn¹co,
 * - pierwszy element==1, ostatni element==150.
 *
 * \post arr.size()==150, arr[0]==1, arr[149]==150
 */
TEST(MergeSortTest, LargeArray) {
    MergeSort<int> sorter;
    std::vector<int> arr;
    // Generowanie du¿ej tablicy (150 elementów malej¹co)
    for (int i = 150; i > 0; i--) arr.push_back(i);

    sorter.sort(arr);

    EXPECT_EQ(arr.size(), 150);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[149], 150);
}