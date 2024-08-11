#include "pch.h"
#include "../Lab11_Strings/MyString.cpp"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(StringTest, DefaultConstructor) {
    MyString str;
    EXPECT_EQ(1, 1);
    EXPECT_EQ(str.length(), 0);
    EXPECT_TRUE(str.empty());
    EXPECT_STREQ(str.c_str(), "");
}

TEST(StringTest, CharArrayConstructor) {
    const char* cStr = "Hello, World!";
    MyString str(cStr);
    EXPECT_EQ(str.length(), std::strlen(cStr));
    EXPECT_FALSE(str.empty());
    EXPECT_STREQ(str.c_str(), cStr);
}

TEST(StringTest, CharCountConstructor) {
    char ch = 'A';
    int count = 5;
    MyString str(count, ch);

    std::cout << "Length: " << str.length() << std::endl;
    std::cout << "String: " << str.c_str() << std::endl;

    EXPECT_EQ(str.length(), count);
    EXPECT_FALSE(str.empty());
    for (int i = 0; i < count; ++i) {
        EXPECT_EQ(str[i], ch);
    }
}

TEST(StringTest, CopyConstructor) {
    const char* cStr = "Hello, World!";
    MyString original(cStr);
    MyString copy(original);
    EXPECT_EQ(copy.length(), original.length());
    EXPECT_FALSE(copy.empty());
    EXPECT_STREQ(copy.c_str(), original.c_str());
}

TEST(StringTest, CopyAssignmentOperator) {
    const char* cStr1 = "Hello, World!";
    const char* cStr2 = "Hello, Universe!";
    MyString str1(cStr1);
    MyString str2(cStr2);
    str2 = str1;
    EXPECT_EQ(str2.length(), str1.length());
    EXPECT_FALSE(str2.empty());
    EXPECT_STREQ(str2.c_str(), str1.c_str());
}

TEST(StringTest, MoveConstructor) {
    const char* cStr = "Hello, World!";
    MyString original(cStr);
    MyString moved(std::move(original));
    EXPECT_EQ(original.length(), 0);
    EXPECT_TRUE(original.empty());
    EXPECT_STREQ(moved.c_str(), cStr);
}

TEST(StringTest, MoveAssignmentOperator) {
    const char* cStr1 = "Hello, World!";
    const char* cStr2 = "Hello, Universe!";
    MyString str1(cStr1);
    MyString str2(cStr2);
    str2 = std::move(str1);
    EXPECT_EQ(str1.length(), 0);
    EXPECT_TRUE(str1.empty());
    EXPECT_STREQ(str2.c_str(), cStr1);
}

TEST(StringTest, BracketOperator) {
    const char* cStr = "Hello, World!";
    MyString str(cStr);
    for (size_t i = 0; i < str.length(); ++i) {
        EXPECT_EQ(str[i], cStr[i]);
    }
}

TEST(StringTest, FrontBackFunctions) {
    const char* cStr = "Hello, World!";
    MyString str(cStr);
    EXPECT_EQ(str.front(), cStr[0]);
    EXPECT_EQ(str.back(), cStr[str.length() - 1]);
}

TEST(StringTest, ComparisonOperators) {
    const char* cStr1 = "Hello a";
    const char* cStr2 = "Hello b";
    MyString str1(cStr1);
    MyString str2(cStr2);

    EXPECT_TRUE(str1 == str1);
    EXPECT_TRUE(str1 != str2);
    EXPECT_TRUE(str1 < str2);
    EXPECT_TRUE(str1 <= str2);
    EXPECT_TRUE(str2 > str1);
    EXPECT_TRUE(str2 >= str1);

    EXPECT_TRUE(str1 == cStr1);
    EXPECT_TRUE(str1 != cStr2);
    EXPECT_TRUE(str1 < cStr2);
    EXPECT_TRUE(str1 <= cStr2);
    EXPECT_TRUE(cStr2 > str1);
    EXPECT_TRUE(cStr2 >= str1);
}

TEST(StringTest, ConcatenationOperators) {
    const char* cStr1 = "Hello, ";
    const char* cStr2 = "World!";
    MyString str1(cStr1);
    MyString str2(cStr2);
    MyString result = str1 + str2;

    EXPECT_STREQ(result.c_str(), "Hello, World!");

    str1 += str2;

    EXPECT_STREQ(str1.c_str(), "Hello, World!");
}

TEST(StringTest, InsertFunction) {
    const char* cStr1 = "123456";
    MyString str1(cStr1);
    const char* cStr2 = "abc";
    str1.insert(3, cStr2);
    EXPECT_STREQ(str1.c_str(), "123abc456");
    EXPECT_STRNE(str1.c_str(), "123abc");
    EXPECT_FALSE(str1.insert(-1, cStr2));

}

TEST(StringTest, EraseFunction) {
    const char* cStr = "abc abc";
    MyString str(cStr);
    str.erase(3, 4);
    EXPECT_STREQ(str.c_str(), "abc");
    EXPECT_STRNE(str.c_str(), "abcabc");
    EXPECT_FALSE(str.erase(-1, 2));

}
TEST(StringTest, PushPopFunctions) {
    MyString str;
    EXPECT_EQ(str.length(), 0);
    str.push_back('A');
    EXPECT_EQ(str.length(), 1);
    str.push_back('A');
    EXPECT_EQ(str[0], 'A');
    str.pop_back();
    EXPECT_EQ(str.length(), 1);
}

TEST(StringTest, ClearFunction) {
    const char* cStr = "Hello, World!";
    MyString str(cStr);
    str.clear();
    EXPECT_EQ(str.length(), 0);
    EXPECT_TRUE(str.empty());
}