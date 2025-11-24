#include "pch.h"
#include "..\MergeSort.h"
#include <vector>
#include <algorithm>

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

    // Sprawdzamy za pomoc¹ funkcji bibliotecznej STL
    EXPECT_TRUE(std::is_sorted(arr.begin(), arr.end()));
    EXPECT_EQ(arr.size(), 5);
}