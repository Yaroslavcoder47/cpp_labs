#include "pch.h"
#include "../task1/task1.h"
#include "../task1/task2.h"
#include "spdlog/spdlog.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(Task1Test, TestCase1) {
	std::vector <int> vec = { 4, 1, 1, 1, 1 };
	int* ptrArr = vec.data();
	vectorRebuild(ptrArr);
	EXPECT_EQ(vec[0], 1);
	EXPECT_EQ(vec[1], 1);
}

TEST(Task1Test, TestCase2) {
	std::vector <int> vec = { 4, 1, 2, 3, 4 };
	int* ptrArr = vec.data();
	vectorRebuild(ptrArr);
	EXPECT_EQ(vec[0], 4);
	EXPECT_EQ(vec[1], 1);
	EXPECT_EQ(vec[2], 2);
	EXPECT_EQ(vec[3], 3);
	EXPECT_EQ(vec[4], 4);
}

TEST(Task1Test, TestCase3) {
	std::vector <int> vec = { 4, 1, 2, 2, 1 };
	int* ptrArr = vec.data();
	vectorRebuild(ptrArr);
	EXPECT_EQ(vec[0], 2);
	EXPECT_EQ(vec[1], 1);
	EXPECT_EQ(vec[2], 2);
}

TEST(Task1Test, TestCase4) {
	std::vector <int> vec = { 1, 2 };
	int* ptrArr = vec.data();
	vectorRebuild(ptrArr);
	EXPECT_EQ(vec[0], 1);
	EXPECT_EQ(vec[1], 2);
}

//Task 2
TEST(Task2Test, TestCase1) {
	std::vector<int> a = { 1, 2, 5, 8 };
	std::vector<int> b = { 2, 4, 6 };
	std::vector<int> result = mergeArrays(a.data(), b.data(), a.size(), b.size());
	std::vector<int> expectedRes = { 1, 2, 2, 4, 5, 6, 8 };
	for (size_t i = 0; i < result.size(); ++i) {
		EXPECT_EQ(result[i], expectedRes[i]);
	}
}

TEST(Task2Test, TestCase2) {
	std::vector<int> a = { 1, 2, 5, 8 };
	std::vector<int> b = { 3, 4, 6 };
	std::vector<int> result = mergeArrays(a.data(), b.data(), a.size(), b.size());
	std::vector<int> expectedRes = { 1, 2, 3, 4, 5, 6, 8 };
	for (size_t i = 0; i < result.size(); ++i) {
		EXPECT_EQ(result[i], expectedRes[i]);
	}	
}

TEST(Task2Test, TestCase3) {
	std::vector<int> a = { 1 };
	std::vector<int> b = { 2 };
	std::vector<int> result = mergeArrays(a.data(), b.data(), a.size(), b.size());
	std::vector<int> expectedRes = { 1, 2 };
	for (size_t i = 0; i < result.size(); ++i) {
		EXPECT_EQ(result[i], expectedRes[i]);
	}
}