#pragma once
#ifndef STACK_ON_LIST_H
#define STACK_ON_LIST_H

#include <initializer_list>
#include <cassert>
#include <exception>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

auto Listlogger = spdlog::basic_logger_mt("StackOnList", "logs/basic-log.txt");

template<class T>
class StackOnList
{
public:
	StackOnList();
	~StackOnList();
	StackOnList(const std::initializer_list<T>& list);// конструктор списка инициализации
	StackOnList(const StackOnList& other); // конструктор копирования
	StackOnList& operator=(const StackOnList& other);
	StackOnList(StackOnList&& moved); // конструктор перемещения
	StackOnList& operator=(StackOnList&& moved);
	bool operator== (const StackOnList& other);

	bool isEmpty() const; 
	T top() const;
	size_t size() const;
	void push(T value);
	T pop();
	
private:
	struct Node
	{
		//параметризованные конструкторы структуры Node
		Node() : next_(nullptr) {}

		Node(T key, Node* next = nullptr) : key_(key), next_(next) {}
		T key_;
		Node* next_;
	};

	Node* top_;
	
	//static std::shared_ptr<spdlog::logger> Listlogger;

};

//
//template<class T>
//std::shared_ptr<spdlog::logger> StackOnList<T>::Listlogger = spdlog::basic_logger_mt("StackOnList", "logs/basic-log.txt");

template<class T>
StackOnList<T>::StackOnList():top_(nullptr) {
	Listlogger->debug("Stack is created");
}

template<class T>
StackOnList<T>::~StackOnList()
{
	Listlogger->debug("Stack is deleted");
	while (top_) {
		pop();
	}	
}

template<class T>
void StackOnList<T>::push(T value)
{
	Node* tmp = new Node(value, top_);
	top_ = tmp;
	Listlogger->debug("Element {0} is pushed", value);
}

template<class T>
T StackOnList<T>::pop()
{
	if (!top_) {
		Listlogger->warn("No elements");
		throw std::logic_error("No elements in stack");
	}
	//assert(top_ != nullptr && "No elements in stack");
	Listlogger->debug("Element {0} is poped", top_->key_);
	T result = top_->key_;
	top_ = top_->next_;
	return result;
}

template<class T>
bool StackOnList<T>::isEmpty() const
{
	Listlogger->info("Check stack is empty");
	return !top_;
}

template<class T>
T StackOnList<T>::top() const
{
	//assert(top_ != nullptr && "No elements in stack");
	if (!top_) {
		Listlogger->warn("No elements");
		throw std::logic_error ("No elements in stack");
	}
	Listlogger->debug("Top element in stack is {0}", top_->key_);
	return top_->key_;
}

template<class T>
size_t StackOnList<T>::size() const
{
	size_t sizeOfStack = 0;
	StackOnList* tmp = new StackOnList(*this);
	while (!tmp->isEmpty()) {
		tmp->pop();
		sizeOfStack++;
	}
	Listlogger->info("Size of stack is {0}", sizeOfStack);
	return sizeOfStack;
	delete tmp;
}

//реализация конструктора копирования
template<class T>
StackOnList<T>::StackOnList(const StackOnList& other):StackOnList()
{
	Listlogger->debug("Copy stack costr");
	StackOnList* tmp = new StackOnList();
	Node* currentTop = other.top_;
	while (currentTop) {
		tmp->push(currentTop->key_);
		currentTop = currentTop->next_;
	}
	currentTop = tmp->top_;
	while (!tmp->isEmpty()) {
		(*this).push(tmp->pop()); // можно было просто push(tmp.pop());
	}
	delete tmp;
}

template<class T>
StackOnList<T>::StackOnList(const std::initializer_list<T>& list)
{
	Listlogger->debug("Initialized stack costr");
	for (const auto& element : list) {
		push(element);
	}
}

template<class T>
StackOnList<T>& StackOnList<T>::operator=(const StackOnList& other)
{
	Listlogger->debug("Operator copy stack costr");
	StackOnList tmp;
	Node* currentTop = other.top_;
	while (currentTop) {
		tmp.push(currentTop->key_);
		currentTop = currentTop->next_;
	}
	currentTop = tmp.top_;
	while (!tmp.isEmpty()) {
		push(tmp.pop());
	}
	return *this;
}

template<class T>
bool StackOnList<T>::operator== (const StackOnList& other)
{
	Listlogger->info("Check equal stacks");
	StackOnList stack1(*this);
	StackOnList stack2(other);
	if (stack1.size() != stack2.size()) {
		return false;
	}
	while (!stack1.isEmpty()) {
		if (stack1.top() != stack2.top()) {
			return false;
		}
		stack1.pop();
		stack2.pop();
	}
	return true;
}

template<class T>
StackOnList<T>::StackOnList(StackOnList&& moved):StackOnList()
{
	Listlogger->debug("Move stack costr");
	StackOnList* tmp = new StackOnList();
	while (!moved.isEmpty()) {
		tmp->push(moved.pop());
	}
	while (!tmp->isEmpty()) {
		push(tmp->pop()); 
	}
	delete tmp;
}

template<class T>
StackOnList<T>& StackOnList<T>::operator=(StackOnList&& moved)
{
	Listlogger->debug("Move operator stack costr");
	StackOnList* tmp = new StackOnList();
	while (!moved.isEmpty()) {
		tmp->push(moved.pop());
	}
	while (!tmp->isEmpty()) {
		push(tmp->pop());
	}
	return *this;
	delete tmp;
}
#endif // STACK_ON_LIST_H