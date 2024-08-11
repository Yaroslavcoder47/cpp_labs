#pragma once
#ifndef STACK_ON_ARRAY_H
#define STACK_ON_ARRAY_H

#include <initializer_list>
#include <cassert>
#include <vector>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

auto Arraylogger = spdlog::basic_logger_mt("StackOnArray", "logs/basic-log.txt");

template<class T>
class StackOnArray {
public:
	StackOnArray();
	~StackOnArray();
	StackOnArray(const std::initializer_list<T>& list);
	StackOnArray(const StackOnArray& other);
	StackOnArray& operator=(const StackOnArray& other);
	StackOnArray(StackOnArray&& moved);
	StackOnArray& operator=(StackOnArray&& moved);
	bool operator== (const StackOnArray& other);

	void push(const T& value);
	T pop();
	T& top();
	bool isEmpty();
	size_t size();
private:
	T* array_;
	int top_;
	int capacity_;

	//static std::shared_ptr<spdlog::logger> Arraylogger;
};

//template<class T>
//std::shared_ptr<spdlog::logger> StackOnArray<T>::Arraylogger = spdlog::basic_logger_mt("StackOnArray", "logs/basic-log.txt");

template<class T>
StackOnArray<T>::StackOnArray()
{
	Arraylogger->debug("Stack is created");
	capacity_ = 10;
	array_ = new T[capacity_];
	top_ = -1;
}

template<class T>
StackOnArray<T>::~StackOnArray()
{
	Arraylogger->debug("Stack is deleted");
	delete[] array_;
}

template<class T>
void StackOnArray<T>::push(const T& value)
{
	if (top_ == capacity_ - 1) {
		T* new_arr = new T[2 * capacity_];
		for (int i = 0; i <= top_; ++i) {
			new_arr[i] = array_[i];
		}
		delete[] array_;
		array_ = new_arr;
		capacity_ *= 2;
	}
	array_[++top_] = value;
	Arraylogger->debug("Element {0} is pushed", value);
}

template<class T>
T& StackOnArray<T>::top()
{
	if (top_ == -1) {
		Arraylogger->warn("No elements");
		throw std::logic_error("No elements in stack");
	}
	//assert(top_ != -1 && "No elements in stack");
	Arraylogger->debug("Top element in stack is {0}", array_[top_]);
	return array_[top_];
}

template<class T>
T StackOnArray<T>::pop()
{
	if (top_ == -1) {
		Arraylogger->warn("No elements");
		throw std::logic_error("No elements in stack");
	}
	//assert(top_ != -1 && "No elements in stack");
	Arraylogger->debug("Element {0} is poped", array_[top_]);
	T tmp = array_[top_];
	top_--;
	return tmp;
}

template<class T>
bool StackOnArray<T>::isEmpty()
{
	Arraylogger->info("Check stack is empty");
	return (top_ == -1);
}

template<class T>
size_t StackOnArray<T>::size()
{
	Arraylogger->info("Size of stack is {0}", top_ + 1);
	return (top_ + 1);
}

template<class T>
StackOnArray<T>::StackOnArray(const std::initializer_list<T>& list):StackOnArray()
{
	Arraylogger->debug("Initialized stack costr");
	for (const auto element : list) {
		push(element);
	}
}

template<class T>
StackOnArray<T>::StackOnArray(const StackOnArray& other):StackOnArray()
{
	Arraylogger->debug("Copy stack costr");
	capacity_ = other.capacity_;
	top_ = other.top_;
	T* tmp = new T[capacity_];
	for (size_t i = 0; i <= top_; i++) {
		tmp[i] = other.array_[i];
	}
	array_ = tmp;
}

template<class T>
StackOnArray<T>& StackOnArray<T>::operator=(const StackOnArray& other)
{
	Arraylogger->debug("Operator copy stack costr");
	capacity_ = other.capacity_;
	top_ = other.top_;
	T* tmp = new T[capacity_];
	for (size_t i = 0; i <= top_; i++) {
		tmp[i] = other.array_[i];
	}
	array_ = tmp;
}

template<class T>
StackOnArray<T>::StackOnArray(StackOnArray&& moved):StackOnArray()
{
	Arraylogger->debug("Move stack costr");
	capacity_ = moved.capacity_;
	top_ = moved.top_;
	T* tmp = new T[capacity_];
	for (size_t i = 0; i <= top_; i++) {
		tmp[i] = moved.array_[i];
	}
	while (!moved.isEmpty()) {
		moved.pop();
	}
	array_ = tmp;
}

template<class T>
StackOnArray<T>& StackOnArray<T>::operator=(StackOnArray&& moved)
{
	Arraylogger->debug("Move operator stack costr");
	capacity_ = moved.capacity_;
	top_ = moved.top_;
	T* tmp = new T[capacity_];
	for (size_t i = 0; i <= top_; i++) {
		tmp[i] = moved.array_[i];
	}
	while (!moved.isEmpty()) {
		moved.pop();
	}
	array_ = tmp;
}

template<class T>
bool StackOnArray<T>::operator== (const StackOnArray& other)
{
	Arraylogger->info("Check equal stacks");
	if (other.top_ != top_) {
		return false;
	}
	else {
		for (size_t i = 0; i <= top_; ++i) {
			if (array_[i] != other.array_[i]) {
				return false;
			}
		}
	}
	return true;
}
#endif // STACK_ON_ARRAY_H
