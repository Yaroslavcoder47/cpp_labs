#pragma once
#ifndef ARRAY_H
#define ARRAY_H

#include <vector>
#include <iostream>
#include <initializer_list>
#include "spdlog/spdlog.h"
#include "ArrayService.h"

template<class T>
class Array : public ArrayService<T>
{
public:
	Array();
	Array(size_t n);
	Array(size_t n, T value);
	Array(const std::initializer_list<T>& list);
	Array(const std::vector<T>& list);

	Array(const Array& other);
	Array& operator=(const Array& other) noexcept;
	Array(Array&& moved) noexcept;
	Array& operator=(Array&& moved) noexcept;
	~Array();

	T getItem(size_t index) const;
	void setItem(size_t index, T value);
	size_t getSize() const;

	//Overloadings of operators
	Array& operator+(const Array& other) const;
	Array& operator+(const T value) const;
	Array& operator-(const Array& other) const;
	Array& operator-(const T value) const;
	Array& operator*(const T value) const;
	Array& operator/(const T value) const;
	Array& operator=(const T value);
	Array& operator+=(const T value);
	Array& operator-=(const T value);
	Array& operator*=(const T value);
	Array& operator/=(const T value);
	bool operator==(const Array& other) const;
	bool operator==(const T value) const;
	bool operator!=(const Array& other) const;
	bool operator!=(const T value) const;
	bool operator<(const Array& other) const;
	bool operator>(const Array& other) const;
	bool operator<=(const Array& other) const;
	bool operator>=(const Array& other) const;
	Array& operator++();
	Array& operator--();
	Array& operator++(int d);
	Array& operator--(int d);

	friend std::ostream& operator<< (std::ostream& stream, const Array<T>& arr) {
		spdlog::info("Output of array");
		for (size_t i = 0; i < arr.getSize(); ++i) {
			stream << arr.getItem(i) << " ";
		}
		return stream;
	}
	
	friend std::istream& operator>> (std::istream& stream, Array<T>& arr) {
		spdlog::info("Input of array");
		for (size_t i = 0; i < arr.getSize(); ++i) {
			stream >> arr.valueList[i];
		}
		return stream;
	}

	T itemSum() override;
	T findMinItem() override;
	T findMaxItem() override;
	int findIndexMinItem() override;
	int findIndexMaxItem() override;

private:
	T* valueList;
	size_t size;
};

template<class T>
Array<T>::Array()
{
	spdlog::info("Constructor default");
	valueList = nullptr;
	size = 0;
}

template<class T>
Array<T>::Array(size_t n)
{
	spdlog::info("Constructor parametric with {0:d}", n);
	size = n;
	valueList = new T[size];
}

template<class T>
Array<T>::Array(size_t n, T value)
{
	spdlog::info("Constructor parametric");
	size = n;
	valueList = new T[size];
	for (size_t i = 0; i < size; ++i) {
		valueList[i] = value;
	}
}

template<class T>
Array<T>::Array(const std::initializer_list<T>& list)
{
	spdlog::info("Constructor initializer_list");
	size = list.size();
	valueList = new T[size];
	size_t i = 0;
	for (const auto& tmp : list) {
		valueList[i] = tmp;
		++i;
	}
}

template<class T>
Array<T>::Array(const std::vector<T>& list)
{
	spdlog::info("Constructor with vector");
	size = list.size();
	valueList = new T[size];
	for (size_t i = 0; i < size; ++i) {
		valueList[i] = list[i];
	}
}

template<class T>
size_t Array<T>::getSize() const
{
	return size;
}

template<class T>
Array<T>::Array(const Array& other) {
	spdlog::info("Copy constructor");
	size = other.size;
	valueList = new T[size];
	for (size_t i = 0; i < size; ++i) {
		valueList[i] = other.getItem(i);
	}
}

template<class T>
Array<T>& Array<T>::operator=(const Array<T>& other) noexcept {
	spdlog::info("Copy constructor operator");
	if (this != &other) {
		delete[] valueList;

		size = other.size;
		valueList = new T[size];
		for (size_t i = 0; i < size; ++i) {
			valueList[i] = other.getItem(i);
		}
	}
	return *this;
}

template<class T>
Array<T>::Array(Array&& moved) noexcept{
	spdlog::info("Moved constructor");
	size = moved.size;
	valueList = moved.valueList;

	moved.size = 0;
	moved.valueList = nullptr;
}

template<class T>
Array<T>& Array<T>::operator=(Array&& moved) noexcept{
	spdlog::info("Moved constructor operator");
	if (this != &moved) {
		delete[] valueList;

		size = moved.size;
		valueList = moved.valueList;

		moved.size = 0;
		moved.valueList = nullptr;
	}

	return *this;	
}

template<class T>
Array<T>::~Array()
{
	spdlog::info("Destructor works");
	if (valueList != nullptr) {
		delete[] valueList;
	}
}

template<class T>
T Array<T>::getItem(size_t index) const
{
	spdlog::debug("Element from position with index {0:d}", index);
	if (index >= size) {
		spdlog::error("Can't get item");
		throw std::runtime_error("Index is out of range");
	}
	return valueList[index];
}

template<class T>
void Array<T>::setItem(size_t index, T value) 
{
	spdlog::debug("Element is set on position {0:d}", index);
	if (index >= size) {
		spdlog::error("Can't set item");
		throw std::runtime_error("Index is out of range");
	}
	valueList[index] = value;
}

template<class T>
Array<T>& Array<T>::operator+(const Array& other) const
{
	spdlog::debug("Operator+ two arrays");
	Array<T>* newArray = new Array<T>(size + other.size);
	for (size_t i = 0; i < size; ++i) {
		newArray->valueList[i] = valueList[i];
	}
	for (size_t i = size, j = 0; i < size + other.size; ++i, ++j) {
		newArray->valueList[i] = other.valueList[j];
	}
	return *newArray;
}

template<class T>
Array<T>& Array<T>::operator+(const T value) const
{
	spdlog::debug("Operator+ array and T");
	Array<T>* newArray = new Array<T>(*this);
	for (size_t i = 0; i < newArray->getSize(); ++i) {
		newArray->valueList[i] += value;
	}
	return *newArray;
}

template<class T>
Array<T>& Array<T>::operator-(const Array& other) const
{
	spdlog::debug("Operator- two arrays");
	if (other.size > size) {
		spdlog::error("Wrong size of array");
		throw std::out_of_range("Size of first array is lower");
	}
	
	Array<T>* newArray = new Array<T>(*this);
	for (size_t i = 0; i < other.size; ++i) {
		newArray->valueList[i] -= other.valueList[i];
	}
	return *newArray;
}

template<class T>
Array<T>& Array<T>::operator-(const T value) const
{
	spdlog::debug("Operator- array and T");
	Array<T>* newArray = new Array<T>(*this);
	for (size_t i = 0; i < newArray->getSize(); ++i) {
		newArray->valueList[i] -= value;
	}
	return *newArray;
}

template<class T>
Array<T>& Array<T>::operator*(const T value) const
{
	spdlog::debug("Operator* array and T");
	Array<T>* newArray = new Array<T>(*this);
	for (size_t i = 0; i < newArray->getSize(); ++i) {
		newArray->valueList[i] *= value;
	}
	return *newArray;
}

template<class T>
Array<T>& Array<T>::operator/(const T value) const
{
	spdlog::debug("Operator/ array and T");
	if (value == 0) {
		spdlog::error("Division by zero");
		throw std::invalid_argument("Division by zero");
	}
	Array<T>* newArray = new Array<T>(*this);
	for (size_t i = 0; i < newArray->getSize(); ++i) {
		newArray->valueList[i] /= value;
	}
	return *newArray;
}

template<class T>
Array<T>& Array<T>::operator=(const T value) 
{
	spdlog::debug("Operator= array and T");
	for (size_t i = 0; i < size; ++i) {
		valueList[i] = value;
	}
	return *this;
}

template<class T>
Array<T>& Array<T>::operator+=(const T value)
{
	spdlog::debug("Operator+= array and T");
	for (size_t i = 0; i < size; ++i) {
		valueList[i] += value;
	}
	return *this;
}

template<class T>
Array<T>& Array<T>::operator-=(const T value)
{
	spdlog::debug("Operator-= array and T");
	for (size_t i = 0; i < size; ++i) {
		valueList[i] -= value;
	}
	return *this;
}

template<class T>
Array<T>& Array<T>::operator*=(const T value)
{
	spdlog::debug("Operator*= array and T");
	for (size_t i = 0; i < size; ++i) {
		valueList[i] *= value;
	}
	return *this;
}

template<class T>
Array<T>& Array<T>::operator/=(const T value)
{
	spdlog::debug("Operator/= array and T");
	if (value == 0) {
		spdlog::error("Division by zero");
		throw std::invalid_argument("Division by zero");
	}
	for (size_t i = 0; i < size; ++i) {
		valueList[i] /= value;
	}
	return *this;
}

template<class T>
bool Array<T>::operator==(const Array& other) const
{
	spdlog::debug("Operator== equal of two arrays");
	if (size != other.size) {
		return false;
	}
	for (size_t i = 0; i < size; ++i) {
		if (valueList[i] != other.valueList[i]) {
			return false;
		}
	}
	return true;
}

template<class T>
bool Array<T>::operator==(const T value) const
{
	spdlog::debug("Operator== equal of array and T");
	for (size_t i = 0; i < size; ++i) {
		if (valueList[i] != value) {
			return false;
		}
	}
	return true;
}


template<class T>
bool Array<T>::operator!=(const Array& other) const
{
	spdlog::debug("Operator!= equal of two arrays");
	if (size != other.size) {
		return true;
	}
	for (size_t i = 0; i < size; ++i) {
		if (valueList[i] != other.valueList[i]) {
			return true;
		}
	}
	return false;
}

template<class T>
bool Array<T>::operator!=(const T value) const
{
	spdlog::debug("Operator!= equal of array and T");
	for (size_t i = 0; i < size; ++i) {
		if (valueList[i] != value) {
			return true;
		}
	}
	return false;
}

template<class T>
bool Array<T>::operator<(const Array& other) const
{
	spdlog::debug("Operator< of two arrays");
	if (size != other.size) {
		spdlog::error("Different size of arrays");
		throw std::out_of_range("Arrays are not equal");
	}
	for (size_t i = 0; i < size; ++i) {
		if (valueList[i] >= other.valueList[i]) {
			return false;
		}
	}
	return true;
}

template<class T>
bool Array<T>::operator>(const Array& other) const
{
	spdlog::debug("Operator> of two arrays");
	if (size != other.size) {
		spdlog::error("Different size of arrays");
		throw std::out_of_range("Arrays are not equal");
	}
	for (size_t i = 0; i < size; ++i) {
		if (valueList[i] <= other.valueList[i]) {
			return false;
		}
	}
	return true;
}

template<class T>
bool Array<T>::operator<=(const Array& other) const
{
	spdlog::debug("Operator<= of two arrays");
	if (size != other.size) {
		spdlog::error("Different size of arrays");
		throw std::out_of_range("Arrays are not equal");
	}
	for (size_t i = 0; i < size; ++i) {
		if (valueList[i] > other.valueList[i]) {
			return false;
		}
	}
	return true;
}

template<class T>
bool Array<T>::operator>=(const Array& other) const
{
	spdlog::debug("Operator>= of two arrays");
	if (size != other.size) {
		spdlog::error("Different size of arrays");
		throw std::out_of_range("Arrays are not equal");
	}
	for (size_t i = 0; i < size; ++i) {
		if (valueList[i] < other.valueList[i]) {
			return false;
		}
	}
	return true;
}

template<class T>
Array<T>& Array<T>::operator++()
{
	spdlog::debug("Operator++ on array");
	for (size_t i = 0; i < size; ++i) {
		valueList[i]++;
	}
	return *this;
}

template<class T>
Array<T>& Array<T>::operator--()
{
	spdlog::debug("Operator-- on array");
	for (size_t i = 0; i < size; ++i) {
		valueList[i]--;
	}
	return *this;
}

template<class T>
Array<T>& Array<T>::operator++(int d)
{
	spdlog::debug("Operator++ on array");
	for (size_t i = 0; i < size; ++i) {
		valueList[i]++;
	}
	return *this;
}

template<class T>
Array<T>& Array<T>::operator--(int d)
{
	spdlog::debug("Operator-- on array");
	for (size_t i = 0; i < size; ++i) {
		valueList[i]--;
	}
	return *this;
}

template<class T>
T Array<T>::itemSum() {
	spdlog::debug("Sum of items");
	T sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += valueList[i];
	}
	return sum;
}

template<class T>
T Array<T>::findMinItem(){
	spdlog::debug("Min item in array");
	T minItem = valueList[0];
	for (size_t i = 1; i < size; ++i) {
		if (valueList[i] < minItem) {
			minItem = valueList[i];
		}
	}
	return minItem;
}

template<class T>
T Array<T>::findMaxItem() {
	spdlog::debug("Max item in array");
	T maxItem = valueList[0];
	for (size_t i = 1; i < size; ++i) {
		if (valueList[i] > maxItem) {
			maxItem = valueList[i];
		}
	}
	return maxItem;
}

template<class T>
int Array<T>::findIndexMinItem() {
	spdlog::debug("Index of min item in array");
	T minIndex = 0;
	T minItem = valueList[0];
	for (size_t i = 1; i < size; ++i) {
		if (valueList[i] < minItem) {
			minIndex = i;
			minItem = valueList[i];
		}
	}
	return minIndex;
}

template<class T>
int Array<T>::findIndexMaxItem() {
	spdlog::debug("Index of max item in array");
	T maxIndex = 0;
	T maxItem = valueList[0];
	for (size_t i = 1; i < size; ++i) {
		if (valueList[i] > maxItem) {
			maxIndex = i;
			maxItem = valueList[i];
		}
	}
	return maxIndex;
}
#endif // ARRAY_H