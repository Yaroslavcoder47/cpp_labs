#include "pch.h"
#include <vector>
#include "../Sorting/sorting_algorithms.h"
#include <iostream>

TEST(SortingTest, BubbleSortTest) {
	std::vector <int> list = { 1 };
	std::vector <int> listSorted = { 1 };
	bubbleSort(list);
	EXPECT_EQ(list, listSorted);

	list = { 2, 1 };
	listSorted = { 1, 2 };
	bubbleSort(list);
	EXPECT_EQ(list, listSorted);

	list = { 8, 1, 4, 5, 6, 2, 0, 3, 7 };
	listSorted = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	bubbleSort(list);
	EXPECT_EQ(list, listSorted);
}

TEST(SortingTest, InsertionSortTest) {
	std::vector <int> list = { 1 };
	std::vector <int> listSorted = { 1 };
	insertionSort(list);
	EXPECT_EQ(list, listSorted);

	list = { 2, 1 };
	listSorted = { 1, 2 };
	insertionSort(list);
	EXPECT_EQ(list, listSorted);

	list = { 8, 1, 4, 5, 6, 2, 0, 3, 7 };
	listSorted = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	insertionSort(list);
	EXPECT_EQ(list, listSorted);
}

TEST(SortingTest, ShellSortTest) {
	std::vector <int> list = { 1 };
	std::vector <int> listSorted = { 1 };
	shellSort(list);
	EXPECT_EQ(list, listSorted);

	list = { 2, 1 };
	listSorted = { 1, 2 };
	shellSort(list);
	EXPECT_EQ(list, listSorted);

	list = { 8, 1, 4, 5, 6, 2, 0, 3, 7 };
	listSorted = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	shellSort(list);
	EXPECT_EQ(list, listSorted);
}

TEST(SortingTest, oddEvenSortTest) {
	std::vector <int> list = { 1 };
	std::vector <int> listSorted = { 1 };
	oddEvenSort(list);
	EXPECT_EQ(list, listSorted);

	list = { 2, 1 };
	listSorted = { 1, 2 };
	oddEvenSort(list);
	EXPECT_EQ(list, listSorted);

	list = { 8, 1, 4, 5, 6, 2, 0, 3, 7 };
	listSorted = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	oddEvenSort(list);
	EXPECT_EQ(list, listSorted);
}

TEST(SortingTest, cocktailSortTest) {
	std::vector <int> list = { 1 };
	std::vector <int> listSorted = { 1 };
	cocktailSort(list);
	EXPECT_EQ(list, listSorted);

	list = { 2, 1 };
	listSorted = { 1, 2 };
	cocktailSort(list);
	EXPECT_EQ(list, listSorted);

	list = { 8, 1, 4, 5, 6, 2, 0, 3, 7 };
	listSorted = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	cocktailSort(list);
	EXPECT_EQ(list, listSorted);
}

TEST(SortingTest, combSortTest) {
	std::vector <int> list = { 1 };
	std::vector <int> listSorted = { 1 };
	combSort(list);
	EXPECT_EQ(list, listSorted);

	list = { 2, 1 };
	listSorted = { 1, 2 };
	combSort(list);
	EXPECT_EQ(list, listSorted);

	list = { 8, 1, 4, 5, 6, 2, 0, 3, 7 };
	listSorted = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	combSort(list);
	EXPECT_EQ(list, listSorted);
}

TEST(SortingTest, SelectionSortTest) {
	std::vector <int> list = { 1 };
	std::vector <int> listSorted = { 1 };
	selectionSort(list);
	EXPECT_EQ(list, listSorted);

	list = { 2, 1 };
	listSorted = { 1, 2 };
	selectionSort(list);
	EXPECT_EQ(list, listSorted);

	list = { 8, 1, 4, 5, 6, 2, 0, 3, 7 };
	listSorted = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	selectionSort(list);
	EXPECT_EQ(list, listSorted);
}

TEST(SortingTest, doubleSelectionSortTest) {
	std::vector <int> list = { 1 };
	std::vector <int> listSorted = { 1 };
	doubleSelectionSort(list);
	EXPECT_EQ(list, listSorted);

	list = { 2, 1 };
	listSorted = { 1, 2 };
	doubleSelectionSort(list);
	EXPECT_EQ(list, listSorted);

	list = { 8, 1, 4, 5, 6, 2, 0, 3, 7 };
	listSorted = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	doubleSelectionSort(list);
	EXPECT_EQ(list, listSorted);
}

TEST(SortingTest, quickSortTest) {
	std::vector <int> list = { 1 };
	std::vector <int> listSorted = { 1 };
	quickSort(list);
	EXPECT_EQ(list, listSorted);

	list = { 2, 1 };
	listSorted = { 1, 2 };
	quickSort(list);
	EXPECT_EQ(list, listSorted);

	list = { 8, 1, 4, 5, 6, 2, 0, 3, 7 };
	listSorted = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	quickSort(list);
	EXPECT_EQ(list, listSorted);
}

TEST(SortingTest, mergeSortTest) {
	std::vector <int> list = { 1 };
	std::vector <int> listSorted = { 1 };
	mergeSort(list);
	EXPECT_EQ(list, listSorted);

	list = { 2, 1 };
	listSorted = { 1, 2 };
	mergeSort(list);
	EXPECT_EQ(list, listSorted);

	list = { 8, 1, 4, 5, 6, 2, 0, 3, 7 };
	listSorted = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	mergeSort(list);
	EXPECT_EQ(list, listSorted);
}