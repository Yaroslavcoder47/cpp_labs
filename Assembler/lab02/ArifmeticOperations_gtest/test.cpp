#include "pch.h"
#include "../ArifmeticOperations/Task1.cpp"
#include "../ArifmeticOperations/Task2.cpp"
#include "../ArifmeticOperations/Task3.cpp"
#include "../ArifmeticOperations/Task4.cpp"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"



TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(AdditionTest, task4Test) {
	uint16_t a1 = 0x0000;
	uint16_t a2 = 0x0000;
	uint16_t a3 = 0x0000;
	uint16_t b1 = 0x0000;
	uint16_t b2 = 0x0000;
	uint16_t b3 = 0x0000;

	std::vector<uint16_t> expectedResult = { 0x0000, 0x0000, 0x0000, 0x0000 };
	std::vector<uint16_t> realResult = task4(a1, a2, a3, b1, b2, b3);
	for (size_t i = 0; i < realResult.size(); ++i) {
		EXPECT_EQ(expectedResult[i], realResult[i]);
	}

	a1 = 0xFFFF;
	a2 = 0x0000;
	a3 = 0x0000;
	b1 = 0x0001;
	b2 = 0x0000;
	b3 = 0x0000;

	expectedResult = { 0x0000, 0x0001, 0x0000, 0x0000 };
	realResult = task4(a1, a2, a3, b1, b2, b3);
	for (size_t i = 0; i < realResult.size(); ++i) {
		EXPECT_EQ(expectedResult[i], realResult[i]);
	}

	a1 = 0xFFFF;
	a2 = 0xFFFF;
	a3 = 0xEFFF;
	b1 = 0x0001;
	b2 = 0x0000;
	b3 = 0x0000;

	expectedResult = { 0x0000, 0x0000, 0xF000, 0x0000 };
	realResult = task4(a1, a2, a3, b1, b2, b3);
	for (size_t i = 0; i < realResult.size(); ++i) {
		EXPECT_EQ(expectedResult[i], realResult[i]);
	}

	a1 = 0x0002;
	a2 = 0xFFFF;
	a3 = 0x0000;
	b1 = 0x0009;
	b2 = 0x0001;
	b3 = 0x0000;

	expectedResult = { 0x000B, 0x0000, 0x0001, 0x0000 };
	realResult = task4(a1, a2, a3, b1, b2, b3);
	for (size_t i = 0; i < realResult.size(); ++i) {
		EXPECT_EQ(expectedResult[i], realResult[i]);
	}

	a1 = 0x0100;
	a2 = 0x2BAC;
	a3 = 0x000F;
	b1 = 0x0001;
	b2 = 0x0000;
	b3 = 0x0000;

	expectedResult = { 0x0101, 0x2BAC, 0x000F, 0x0000 };
	realResult = task4(a1, a2, a3, b1, b2, b3);
	for (size_t i = 0; i < realResult.size(); ++i) {
		EXPECT_EQ(expectedResult[i], realResult[i]);
	}

	a1 = 0xFFFF;
	a2 = 0xFFFF;
	a3 = 0x0000;
	b1 = 0x0001;
	b2 = 0x0001;
	b3 = 0x0000;

	expectedResult = { 0x0000, 0x0001, 0x0001, 0x0000 };
	realResult = task4(a1, a2, a3, b1, b2, b3);
	for (size_t i = 0; i < realResult.size(); ++i) {
		EXPECT_EQ(expectedResult[i], realResult[i]);
	}

	a1 = 0xFFFF;
	a2 = 0xFFFF;
	a3 = 0x0000;
	b1 = 0x0001;
	b2 = 0x0001;
	b3 = 0x000F;

	expectedResult = { 0x0000, 0x0001, 0x0010, 0x0000 };
	realResult = task4(a1, a2, a3, b1, b2, b3);
	for (size_t i = 0; i < realResult.size(); ++i) {
		EXPECT_EQ(expectedResult[i], realResult[i]);
	}

	a1 = 0xFFFF;
	a2 = 0xFFFF;
	a3 = 0x000F;
	b1 = 0x0001;
	b2 = 0x0001;
	b3 = 0x0001;

	expectedResult = { 0x0000, 0x0001, 0x0011, 0x0000 };
	realResult = task4(a1, a2, a3, b1, b2, b3);
	for (size_t i = 0; i < realResult.size(); ++i) {
		EXPECT_EQ(expectedResult[i], realResult[i]);
	}

	a1 = 0xFFFF;
	a2 = 0xFFFF;
	a3 = 0xFFFF;
	b1 = 0x0001;
	b2 = 0x0000;
	b3 = 0x0000;

	expectedResult = { 0x0000, 0x0000, 0x0000, 0x0001 };
	realResult = task4(a1, a2, a3, b1, b2, b3);
	for (size_t i = 0; i < realResult.size(); ++i) {
		EXPECT_EQ(expectedResult[i], realResult[i]);
	}

	a1 = 0xFFFF;
	a2 = 0xFFFF;
	a3 = 0xFFFF;
	b1 = 0xFFFF;
	b2 = 0xFFFF;
	b3 = 0xFFFF;

	expectedResult = { 0xFFFE, 0xFFFF, 0xFFFF, 0x0001 };
	realResult = task4(a1, a2, a3, b1, b2, b3);
	for (size_t i = 0; i < realResult.size(); ++i) {
		EXPECT_EQ(expectedResult[i], realResult[i]);
	}
}

TEST(AdditionTest, task4AsmTest) {
	uint16_t a1 = 0x0000;
	uint16_t a2 = 0x0000;
	uint16_t a3 = 0x0000;
	uint16_t b1 = 0x0000;
	uint16_t b2 = 0x0000;
	uint16_t b3 = 0x0000;

	std::vector<uint16_t> expectedResult = { 0x0000, 0x0000, 0x0000, 0x0000 };
	std::vector<uint16_t> realResult = task4Asm(a1, a2, a3, b1, b2, b3);
	for (size_t i = 0; i < realResult.size(); ++i) {
		EXPECT_EQ(expectedResult[i], realResult[i]);
	}

	a1 = 0xFFFF;
	a2 = 0x0000;
	a3 = 0x0000;
	b1 = 0x0001;
	b2 = 0x0000;
	b3 = 0x0000;

	expectedResult = { 0x0000, 0x0001, 0x0000, 0x0000 };
	realResult = task4Asm(a1, a2, a3, b1, b2, b3);
	for (size_t i = 0; i < realResult.size(); ++i) {
		EXPECT_EQ(expectedResult[i], realResult[i]);
	}

	a1 = 0xFFFF;
	a2 = 0xFFFF;
	a3 = 0xEFFF;
	b1 = 0x0001;
	b2 = 0x0000;
	b3 = 0x0000;

	expectedResult = { 0x0000, 0x0000, 0xF000, 0x0000 };
	realResult = task4Asm(a1, a2, a3, b1, b2, b3);
	for (size_t i = 0; i < realResult.size(); ++i) {
		EXPECT_EQ(expectedResult[i], realResult[i]);
	}

	a1 = 0x0002;
	a2 = 0xFFFF;
	a3 = 0x0000;
	b1 = 0x0009;
	b2 = 0x0001;
	b3 = 0x0000;

	expectedResult = { 0x000B, 0x0000, 0x0001, 0x0000 };
	realResult = task4Asm(a1, a2, a3, b1, b2, b3);
	for (size_t i = 0; i < realResult.size(); ++i) {
		EXPECT_EQ(expectedResult[i], realResult[i]);
	}

	a1 = 0x0100;
	a2 = 0x2BAC;
	a3 = 0x000F;
	b1 = 0x0001;
	b2 = 0x0000;
	b3 = 0x0000;

	expectedResult = { 0x0101, 0x2BAC, 0x000F, 0x0000 };
	realResult = task4Asm(a1, a2, a3, b1, b2, b3);
	for (size_t i = 0; i < realResult.size(); ++i) {
		EXPECT_EQ(expectedResult[i], realResult[i]);
	}

	a1 = 0xFFFF;
	a2 = 0xFFFF;
	a3 = 0x0000;
	b1 = 0x0001;
	b2 = 0x0001;
	b3 = 0x0000;

	expectedResult = { 0x0000, 0x0001, 0x0001, 0x0000 };
	realResult = task4Asm(a1, a2, a3, b1, b2, b3);
	for (size_t i = 0; i < realResult.size(); ++i) {
		EXPECT_EQ(expectedResult[i], realResult[i]);
	}

	a1 = 0xFFFF;
	a2 = 0xFFFF;
	a3 = 0x0000;
	b1 = 0x0001;
	b2 = 0x0001;
	b3 = 0x000F;

	expectedResult = { 0x0000, 0x0001, 0x0010, 0x0000 };
	realResult = task4Asm(a1, a2, a3, b1, b2, b3);
	for (size_t i = 0; i < realResult.size(); ++i) {
		EXPECT_EQ(expectedResult[i], realResult[i]);
	}

	a1 = 0xFFFF;
	a2 = 0xFFFF;
	a3 = 0x000F;
	b1 = 0x0001;
	b2 = 0x0001;
	b3 = 0x0001;

	expectedResult = { 0x0000, 0x0001, 0x0011, 0x0000 };
	realResult = task4Asm(a1, a2, a3, b1, b2, b3);
	for (size_t i = 0; i < realResult.size(); ++i) {
		EXPECT_EQ(expectedResult[i], realResult[i]);
	}

	a1 = 0xFFFF;
	a2 = 0xFFFF;
	a3 = 0xFFFF;
	b1 = 0x0001;
	b2 = 0x0000;
	b3 = 0x0000;

	expectedResult = { 0x0000, 0x0000, 0x0000, 0x0001 };
	realResult = task4Asm(a1, a2, a3, b1, b2, b3);
	for (size_t i = 0; i < realResult.size(); ++i) {
		EXPECT_EQ(expectedResult[i], realResult[i]);
	}

	a1 = 0xFFFF;
	a2 = 0xFFFF;
	a3 = 0xFFFF;
	b1 = 0xFFFF;
	b2 = 0xFFFF;
	b3 = 0xFFFF;

	expectedResult = { 0xFFFE, 0xFFFF, 0xFFFF, 0x0001 };
	realResult = task4Asm(a1, a2, a3, b1, b2, b3);
	for (size_t i = 0; i < realResult.size(); ++i) {
		EXPECT_EQ(expectedResult[i], realResult[i]);
	}
}

TEST(EquationTest, task1Test){
	int result = task1(1);
	EXPECT_EQ(result, 3);

	result = task1(2);
	EXPECT_EQ(result, 42);

	result = task1(3);
	EXPECT_EQ(result, 273);
}

TEST(EquationTest, task2Test) {
	int result = task2(1);
	EXPECT_EQ(result, -4);

	result = task2(2);
	EXPECT_EQ(result, 4);

	result = task2(3);
	EXPECT_EQ(result, 9);
}

TEST(EquationTest, task3Test) {
	int result = task3(5);
	EXPECT_EQ(result, 13);

	result = task3(65535);
	EXPECT_EQ(result, 1);

	result = task3(15);
	EXPECT_EQ(result, 7);
}