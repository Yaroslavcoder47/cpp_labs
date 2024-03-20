#include "pch.h"
#include "../task1/task1.h"
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
