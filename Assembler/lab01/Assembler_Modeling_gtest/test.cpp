#include "pch.h"
#include "../Modeling_Assembler/ProgramClass.h"

class ProgramTest : public ::testing::Test
{
protected:
	void SetUp() {
		obj = new ProgramClass;
	}
	void TearDown() {
		delete obj;
	}
	ProgramClass* obj;
};

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST_F(ProgramTest, SetGetRegData) {
	obj->setRegisterData(10);
	EXPECT_EQ(obj->getRegisterData(), 10);
}

TEST_F(ProgramTest, SetGetResData) {
	obj->setResultData("first", 10);
	EXPECT_EQ(obj->getResultData("first"), 10);
}

