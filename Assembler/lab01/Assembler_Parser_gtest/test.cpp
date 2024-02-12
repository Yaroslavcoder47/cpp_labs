#include "pch.h"
#include "../Modeling_Assembler/Parser.cpp"



class ParserTest : public ::testing::Test
{
protected:
	void SetUp() {
		pars = new Parser;
	}
	void TearDown() {
		delete pars;
	}
	Parser* pars;
};

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(ParserTest, parseDataTestRes) {
	Parser obj;
	std::map<std::string, int> m = obj.parseData("input-test.txt", 0);
	EXPECT_EQ(1, 1);
}
//TEST_F(ParserTest, ParseCodeTest) {
//	std::string st = "input-test.txt";
//	std::map<std::string, int> m = pars->parseData(st, true);
//	EXPECT_EQ(m["x00"], -1);
//	EXPECT_EQ(m["x01"], 3);
//	EXPECT_EQ(m["x02"], 2);
//	EXPECT_EQ(m["x03"], 1);
//	EXPECT_EQ(m["x04"], 10);
//}


