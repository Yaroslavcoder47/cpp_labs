#pragma once
#ifndef MYSTRING_H
#define MYSTRING_H
#include <cstring>
#include <iostream>
#include <exception>

class MyString
{
public:
	MyString();
	MyString(const char* other);
	MyString(int count, char ch);
	MyString(const MyString& other);
	MyString operator=(const MyString& other);
	MyString(MyString&& moved) noexcept;
	MyString operator= (MyString&& moved) noexcept;
	~MyString();

	int length() const;
	bool empty() const;
	const char* c_str();
	char& operator[](int index);
	const char& operator[](int index) const;
	char& front();
	char& back();
	const char& front() const;
	const char& back() const;
	void reserve(int capacity);
	void push_back(char ch);
	void pop_back();
	void clear();
	bool insert(int index, const MyString& str);
	bool insert(int index, const char* str, int count);
	bool erase(int index, int count = 1);

	MyString operator+ (const MyString& other);
	MyString& operator+= (const MyString& other);

	int compare(const MyString& str) const;
	int compare(const char* str) const;

	bool operator< (const MyString& other) const;
	bool operator<= (const MyString& other) const;
	bool operator> (const MyString& other) const;
	bool operator>= (const MyString& other) const;
	bool operator== (const MyString& other) const;
	bool operator!= (const MyString& other) const;
	bool operator< (const char* other) const;
	bool operator<= (const char* other) const;
	bool operator> (const char* other) const;
	bool operator>= (const char* other) const;
	bool operator== (const char* other) const;
	bool operator!= (const char* other) const;
	friend bool operator==(const char* str, const MyString& other);
	friend bool operator!=(const char* str, const MyString& other);
	friend bool operator<(const char* str, const MyString& other);
	friend bool operator<=(const char* str, const MyString& other);
	friend bool operator>(const char* str, const MyString& other);
	friend bool operator>=(const char* str, const MyString& other);
private:
	char* array;
	int size;
	int capacity;
};

#endif // MYSTRING_H



