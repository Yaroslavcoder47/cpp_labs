#include <iostream>
#include <utility>
#include "pch.h"
#include "../SimpleTasks/task1.cpp"
#include "../SimpleTasks/task2.cpp"
#include "../SimpleTasks/task3.cpp"
#include "../SimpleTasks/task4.cpp"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

auto loggerTest = spdlog::basic_logger_mt("Lab03_test", "../Logs/Lab03Logger.txt");
TEST(TestCaseName, TestName) {
	loggerTest->set_level(spdlog::level::debug);
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(TestFirstTask, task1Test1) {
	loggerTest.get()->debug("Test 1 of task 1 function");
	std::pair<int, int> resultPair = task1(1025);
	std::pair<int, int> expectedtPair(2, 1);
	EXPECT_EQ(resultPair.first, expectedtPair.first);
	EXPECT_EQ(resultPair.second, expectedtPair.second);
}

TEST(TestFirstTask, task1Test2) {
	loggerTest.get()->debug("Test 2 of task 1 function");
	std::pair<int, int> resultPair = task1(137);
	std::pair<int, int> expectedtPair(0, 0);
	EXPECT_EQ(resultPair.first, expectedtPair.first);
	EXPECT_EQ(resultPair.second, expectedtPair.second);
}

TEST(TestFirstTask, task1Test3) {
	loggerTest.get()->debug("Test 3 of task 1 function");
	std::pair<int, int> resultPair = task1(24002);
	std::pair<int, int> expectedtPair(5, 2);
	EXPECT_EQ(resultPair.first, expectedtPair.first);
	EXPECT_EQ(resultPair.second, expectedtPair.second);
}

TEST(TestSecondTask, task2Test1) {
	loggerTest.get()->debug("Test 1 of task 2 function");
	std::pair<int, int> resultPair = task2(4, 8);
	std::pair<int, int> expectedtPair(1, 2);
	EXPECT_EQ(resultPair.first, expectedtPair.first);
	EXPECT_EQ(resultPair.second, expectedtPair.second);
}

TEST(TestSecondTask, task2Test2) {
	loggerTest.get()->debug("Test 2 of task 2 function");
	std::pair<int, int> resultPair = task2(-3, 9);
	std::pair<int, int> expectedtPair(-1, 3);
	EXPECT_EQ(resultPair.first, expectedtPair.first);
	EXPECT_EQ(resultPair.second, expectedtPair.second);
}

TEST(TestSecondTask, task2Test3) {
	loggerTest.get()->debug("Test 3 of task 2 function");
	std::pair<int, int> resultPair = task2(5, 7);
	std::pair<int, int> expectedtPair(5, 7);
	EXPECT_EQ(resultPair.first, expectedtPair.first);
	EXPECT_EQ(resultPair.second, expectedtPair.second);
}

TEST(TestThirdTask, task3Test1) {
	loggerTest.get()->debug("Test 1 of task 3 function");
	int result = task3(5, 13);
	int expectedResult = 1220703125;
	EXPECT_EQ(result, expectedResult);
}

TEST(TestThirdTask, task3Test2) {
	loggerTest.get()->debug("Test 2 of task 3 function");
	int result = task3(7, 4);
	int expectedResult = 2401;
	EXPECT_EQ(result, expectedResult);
}

TEST(TestThirdTask, task3Test3) {
	loggerTest.get()->debug("Test 3 of task 3 function");
	int result = task3(8, 1);
	int expectedResult = 8;
	EXPECT_EQ(result, expectedResult);
}

TEST(TestForthTask, task4Test1) {
	loggerTest.get()->debug("Test 1 of task 4 function");
	std::pair<int, int> resultPair = task4(5);
	std::pair<int, int> expectedtPair(2, 3);
	EXPECT_EQ(resultPair.first, expectedtPair.first);
	EXPECT_EQ(resultPair.second, expectedtPair.second);
}

TEST(TestForthTask, task4Test2) {
	loggerTest.get()->debug("Test 2 of task 4 function");
	std::pair<int, int> resultPair = task4(500);
	std::pair<int, int> expectedtPair(8, 9);
	EXPECT_EQ(resultPair.first, expectedtPair.first);
	EXPECT_EQ(resultPair.second, expectedtPair.second);
}

TEST(TestForthTask, task4Test3) {
	loggerTest.get()->debug("Test 3 of task 4 function");
	std::pair<int, int> resultPair = task4(16);
	std::pair<int, int> expectedtPair(4, 5);
	EXPECT_EQ(resultPair.first, expectedtPair.first);
	EXPECT_EQ(resultPair.second, expectedtPair.second);
}