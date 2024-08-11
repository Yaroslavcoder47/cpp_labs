#include "pch.h"
#include "../Lab12_WorkWithMemory/StackOnList.h"
#include "../Lab12_WorkWithMemory/StackOnArray.h"
//#include "spdlog/spdlog.h"
//#include "spdlog/sinks/basic_file_sink.h"


TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

TEST(StackOnList, isCostrWorking) {
	StackOnList<int>* stack = new StackOnList<int>();
	EXPECT_NE(stack, nullptr);
	delete stack;
}

TEST(StackOnList, isPushWorking) {
	StackOnList<int>* stack = new StackOnList<int>();
	stack->push(1);
	EXPECT_EQ(stack->top(), 1);
	stack->push(2);
	EXPECT_EQ(stack->top(), 2);
	delete stack;
}

TEST(StackOnList, isPopWorking) {
	StackOnList<int>* stack = new StackOnList<int>();
	stack->push(1);
	stack->push(2);
	EXPECT_EQ(stack->pop(), 2);
	EXPECT_EQ(stack->pop(), 1);
	delete stack;
}

TEST(StackOnList, isStackEmpty) {
	StackOnList<int>* stack = new StackOnList<int>();
	EXPECT_TRUE(stack->isEmpty());
	stack->push(1);
	stack->push(2);
	EXPECT_FALSE(stack->isEmpty());
	stack->pop();
	EXPECT_FALSE(stack->isEmpty());
	stack->pop();
	EXPECT_TRUE(stack->isEmpty());
	delete stack;
}

TEST(StackOnList, isCopyCostrWorking) {
	StackOnList<int>* stack = new StackOnList<int>();
	stack->push(1);
	stack->push(2);
	stack->push(3);
	stack->push(4);
	stack->push(5);
	StackOnList<int>* stack2 = new StackOnList<int>(*stack);
	EXPECT_EQ(stack2->top(), stack->top());
	stack->pop();
	stack2->pop();
	EXPECT_EQ(stack2->top(), stack->top());	stack->pop();
	stack2->pop();
	EXPECT_EQ(stack2->top(), stack->top());	stack->pop();
	stack2->pop();
	EXPECT_EQ(stack2->top(), stack->top());	stack->pop();
	stack2->pop();
	EXPECT_EQ(stack2->top(), stack->top());
	delete stack;
	delete stack2;
}

TEST(StackOnList, isSizeWorking) {
	StackOnList<int>* stack = new StackOnList<int>();
	stack->push(1);
	stack->push(2);
	stack->push(3);
	stack->push(4);
	EXPECT_EQ(stack->size(), 4);
	stack->pop();
	EXPECT_EQ(stack->size(), 3);
	stack->pop();
	EXPECT_EQ(stack->size(), 2);
	stack->pop();
	EXPECT_EQ(stack->size(), 1);
	stack->pop();
	EXPECT_EQ(stack->size(), 0);
	delete stack;
}

TEST(StackOnList, isCostrInitializerWorking) {
	StackOnList<int>* stack = new StackOnList<int>{ 1, 2, 3, 4 };
	EXPECT_EQ(stack->top(), 4);
	stack->pop();
	EXPECT_EQ(stack->top(), 3);
	stack->pop();
	EXPECT_EQ(stack->top(), 2);
	stack->pop();
	EXPECT_EQ(stack->top(), 1);
	stack->pop();
	delete stack;
}

TEST(StackOnList, isOperatorEqualWorking) {
	StackOnList<int>* stack1 = new StackOnList<int>{ 1, 2, 3 };
	StackOnList<int>* stack2 = new StackOnList<int>{ 1, 2, 3 };
	EXPECT_TRUE(*stack1 == *stack2);
	stack1->pop();
	EXPECT_FALSE(*stack1 == *stack2);
	stack1->push(4);
	EXPECT_FALSE(*stack1 == *stack2);
	delete stack1;
	delete stack2;
}

TEST(StackOnList, isCopyOperatorWorking) {
	StackOnList<int>* stack = new StackOnList<int>();
	stack->push(1);
	stack->push(2);
	stack->push(3);
	stack->push(4);
	stack->push(5);
	StackOnList<int> stack2 = *stack;
	EXPECT_EQ(stack2.top(), stack->top());
	stack->pop();
	stack2.pop();
	EXPECT_EQ(stack2.top(), stack->top());
	stack->pop();
	stack2.pop();
	EXPECT_EQ(stack2.top(), stack->top());
	stack->pop();
	stack2.pop();
	EXPECT_EQ(stack2.top(), stack->top());
	stack->pop();
	stack2.pop();
	EXPECT_EQ(stack2.top(), stack->top());
	delete stack;
}

TEST(StackOnList, isCostrMoveWorking) {
	StackOnList<int>* stack1 = new StackOnList<int>{ 1, 2 };
	StackOnList<int>* stack2 = new StackOnList<int>(std::move(*stack1));
	EXPECT_EQ(stack2->top(), 2);
	stack2->pop();
	EXPECT_EQ(stack2->top(), 1);
	delete stack1;
	delete stack2;
}

TEST(StackOnList, isOperatorMoveWorking) {
	StackOnList<int>* stack1 = new StackOnList<int>{ 1, 2 };
	StackOnList<int>* stack2 = new StackOnList<int>(std::move(*stack1));
	EXPECT_EQ(stack2->top(), 2);
	stack2->pop();
	EXPECT_EQ(stack2->top(), 1);
	delete stack1;
	delete stack2;
}

/////////////// Tests for StackOnArray
TEST(StackOnArray, isPushWorking) {
	StackOnArray<int>* stack = new StackOnArray<int>();
	stack->push(1);
	EXPECT_EQ(stack->top(), 1);
	stack->push(2);
	EXPECT_EQ(stack->top(), 2);
	delete stack;
}

TEST(StackOnArray, isPopWorking) {
	StackOnArray<int>* stack = new StackOnArray<int>();
	stack->push(1);
	stack->push(2);
	EXPECT_EQ(stack->pop(), 2);
	EXPECT_EQ(stack->pop(), 1);
	delete stack;
}

TEST(StackOnArray, isEmptyWorking)
{
	StackOnArray<int>* stack = new StackOnArray<int>();
	EXPECT_TRUE(stack->isEmpty());
	stack->push(1);
	EXPECT_FALSE(stack->isEmpty());
	stack->pop();
	EXPECT_TRUE(stack->isEmpty());
	delete stack;
}

TEST(StackOnArray, isSizeWorking)
{
	StackOnArray<int>* stack = new StackOnArray<int>();
	EXPECT_EQ(stack->size(), 0);
	stack->push(1);
	EXPECT_EQ(stack->size(), 1);
	stack->push(1);
	EXPECT_EQ(stack->size(), 2);
	delete stack;
}

TEST(StackOnArray, isCostrInitializerWorking) {
	StackOnArray<int>* stack = new StackOnArray<int>{ 1, 2, 3, 4 };
	EXPECT_EQ(stack->top(), 4);
	stack->pop();
	EXPECT_EQ(stack->top(), 3);
	stack->pop();
	EXPECT_EQ(stack->top(), 2);
	stack->pop();
	EXPECT_EQ(stack->top(), 1);
	stack->pop();
	delete stack;
}

TEST(StackOnArray, isCostrCopyWorking) {
	StackOnArray<int>* stack = new StackOnArray<int>{ 1, 2, 3, 4 };
	StackOnArray<int>* stack1 = new StackOnArray<int>(*stack);
	EXPECT_EQ(stack1->top(), 4);
	stack1->pop();
	EXPECT_EQ(stack1->top(), 3);
	stack1->pop();
	EXPECT_EQ(stack1->top(), 2);
	stack1->pop();
	EXPECT_EQ(stack1->top(), 1);
	stack1->pop();
	delete stack;
	delete stack1;
}

TEST(StackOnArray, isOperatorCopyWorking) {
	StackOnArray<int>* stack = new StackOnArray<int>{ 1, 2, 3, 4 };
	StackOnArray<int> stack1 = *stack;
	EXPECT_EQ(stack1.top(), 4);
	stack1.pop();
	EXPECT_EQ(stack1.top(), 3);
	stack1.pop();
	EXPECT_EQ(stack1.top(), 2);
	stack1.pop();
	EXPECT_EQ(stack1.top(), 1);
	stack1.pop();
	delete stack;
}

TEST(StackOnArray, isCostrMoveWorking) {
	StackOnArray<int>* stack1 = new StackOnArray<int>{ 1, 2 };
	StackOnArray<int>* stack2 = new StackOnArray<int>(std::move(*stack1));
	EXPECT_EQ(stack2->top(), 2);
	stack2->pop();
	EXPECT_EQ(stack2->top(), 1);
	delete stack1;
	delete stack2;
}

TEST(StackOnArray, isOperatorMoveWorking) {
	StackOnArray<int>* stack1 = new StackOnArray<int>{ 1, 2 };
	StackOnArray<int> stack2 = StackOnArray<int>(std::move(*stack1));
	EXPECT_EQ(stack2.top(), 2);
	stack2.pop();
	EXPECT_EQ(stack2.top(), 1);
	delete stack1;
}

TEST(StackOnArray, isOperatorEqualWorking) {
	StackOnArray<int>* stack1 = new StackOnArray<int>{ 1, 2, 3 };
	StackOnArray<int>* stack2 = new StackOnArray<int>{ 1, 2, 3 };
	EXPECT_TRUE(*stack1 == *stack2);
	stack1->pop();
	EXPECT_FALSE(*stack1 == *stack2);
	stack1->push(4);
	EXPECT_FALSE(*stack1 == *stack2);
	delete stack1;
	delete stack2;
}