#include "pch.h" 
#include "../MergeSort.cpp"
#include <vector>
#include <algorithm>
#include <random>

// --- TESTY PODSTAWOWE ---

TEST(MergeSortTest, AlreadySorted) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, ReverseSorted) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, RandomArray) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 10, 2, 8, 1, 5 };
    sorter.sort(arr);
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));
}

// --- OBS£UGA RÓ¯NYCH TYPÓW DANYCH (INT/DOUBLE) ---

TEST(MergeSortTest, NegativeNumbers) {
    MergeSort<int> sorter;
    std::vector<int> arr = { -5, -1, -10, -2 };
    std::vector<int> expected = { -10, -5, -2, -1 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, DoubleType) {
    MergeSort<double> sorter;
    std::vector<double> arr = { 3.5, 1.1, -2.2, 0.0 };
    std::vector<double> expected = { -2.2, 0.0, 1.1, 3.5 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// --- PRZYPADKI BRZEGOWE ---

TEST(MergeSortTest, EmptyArray) {
    MergeSort<int> sorter;
    std::vector<int> arr = {};
    ASSERT_NO_THROW(sorter.sort(arr)); // Testuje czy nie rzuca wyj¹tku
    EXPECT_TRUE(arr.empty());
}

TEST(MergeSortTest, SingleElement) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 42 };
    std::vector<int> expected = { 42 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST(MergeSortTest, Duplicates) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 3, 1, 3, 2, 1 };
    std::vector<int> expected = { 1, 1, 2, 3, 3 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// --- TESTY ZAAWANSOWANE I DU¯E DANE ---

TEST(MergeSortTest, MixedSignAndDuplicates) {
    MergeSort<int> sorter;
    std::vector<int> arr = { -2, 2, 0, -2, 5, 0 };
    std::vector<int> expected = { -2, -2, 0, 0, 2, 5 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

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