#include <vector>
#include "pch.h"
#include "../Seminar11_Matrix/Array.h"

class ArrayTestOperator : public ::testing::Test
{
protected:
	void SetUp() {
		a = new Array<int>{ 4, 5 };
		b = new Array<int>{ 1, 2 };
		c = new Array<int>();
	}
	void TearDown() {
		delete a;
		delete b;
		delete c;
	}
	Array<int>* a;
	Array<int>* b;
	Array<int>* c;
};
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(ArrayTest, DefaultConstr) {
	Array<int> a;
	EXPECT_EQ(a.getSize(), 0);
}

TEST(ArrayTest, ConstrWithSize) {
	Array<int> a(3);
	EXPECT_EQ(a.getSize(), 3);
}

TEST(ArrayTest, ConstrWithSizeAndValue) {
	Array<int> a(2, 4);
	EXPECT_EQ(a.getSize(), 2);
	EXPECT_EQ(a.getItem(0), 4);
	EXPECT_EQ(a.getItem(1), 4);
}

TEST(ArrayTest, ConstrInitializerList) {
	Array<int> a{1, 8, 6};
	EXPECT_EQ(a.getSize(), 3);
	EXPECT_EQ(a.getItem(0), 1);
	EXPECT_EQ(a.getItem(1), 8);
	EXPECT_EQ(a.getItem(2), 6);
}

TEST(ArrayTest, ConstrVector) {
	std::vector<int> list = { 8, 3, 4 };
	Array<int> a(list);
	EXPECT_EQ(a.getSize(), 3);
	EXPECT_EQ(a.getItem(0), 8);
	EXPECT_EQ(a.getItem(1), 3);
	EXPECT_EQ(a.getItem(2), 4);
}

TEST(ArrayTest, CopyConstr) {
	Array<int> a{5, 3};
	Array<int> b(a);
	EXPECT_EQ(b.getSize(), 2);
	EXPECT_EQ(b.getItem(0), 5);
	EXPECT_EQ(b.getItem(1), 3);
}

TEST(ArrayTest, CopyConstrOperator) {
	Array<int> a{ 5, 3 };
	Array<int> b = a;
	EXPECT_EQ(b.getSize(), 2);
	EXPECT_EQ(b.getItem(0), 5);
	EXPECT_EQ(b.getItem(1), 3);
}

TEST(ArrayTest, MoveConstr) {
	Array<int> a{ 5, 3 };
	Array<int> b(std::move(a));
	EXPECT_EQ(a.getSize(), 0);
	EXPECT_EQ(b.getSize(), 2);
	EXPECT_EQ(b.getItem(0), 5);
	EXPECT_EQ(b.getItem(1), 3);
}

TEST(ArrayTest, MoveConstrOperator) {
	Array<int> a{ 5, 3 };
	Array<int> b = std::move(a);
	EXPECT_EQ(a.getSize(), 0);
	EXPECT_EQ(b.getSize(), 2);
	EXPECT_EQ(b.getItem(0), 5);
	EXPECT_EQ(b.getItem(1), 3);
}

TEST_F(ArrayTestOperator, OperatorPlus) {
	*c = *a + *b;
	EXPECT_EQ(c->getItem(0), 4);
	EXPECT_EQ(c->getItem(1), 5);
	EXPECT_EQ(c->getItem(2), 1);
	EXPECT_EQ(c->getItem(3), 2);
}

TEST_F(ArrayTestOperator, OperatorPlusTValue) {
	*c = *a + 5;
	EXPECT_EQ(c->getItem(0), 9);
	EXPECT_EQ(c->getItem(1), 10);
}

TEST_F(ArrayTestOperator, OperatorMinus) {
	*c = *a - *b;
	EXPECT_EQ(c->getItem(0), 3);
	EXPECT_EQ(c->getItem(1), 3);
}

TEST_F(ArrayTestOperator, OperatorMinusTValue) {
	*c = *a - 5;
	EXPECT_EQ(c->getItem(0), -1);
	EXPECT_EQ(c->getItem(1), 0);
}

TEST_F(ArrayTestOperator, OperatorMultiplicateTValue) {
	*c = *a * 2;
	EXPECT_EQ(c->getItem(0), 8);
	EXPECT_EQ(c->getItem(1), 10);
}

TEST_F(ArrayTestOperator, OperatorDivideTValue) {
	*c = *b / 2;
	EXPECT_EQ(c->getItem(0), 0);
	EXPECT_EQ(c->getItem(1), 1);
}

TEST_F(ArrayTestOperator, OperatorEqualTValue) {
	*b = 6;
	EXPECT_EQ(b->getItem(0), 6);
	EXPECT_EQ(b->getItem(1), 6);
}

TEST_F(ArrayTestOperator, OperatorPlusEqual) {
	*a += 4;
	EXPECT_EQ(a->getItem(0), 8);
	EXPECT_EQ(a->getItem(1), 9);
}

TEST_F(ArrayTestOperator, OperatorMinusEqual) {
	*a -= 4;
	EXPECT_EQ(a->getItem(0), 0);
	EXPECT_EQ(a->getItem(1), 1);
}

TEST_F(ArrayTestOperator, OperatorMultiplicateEqual) {
	*a *= 4;
	EXPECT_EQ(a->getItem(0), 16);
	EXPECT_EQ(a->getItem(1), 20);
}

TEST_F(ArrayTestOperator, OperatorDivideEqual) {
	*a /= 4;
	EXPECT_EQ(a->getItem(0), 1);
	EXPECT_EQ(a->getItem(1), 1);
}

TEST_F(ArrayTestOperator, OperatorEq) {
	EXPECT_FALSE(*a == *b);
	EXPECT_TRUE(*a == *a);
}

TEST_F(ArrayTestOperator, OperatorEqTValue) {
	EXPECT_FALSE(*a == 5);
	*c = { 1 , 1 };
	EXPECT_TRUE(*c == 1);
}

TEST_F(ArrayTestOperator, OperatorNotEq) {
	EXPECT_TRUE(*a != *b);
	EXPECT_FALSE(*a != *a);
}

TEST_F(ArrayTestOperator, OperatorNotEqTValue) {
	EXPECT_TRUE(*a != 5);
	*c = { 1 , 1 };
	EXPECT_FALSE(*c != 1);
}

TEST_F(ArrayTestOperator, OperatorLess) {
	EXPECT_FALSE(*a < *b);
	EXPECT_TRUE(*b < *a);
}

TEST_F(ArrayTestOperator, OperatorGreater) {
	EXPECT_FALSE(*b > *a);
	EXPECT_TRUE(*a > *b);
}

TEST_F(ArrayTestOperator, OperatorLessEq) {
	*c = { 3, 5 };
	EXPECT_TRUE(*c <= *a);
	*c = { 1, 3 };
	EXPECT_FALSE(*c <= *b);
}

TEST_F(ArrayTestOperator, OperatorGreaterEq) {
	*c = { 4, 6 };
	EXPECT_TRUE(*c >= *a);
	*c = { 1, 1 };
	EXPECT_FALSE(*c >= *b);
}

TEST_F(ArrayTestOperator, OperatorIncrementPrefix) {
	++*a;
	EXPECT_EQ(a->getItem(0), 5);
	EXPECT_EQ(a->getItem(1), 6);
}

TEST_F(ArrayTestOperator, OperatorDecrementPrefix) {
	--*a;
	EXPECT_EQ(a->getItem(0), 3);
	EXPECT_EQ(a->getItem(1), 4);
}

TEST_F(ArrayTestOperator, OperatorIncrementPostfix) {
	(*a)++;
	EXPECT_EQ(a->getItem(0), 5);
	EXPECT_EQ(a->getItem(1), 6);
}

TEST_F(ArrayTestOperator, OperatorDecrementPostfix) {
	(*a)--;
	EXPECT_EQ(a->getItem(0), 3);
	EXPECT_EQ(a->getItem(1), 4);
}

TEST_F(ArrayTestOperator, ItemSum) {
	EXPECT_EQ(a->itemSum(), 9);
}

TEST_F(ArrayTestOperator, MinItem) {
	EXPECT_EQ(a->findMinItem(), 4);
}

TEST_F(ArrayTestOperator, MaxItem) {
	EXPECT_EQ(a->findMaxItem(), 5);
}

TEST_F(ArrayTestOperator, MinItemIndex) {
	EXPECT_EQ(a->findIndexMinItem(), 0);
}

TEST_F(ArrayTestOperator, MaxItemIndex) {
	EXPECT_EQ(a->findIndexMaxItem(), 1);
}