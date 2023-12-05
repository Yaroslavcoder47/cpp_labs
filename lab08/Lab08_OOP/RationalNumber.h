#pragma once
#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H
#include <iostream>
#include <cmath>
#include <numeric>

template<class T>
class RationalNumber
{
	template<typename U>
	friend void print(const RationalNumber<U>&); // вспомогательная функция вывода в поток cout значения дроби
	template <class Y>
	friend std::ostream& operator<<(std::ostream& os, const RationalNumber<Y>& num);
public:
	void Sum(RationalNumber<T> num);
	void Substraction(RationalNumber<T> num);
	void Division(RationalNumber<T> num);
	void Multiplication(RationalNumber<T> num);

	RationalNumber<T>& operator+ ();
	RationalNumber<T>& operator+ (const RationalNumber<T>& num);
	RationalNumber<T>& operator+ (const T& num1);
	RationalNumber<T>& operator- ();
	RationalNumber<T>& operator- (const RationalNumber<T>& num);
	RationalNumber<T>& operator- (const T& num1);
	RationalNumber<T>& operator* (const RationalNumber<T>& num);
	RationalNumber<T>& operator* (const T& num1);
	RationalNumber<T>& operator/ (const RationalNumber<T>& num);
	RationalNumber<T>& operator/ (const T& num1);
	RationalNumber<T>& operator= (const RationalNumber<T>& num);
	RationalNumber<T>& operator= (const T& num1);
	RationalNumber<T>& operator+= (const RationalNumber<T>& num);
	RationalNumber<T>& operator+= (const T& num1);
	RationalNumber<T>& operator-= (const RationalNumber<T>& num);
	RationalNumber<T>& operator-= (const T& num1);
	RationalNumber<T>& operator*= (const RationalNumber<T>& num);
	RationalNumber<T>& operator*= (const T& num1);
	RationalNumber<T>& operator/= (const RationalNumber<T>& num);
	RationalNumber<T>& operator/= (const T& num1);

	bool operator== (const RationalNumber<T>& num);
	bool operator== (const T& num1);
	bool operator!= (const RationalNumber<T>& num);
	bool operator!= (const T& num1);
	bool operator< (const RationalNumber<T>& num);
	bool operator< (const T& num1);
	bool operator> (const RationalNumber<T>& num);
	bool operator> (const T& num1);
	bool operator<= (const RationalNumber<T>& num);
	bool operator<= (const T& num1);
	bool operator>= (const RationalNumber<T>& num);
	bool operator>= (const T& num1);

	RationalNumber<T>& operator++ ();
	RationalNumber<T>& operator-- ();
	

	RationalNumber() 
	{
		numerator_ = 0;
		denominator_ = 1;
	}
	RationalNumber(int numerator, int denominator) // реализация параметризованного конструктора
	{
		try {
			if (denominator == 0) {
				throw std::invalid_argument("Denominator can't be zero");
			}
			numerator_ = numerator;
			denominator_ = denominator;
		}
		catch (const std::exception& excep) {
			std::cerr << "Error during object creation: " << excep.what() << std::endl;
			exit(0);
		}
	}
	RationalNumber(const RationalNumber<T>& other) // реализация конструктора копирования
	{
		numerator_ = other.numerator_;
		denominator_ = other.denominator_ ;
	}
	
	
private:
	void Reducing();
	T numerator_;
	T denominator_;
};

/// реализация всех функций
static int gcdFunction(int a, int b) // алгоритм поиска НОДа двух чисел
{
	if (b == 0) {
		return a;
	}
	return gcdFunction(b, a % b);
}

template<typename T>
void RationalNumber<T>::Sum(RationalNumber<T> num)
{
	numerator_ = numerator_ * num.denominator_ + denominator_ * num.numerator_;
	denominator_ = num.denominator_ * denominator_;
	Reducing();
}

template<typename T>
void RationalNumber<T>::Substraction(RationalNumber<T> num)
{
	numerator_ = numerator_ * num.denominator_ - denominator_ * num.numerator_;
	denominator_ = num.denominator_ * denominator_;
	Reducing();
}

template<typename T>
void RationalNumber<T>::Division(RationalNumber<T> num)
{
	numerator_ = numerator_ * num.denominator_;
	denominator_ = denominator_ * num.numerator_;
	Reducing();
}

template<typename T>
void RationalNumber<T>::Multiplication(RationalNumber<T> num)
{
	numerator_ = numerator_ * num.numerator_;
	denominator_ = denominator_ * num.denominator_;
	Reducing();
}

template<typename T>
void RationalNumber<T>::Reducing()
{
	int devider = gcdFunction(abs(numerator_), abs(denominator_));
	numerator_ /= devider;
	denominator_ /= devider;
}

template<typename U>
void print(const RationalNumber<U>& num) // метод вывода объекта класса RationalNumber
{
	std::cout << num.numerator_ << '/' << num.denominator_;
}

/// реализация перегрузок операторов
template<typename T>
RationalNumber<T>& RationalNumber<T>::operator+ ()
{
	Reducing();
	return *this;
}

template<typename T>
RationalNumber<T>& RationalNumber<T>::operator+ (const RationalNumber<T>& num)
{
	RationalNumber<T> result(*this);
	result.Sum(num);
	result.Reducing();
	return result;
}

template<typename T>
RationalNumber<T>& RationalNumber<T>::operator+ (const T& num1)
{
	RationalNumber<T> num(num1, 1); 
	num.Sum(*this);
	num.Reducing();
	return num;
}

template<typename T>
RationalNumber<T>& RationalNumber<T>::operator- ()
{
	numerator_ *= -1;
	return *this;
}

template<typename T>
RationalNumber<T>& RationalNumber<T>::operator- (const RationalNumber<T>& num)
{
	RationalNumber<T> result(*this);
	result.Substraction(num);
	result.Reducing();
	return result;
}

template<typename T>
RationalNumber<T>& RationalNumber<T>::operator- (const T& num1)
{
	RationalNumber<T> num(num1, 1);
	RationalNumber<T> result(*this);
	result.Substraction(num);
	result.Reducing();
	return result;
}

template<typename T>
RationalNumber<T>& RationalNumber<T>::operator* (const RationalNumber<T>& num)
{
	RationalNumber<T> result(*this);
	result.Multiplication(num);
	result.Reducing();
	return result;
}

template<typename T>
RationalNumber<T>& RationalNumber<T>::operator* (const T& num1)
{
	RationalNumber<T> result(*this);
	RationalNumber<T> num(num1, 1);
	result.Multiplication(num);
	result.Reducing();
	return result;
}

template<typename T>
RationalNumber<T>& RationalNumber<T>::operator/ (const RationalNumber<T>& num)
{
	RationalNumber<T> result(*this);
	result.Division(num);
	result.Reducing();
	return result;
}

template<typename T>
RationalNumber<T>& RationalNumber<T>::operator/ (const T& num1)
{
	try {
		if (num1 == 0) {
			throw std::invalid_argument("Object can't be zero to make a division");
		}
		RationalNumber<T> result(*this);
		RationalNumber<T> num(num1, 1);
		result.Division(num);
		result.Reducing();
		return result;
	}
	catch (const std::exception& excep) {
		std::cerr << "Error during operation: " << excep.what() << std::endl;
		exit(0);
	}
}

template<typename T>
RationalNumber<T>& RationalNumber<T>::operator= (const RationalNumber<T>& num)
{
	numerator_ = num.numerator_;
	denominator_ = num.denominator_;
	return *this;
}

template<typename T>
RationalNumber<T>& RationalNumber<T>::operator= (const T& num1)
{
	numerator_ = num1;
	denominator_ = 1;
	return *this;

}

template<typename T>
RationalNumber<T>& RationalNumber<T>::operator+= (const RationalNumber<T>& num)
{
	Sum(num);
	return *this;
}

template<typename T>
RationalNumber<T>& RationalNumber<T>::operator+= (const T& num1)
{
	RationalNumber<T> num(num1, 1);
	Sum(num);
	return *this;
}

template<typename T>
RationalNumber<T>& RationalNumber<T>::operator-= (const RationalNumber<T>& num)
{
	Substraction(num);
	return *this;
}

template<typename T>
RationalNumber<T>& RationalNumber<T>::operator-= (const T& num1)
{
	RationalNumber<T> num(num1, 1);
	Substraction(num);
	return *this;
}

template<typename T>
RationalNumber<T>& RationalNumber<T>::operator*= (const RationalNumber<T>& num)
{
	Multiplication(num);
	return *this;
}

template<typename T>
RationalNumber<T>& RationalNumber<T>::operator*= (const T& num1)
{
	RationalNumber<T> num(num1, 1);
	Multiplication(num);
	return *this;
}

template<typename T>
RationalNumber<T>& RationalNumber<T>::operator/= (const RationalNumber<T>& num)
{
	Division(num);
	return *this;
}

template<typename T>
RationalNumber<T>& RationalNumber<T>::operator/= (const T& num1)
{
	try {
		if (num1 == 0) {
			throw std::invalid_argument("Object can't be zero to make a division");
		}
		RationalNumber<T> num(num1, 1);
		Division(num);
		return *this;
	}
	catch (const std::exception& excep) {
		std::cerr << "Error during operation: " << excep.what() << std::endl;
		exit(0);
	}
}

template<typename T>
bool RationalNumber<T>::operator== (const RationalNumber<T>& num) 
{
	return (numerator_ * num.denominator_ == num.numerator_ * denominator_);
}

template<typename T>
bool RationalNumber<T>::operator== (const T& num1)
{
	RationalNumber<T> num(num1, 1);
	return (numerator_ * num.denominator_ == num.numerator_ * denominator_);
}

template<typename T>
bool RationalNumber<T>::operator!= (const RationalNumber<T>& num)
{
	return !(*this == num);
}

template<typename T>
bool RationalNumber<T>::operator!= (const T& num1)
{
	RationalNumber<T> num(num1, 1);
	return !(*this == num);
}

template<typename T>
bool RationalNumber<T>::operator< (const RationalNumber<T>& num)
{
	return (numerator_ * num.denominator_ < num.numerator_ * denominator_);
}

template<typename T>
bool RationalNumber<T>::operator< (const T& num1)
{
	RationalNumber<T> num(num1, 1);
	return (numerator_ * num.denominator_ < num.numerator_ * denominator_);
}

template<typename T>
bool RationalNumber<T>::operator> (const RationalNumber<T>& num)
{
	return (numerator_ * num.denominator_ > num.numerator_ * denominator_);
}

template<typename T>
bool RationalNumber<T>::operator> (const T& num1)
{
	RationalNumber<T> num(num1, 1);
	return (numerator_ * num.denominator_ > num.numerator_ * denominator_);
}

template<typename T>
bool RationalNumber<T>::operator<= (const RationalNumber<T>& num)
{
	return (*this < num || *this == num);
}

template<typename T>
bool RationalNumber<T>::operator<= (const T& num1)
{
	RationalNumber<T> num(num1, 1);
	return (*this < num || *this == num);
}

template<typename T>
bool RationalNumber<T>::operator>= (const RationalNumber<T>& num)
{
	return (*this > num || *this == num);
}

template<typename T>
bool RationalNumber<T>::operator>= (const T& num1)
{
	RationalNumber<T> num(num1, 1);
	return (*this > num || *this == num);
}

template<typename T>
RationalNumber<T>& RationalNumber<T>::operator++ ()
{
	RationalNumber<T> num(1, 1);
	Sum(num);
	return *this;
}

template<typename T>
RationalNumber<T>& RationalNumber<T>::operator-- ()
{
	RationalNumber<T> num(1, 1);
	Substraction(num);
	return *this;
}

template<class Y>
std::ostream& operator<<(std::ostream& os, const RationalNumber<Y>& num)
{
	os << num.numerator_ << "/" << num.denominator_;
	return os;
	os.clear();
}
#endif // RATIONALNUMBER_H
