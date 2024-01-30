#include <vector>
#include <fstream>
#include <iostream>
#include "pch.h"
#include "../Seminar11_Matrix/Matrix.h"
#include "../Seminar11_Matrix/MatrixService.h"

class MatrixTestOperator : public ::testing::Test
{
protected:
	void SetUp() {
		a = new Matrix<int>(4, { 4, 2, 2, 9 });
		b = new Matrix<int>(4, { 1, 7, 3, 4 });
		c = new Matrix<int>();
	}
	void TearDown() {
		delete a;
		delete b;
		delete c;
	}
	Matrix<int>* a;
	Matrix<int>* b;
	Matrix<int>* c;
};

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(MatrixTest, DefaultConstr) {
	Matrix<int> a;
	EXPECT_EQ(a.getHeight(), 1);
	EXPECT_EQ(a.getWidth(), 0);
}

TEST(MatrixTest, ConstrWithSize) {
	Matrix<int> a(3, 4);
	EXPECT_EQ(a.getHeight(), 3);
	EXPECT_EQ(a.getWidth(), 4);
}

TEST(MatrixTest, ConstrIdentityMatrix) {
	Matrix<int> a(3);
	EXPECT_EQ(a.getHeight(), 3);
	EXPECT_EQ(a.getWidth(), 3);
}

TEST(MatrixTest, ConstrDiagonalMatrix) {
	Matrix<int> a(3, {1, 6, 2});
	EXPECT_EQ(a.getHeight(), 3);
	EXPECT_EQ(a.getWidth(), 3);
	EXPECT_EQ(a.getItem(0, 0), 1);
	EXPECT_EQ(a.getItem(1, 1), 6);
	EXPECT_EQ(a.getItem(2, 2), 2);
}

TEST(MatrixTest, CopyConstr) {
	Matrix<int> a(2, {4, 8});
	Matrix<int> b(a);
	EXPECT_EQ(b.getHeight(), 2);
	EXPECT_EQ(b.getWidth(), 2);
	EXPECT_EQ(b.getItem(0, 0), 4);
	EXPECT_EQ(b.getItem(1, 1), 8);
}

TEST(MatrixTest, CopyConstrOperator) {
	Matrix<int> a(2, { 4, 8 });
	Matrix<int> b = a;
	EXPECT_EQ(b.getHeight(), 2);
	EXPECT_EQ(b.getWidth(), 2);
	EXPECT_EQ(b.getItem(0, 0), 4);
	EXPECT_EQ(b.getItem(1, 1), 8);
}

TEST(MatrixTest, MoveConstr) {
	Matrix<int> a(2, { 4, 8 });
	Matrix<int> b(std::move(a));
	EXPECT_EQ(b.getHeight(), 2);
	EXPECT_EQ(b.getWidth(), 2);
	EXPECT_EQ(b.getItem(0, 0), 4);
	EXPECT_EQ(b.getItem(1, 1), 8);
}

TEST(MatrixTest, MoveConstrOperator) {
	Matrix<int> a(2, { 4, 8 });
	Matrix<int> b = std::move(a);
	EXPECT_EQ(b.getHeight(), 2);
	EXPECT_EQ(b.getWidth(), 2);
	EXPECT_EQ(b.getItem(0, 0), 4);
	EXPECT_EQ(b.getItem(1, 1), 8);
}

TEST(MatrixTest, PushRow) {
	Matrix<int> a(2, { 4, 8 });
	std::vector<int> row{ 5, 5 };
	a.pushRow(row);
	EXPECT_EQ(a.getHeight(), 3);
	EXPECT_EQ(a.getWidth(), 2);
	EXPECT_EQ(a.getItem(2, 0), 5);
	EXPECT_EQ(a.getItem(2, 1), 5);
}

TEST_F(MatrixTestOperator, OperatorPlus) {
	*c = *a + *b;
	EXPECT_EQ(c->getItem(0, 0), 5);
	EXPECT_EQ(c->getItem(1, 1), 9);
	EXPECT_EQ(c->getItem(2, 2), 5);
	EXPECT_EQ(c->getItem(3, 3), 13);
}

TEST_F(MatrixTestOperator, OperatorMinus) {
	*c = *a - *b;
	EXPECT_EQ(c->getItem(0, 0), 3);
	EXPECT_EQ(c->getItem(1, 1), -5);
	EXPECT_EQ(c->getItem(2, 2), -1);
	EXPECT_EQ(c->getItem(3, 3), 5);
}

TEST_F(MatrixTestOperator, OperatorMultiplicateTValue) {
	*c = *a * 2;
	EXPECT_EQ(c->getItem(0, 0), 8);
	EXPECT_EQ(c->getItem(1, 1), 4);
	EXPECT_EQ(c->getItem(2, 2), 4);
	EXPECT_EQ(c->getItem(3, 3), 18);
}

TEST_F(MatrixTestOperator, OperatorMultiplicateMatrices) {
	*c = *a * *b;
	EXPECT_EQ(c->getItem(0, 0), 4);
	EXPECT_EQ(c->getItem(1, 1), 14);
	EXPECT_EQ(c->getItem(2, 2), 6);
	EXPECT_EQ(c->getItem(3, 3), 36);
}

TEST_F(MatrixTestOperator, OperatorDivideTValue) {
	*c = *a / 2;
	EXPECT_EQ(c->getItem(0, 0), 2);
	EXPECT_EQ(c->getItem(1, 1), 1);
	EXPECT_EQ(c->getItem(2, 2), 1);
	EXPECT_EQ(c->getItem(3, 3), 4);
}

TEST_F(MatrixTestOperator, OperatorPlusEqual) {
	*a += *b;
	EXPECT_EQ(a->getItem(0, 0), 5);
	EXPECT_EQ(a->getItem(1, 1), 9);
	EXPECT_EQ(a->getItem(2, 2), 5);
	EXPECT_EQ(a->getItem(3, 3), 13);
}

TEST_F(MatrixTestOperator, OperatorMinusEqual) {
	*a -= *b;
	EXPECT_EQ(a->getItem(0, 0), 3);
	EXPECT_EQ(a->getItem(1, 1), -5);
	EXPECT_EQ(a->getItem(2, 2), -1);
	EXPECT_EQ(a->getItem(3, 3), 5);
}

TEST_F(MatrixTestOperator, OperatorMultiplicateEqual) {
	*a *= 4;
	EXPECT_EQ(a->getItem(0, 0), 16);
	EXPECT_EQ(a->getItem(1, 1), 8);
	EXPECT_EQ(a->getItem(2, 2), 8);
	EXPECT_EQ(a->getItem(3, 3), 36);
}

TEST_F(MatrixTestOperator, OperatorDivideEqual) {
	*a /= 4;
	EXPECT_EQ(a->getItem(0, 0), 1);
	EXPECT_EQ(a->getItem(1, 1), 0);
	EXPECT_EQ(a->getItem(2, 2), 0);
	EXPECT_EQ(a->getItem(3, 3), 2);
}

TEST_F(MatrixTestOperator, OperatorEq) {
	EXPECT_FALSE(*a == *b);
	EXPECT_TRUE(*a == *a);
}

TEST_F(MatrixTestOperator, OperatorNotEq) {
	EXPECT_TRUE(*a != *b);
	EXPECT_FALSE(*a != *a);
}

TEST(MatrixTest, SetItemMatrix) {
	Matrix<int> a(2, 3);
	a.setItem(0, 1, 8);
	EXPECT_EQ(a.getItem(0, 1), 8);
}