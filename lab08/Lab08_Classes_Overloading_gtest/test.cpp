#include "pch.h"
#include "../Lab08_OOP/RationalNumber.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(RationalNumberTest, ClassConstrDefault) {
	RationalNumber<int> a;
	EXPECT_TRUE(a == RationalNumber<int>(0, 1));
}

TEST(RationalNumberTest, ClassConstrParametrs) {
	RationalNumber<int> a(2, 3);
	EXPECT_TRUE(a == RationalNumber<int>(2, 3));
}

TEST(RationalNumberTest, ClassConstrCopy) {
	RationalNumber<int> a(2, 3);
	RationalNumber<int> b(a);
	EXPECT_TRUE(b == RationalNumber<int>(2, 3));
}
TEST(RationalNumberTest, OperatorUnaryPlus) {
	RationalNumber<int> a(2, 6);
	EXPECT_TRUE(+a == RationalNumber<int>(1, 3));
}
TEST(RationalNumberTest, OperatorSum) {
	RationalNumber<int> a(1, 3);
	RationalNumber<int> b(1, 2);
	EXPECT_TRUE(a + b == RationalNumber<int>(5, 6));
}

TEST(RationalNumberTest, OperatorSumT) {
	RationalNumber<int> a(1, 3);
	int b = 2;
	EXPECT_TRUE(a + b == RationalNumber<int>(7, 3));
}

TEST(RationalNumberTest, OperatorUnaryMinus) {
	RationalNumber<int> a(2, 6);
	EXPECT_TRUE(-a == RationalNumber<int>(-2, 6));
}
TEST(RationalNumberTest, OperatorSubstraction) {
	RationalNumber<int> a(1, 3);
	RationalNumber<int> b(1, 2);
	EXPECT_TRUE(a - b == RationalNumber<int>(-1, 6));
}

TEST(RationalNumberTest, OperatorSubstractionT) {
	RationalNumber<int> a(1, 3);
	int b = 2;
	EXPECT_TRUE(a - b == RationalNumber<int>(-5, 3));
}

TEST(RationalNumberTest, OperatorMultiplication) {
	RationalNumber<int> a(1, 3);
	RationalNumber<int> b(1, 2);
	EXPECT_TRUE(a * b == RationalNumber<int>(1, 6));
}

TEST(RationalNumberTest, OperatorMultiplicationT) {
	RationalNumber<int> a(1, 3);
	int b = 2;
	EXPECT_TRUE(a * b == RationalNumber<int>(2, 3));
}

TEST(RationalNumberTest, OperatorDivision) {
	RationalNumber<int> a(1, 3);
	RationalNumber<int> b(1, 2);
	EXPECT_TRUE(a / b == RationalNumber<int>(2, 3));
}

TEST(RationalNumberTest, OperatorDivisionT) {
	RationalNumber<int> a(1, 3);
	int b = 2;
	EXPECT_TRUE(a / b == RationalNumber<int>(1, 6));
}

TEST(RationalNumberTest, OperatorEqual) {
	RationalNumber<int> a(1, 3);
	RationalNumber<int> b = a;
	EXPECT_TRUE(b == RationalNumber<int>(1, 3));
}

TEST(RationalNumberTest, OperatorEqualT) {
	int a = 2;
	RationalNumber<int> b;
	b = a;
	EXPECT_TRUE(b == RationalNumber<int>(2, 1));
}

TEST(RationalNumberTest, OperatorPlusEqual) {
	RationalNumber<int> a(1, 3);
	RationalNumber<int> b(1, 2);
	a += b;
	EXPECT_TRUE(a == RationalNumber<int>(5, 6));
}

TEST(RationalNumberTest, OperatorPlusEqualT) {
	RationalNumber<int> a(1, 3);
	int b = 2;
	a += b;
	EXPECT_TRUE(a == RationalNumber<int>(7, 3));
}

TEST(RationalNumberTest, OperatorMinusEqual) {
	RationalNumber<int> a(1, 3);
	RationalNumber<int> b(1, 2);
	a -= b;
	EXPECT_TRUE(a == RationalNumber<int>(-1, 6));
}

TEST(RationalNumberTest, OperatorMinusEqualT) {
	RationalNumber<int> a(1, 3);
	int b = 2;
	a -= b;
	EXPECT_TRUE(a == RationalNumber<int>(-5, 3));
}

TEST(RationalNumberTest, OperatorMultiplyEqual) {
	RationalNumber<int> a(1, 3);
	RationalNumber<int> b(1, 2);
	a *= b;
	EXPECT_TRUE(a == RationalNumber<int>(1, 6));
}

TEST(RationalNumberTest, OperatorMultiplyEqualT) {
	RationalNumber<int> a(1, 3);
	int b = 2;
	a *= b;
	EXPECT_TRUE(a == RationalNumber<int>(2, 3));
}

TEST(RationalNumberTest, OperatorDivisionEqual) {
	RationalNumber<int> a(1, 3);
	RationalNumber<int> b(1, 2);
	a /= b;
	EXPECT_TRUE(a == RationalNumber<int>(2, 3));
}

TEST(RationalNumberTest, OperatorDivisionEqualT) {
	RationalNumber<int> a(1, 3);
	int b = 2;
	a /= b;
	EXPECT_TRUE(a == RationalNumber<int>(1, 6));
}

TEST(RationalNumberTest, OperatorCheckEqual) {
	RationalNumber<int> a(1, 3);
	RationalNumber<int> b(1, 3);
	EXPECT_TRUE(a == b);
	RationalNumber<int> c(2, 3);
	EXPECT_FALSE(a == c);
}

TEST(RationalNumberTest, OperatorCheckEqualT) {
	RationalNumber<int> a(2, 1);
	int b = 2;
	EXPECT_TRUE(a == b);
	int c = 3;
	EXPECT_FALSE(a == c);
}

TEST(RationalNumberTest, OperatorCheckNotEqual) {
	RationalNumber<int> a(1, 3);
	RationalNumber<int> b(2, 3);
	EXPECT_TRUE(a != b);
	RationalNumber<int> c(1, 3);
	EXPECT_FALSE(a != c);
}

TEST(RationalNumberTest, OperatorCheckNotEqualT) {
	RationalNumber<int> a(2, 1);
	int b = 3;
	EXPECT_TRUE(a != b);
	int c = 2;
	EXPECT_FALSE(a != c);
}

TEST(RationalNumberTest, OperatorCheckLess) {
	RationalNumber<int> a(1, 3);
	RationalNumber<int> b(2, 3);
	EXPECT_TRUE(a < b);
	RationalNumber<int> c(1, 3);
	EXPECT_FALSE(a < c);
}

TEST(RationalNumberTest, OperatorCheckLessT) {
	RationalNumber<int> a(2, 1);
	int b = 3;
	EXPECT_TRUE(a < b);
	int c = 2;
	EXPECT_FALSE(a < c);
}

TEST(RationalNumberTest, OperatorCheckGreater) {
	RationalNumber<int> a(2, 3);
	RationalNumber<int> b(1, 3);
	EXPECT_TRUE(a > b);
	RationalNumber<int> c(4, 3);
	EXPECT_FALSE(a > c);
}

TEST(RationalNumberTest, OperatorCheckGreaterT) {
	RationalNumber<int> a(3, 1);
	int b = 2;
	EXPECT_TRUE(a > b);
	int c = 4;
	EXPECT_FALSE(a > c);
}

TEST(RationalNumberTest, OperatorCheckLessEqual) {
	RationalNumber<int> a(1, 3);
	RationalNumber<int> b(2, 3);
	EXPECT_TRUE(a <= b);
	RationalNumber<int> d(1, 3);
	EXPECT_TRUE(a <= d);
	RationalNumber<int> c(1, 6);
	EXPECT_FALSE(a <= c);
}

TEST(RationalNumberTest, OperatorCheckLessEqualT) {
	RationalNumber<int> a(2, 1);
	int b = 3;
	EXPECT_TRUE(a <= b);
	int d = 2;
	EXPECT_TRUE(a <= d);
	int c = 1;
	EXPECT_FALSE(a <= c);
}

TEST(RationalNumberTest, OperatorCheckGreaterEqual) {
	RationalNumber<int> a(2, 3);
	RationalNumber<int> b(1, 3);
	EXPECT_TRUE(a >= b);
	RationalNumber<int> d(2, 3);
	EXPECT_TRUE(a >= d);
	RationalNumber<int> c(4, 3);
	EXPECT_FALSE(a >= c);
}

TEST(RationalNumberTest, OperatorCheckGreaterEqualT) {
	RationalNumber<int> a(3, 1);
	int b = 2;
	EXPECT_TRUE(a >= b);
	int d = 3;
	EXPECT_TRUE(a >= d);
	int c = 4;
	EXPECT_FALSE(a >= c);
}

TEST(RationalNumberTest, OperatorIncrement) {
	RationalNumber<int> a(2, 3);
	++a;
	EXPECT_TRUE(a == RationalNumber<int> (5, 3));
}

TEST(RationalNumberTest, OperatorDecrement) {
	RationalNumber<int> a(4, 3);
	--a;
	EXPECT_TRUE(a == RationalNumber<int>(1, 3));
}