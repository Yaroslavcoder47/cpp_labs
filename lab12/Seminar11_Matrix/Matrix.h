#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include <initializer_list>
#include "spdlog/spdlog.h"

template<class T>
class Matrix
{
public:
	Matrix();
	Matrix(const size_t h, const size_t w);
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);
	Matrix(Matrix&& moved) noexcept;
	Matrix& operator=(Matrix&& moved) noexcept;
	~Matrix();

	Matrix(const size_t n); // конструктор единичной матрицы
	Matrix(const size_t n, const std::initializer_list<T> list); // конструктор диагональной матрицы через список инициализации


	size_t getWidth() const;
	size_t getHeight() const;
	T getItem(size_t i, size_t j) const;
	void setItem(size_t i, size_t j, const T value);
	void pushRow(std::vector<T> row);

	Matrix& operator+(const Matrix& other) const;
	Matrix& operator-(const Matrix& other) const;
	Matrix& operator*(const T value) const;
	Matrix& operator*(const Matrix<T>& other) const;
	Matrix& operator/(const T value) const;
	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(const T value);
	Matrix& operator/=(const T value);
	bool operator==(const Matrix& other) const;
	bool operator!=(const Matrix& other) const;

	friend std::ostream& operator<< (std::ostream& stream, const Matrix& matr) {
		spdlog::info("Output of matrix");
		for (size_t i = 0; i < matr.getHeight(); ++i) {
			for (size_t j = 0; j < matr.getWidth(); ++j) {
				stream << matr.getItem(i, j) << " ";
			}
			stream << "\n";
		}
		return stream;
	}

	friend std::istream& operator>> (std::istream& stream, Matrix& matr) {
		spdlog::info("Input of array");
		for (size_t i = 0; i < matr.getHeight(); ++i) {
			for (size_t j = 0; j < matr.getWidth(); ++j) {
				int u;
				stream >> u;
				matr.setItem(i, j, u);
			}	
		}
		return stream;
	}

private:
	T** matrix;
	size_t width;
	size_t height;
};

template<class T>
Matrix<T>::Matrix(const size_t n)
{
	spdlog::info("Constructor identity matrix");
	width = n;
	height = n;
	matrix = new T * [height];
	for (size_t i = 0, j = 0; i < height; ++i, ++j) {
		matrix[i] = new T[width];
	}
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			if (i == j) {
				matrix[i][j] = 1;
				continue;
			}
			matrix[i][j] = 0;
		}
	}
}


template<class T>
Matrix<T>::Matrix(const size_t n, const std::initializer_list<T> list)
{
	spdlog::info("Constructor diagonal matrix");
	if (list.size() != n) {
		spdlog::error("Elements are more than size of matrix");
		throw std::invalid_argument("Number of elements is more than size of matrix");
	}
	width = n;
	height = n;
	matrix = new T * [height];
	for (size_t i = 0, j = 0; i < height; ++i, ++j) {
		matrix[i] = new T[width];
	}
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			if (i == j) {
				matrix[i][j] = *(list.begin() + i);
				continue;
			}
			matrix[i][j] = 0;
		}
	}
}

template<class T>
Matrix<T>::Matrix()
{
	spdlog::info("Default constructor");
	matrix = new T*[1];
	width = 0;
	height = 1;
}

template<class T>
Matrix<T>::Matrix(const size_t h, const size_t w)
{
	spdlog::info("Constructor with parametrs: height {0:d}, width {1:d}", h, w);
	width = w;
	height = h;
	matrix = new T*[height];
	for (size_t i = 0; i < height; ++i) {
		matrix[i] = new T[width];
	}
}

template<class T>
Matrix<T>::Matrix(const Matrix& other)
{
	spdlog::info("Copy constructor");
	width = other.width;
	height = other.height;
	matrix = new T * [height];
	for (size_t i = 0; i < height; ++i) {
		matrix[i] = new T[width];
	}
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			matrix[i][j] = other.matrix[i][j];
		}
	}
}

template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix& other)
{
	spdlog::info("Copy operator constructor");
	width = other.width;
	height = other.height;
	matrix = new T * [height];
	for (size_t i = 0; i < height; ++i) {
		matrix[i] = new T[width];
	}
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			matrix[i][j] = other.matrix[i][j];
		}
	}
	return *this;
}

template<class T>
Matrix<T>::Matrix(Matrix&& moved) noexcept
{
	spdlog::info("Moved constructor");
	width = moved.width;
	height = moved.height;
	matrix = moved.matrix;

	moved.width = 0;
	moved.height = 0;
	moved.matrix = nullptr;
}

template<class T>
Matrix<T>& Matrix<T>::operator=(Matrix&& moved) noexcept
{
	spdlog::info("Moved operator constructor");
	width = moved.width;
	height = moved.height;
	matrix = moved.matrix;

	moved.width = 0;
	moved.height = 0;
	moved.matrix = nullptr;
	return *this;
}

template<class T>
Matrix<T>::~Matrix()
{
	spdlog::info("Destructor of matrix");
	width = 0;
	height = 0;
	matrix = nullptr;
}

template<class T>
size_t Matrix<T>::getWidth() const
{
	spdlog::info("Width of matrix");
	return width;
}

template<class T>
size_t Matrix<T>::getHeight() const
{
	spdlog::info("Height of matrix");
	return height;
}

template<class T>
T Matrix<T>::getItem(size_t i, size_t j) const
{
	spdlog::debug("Get item on position: {0:d}, {1:d}", i, j);
	if (i >= height || j >= width) {
		spdlog::error("Can't get item");
		throw std::out_of_range("Index is out of range");
	}
	return matrix[i][j];
}

template<class T>
void Matrix<T>::setItem(size_t i, size_t j, const T value)
{
	spdlog::debug("Set item on position: {0:d}, {1:d}", i, j);
	if (i >= height || j >= width) {
		spdlog::error("Can't set item");
		throw std::out_of_range("Index is out of range");
	}
	matrix[i][j] = value;
}

template<class T>
void Matrix<T>::pushRow(std::vector<T> row)
{
	spdlog::debug("Row pushed in matrix");
	matrix = new T*[height + 1];
	matrix[height] = new T[row.size()];
	for (size_t i = 0; i < row.size(); ++i) {
		matrix[height][i] = row[i];
	}
	++height;
	width = row.size();
}

template<class T>
Matrix<T>& Matrix<T>::operator+(const Matrix& other) const
{
	spdlog::debug("Operator+ on matrices");
	if (height != other.getHeight() || width != other.getWidth()) {
		spdlog::error("Don't equal matrices");
		throw std::invalid_argument("Matrices must have equal size");
	}
	Matrix<T>* res = new Matrix<T>(other.getHeight(), other.getWidth());
	for (size_t i = 0; i < res->getHeight(); ++i) {
		for (size_t j = 0; j < res->getWidth(); ++j) {
			res->matrix[i][j] = matrix[i][j] + other.matrix[i][j];
		}
	}
	return *res;
}

template<class T>
Matrix<T>& Matrix<T>::operator-(const Matrix& other) const
{
	spdlog::debug("Operator- on matrices");
	if (height != other.getHeight() || width != other.getWidth()) {
		spdlog::error("Don't equal matrices");
		throw std::invalid_argument("Matrices must have equal size");
	}
	Matrix<T>* res = new Matrix<T>(other.getHeight(), other.getWidth());
	for (size_t i = 0; i < res->getHeight(); ++i) {
		for (size_t j = 0; j < res->getWidth(); ++j) {
			res->matrix[i][j] = matrix[i][j] - other.matrix[i][j];
		}
	}
	return *res;
}

template<class T>
Matrix<T>& Matrix<T>::operator*(const T value) const
{
	spdlog::debug("Operator* on matrices");
	Matrix<T>* res = new Matrix<T>(height, width);
	for (size_t i = 0; i < res->getHeight(); ++i) {
		for (size_t j = 0; j < res->getWidth(); ++j) {
			res->matrix[i][j] = matrix[i][j] * value;
		}
	}
	return *res;
}

template<class T>
Matrix<T>& Matrix<T>::operator*(const Matrix<T>& other) const
{
	spdlog::debug("Operator* on two matrices");
	Matrix<T>* res = new Matrix<T>(height, width);
	if (width != other.getHeight()) {
		spdlog::error("Matrices aren't matched");
		throw std::invalid_argument("Matrices must be matched");
	}
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			T tmp = 0;
			for (size_t k = 0, h = 0; k < width; ++k, ++h) {
				tmp += matrix[i][k] * other.getItem(h, j);
			}
			res->setItem(i, j, tmp);
		}
	}
	return *res;
}

template<class T>
Matrix<T>& Matrix<T>::operator/(const T value) const
{
	spdlog::debug("Operator/ on matrices");
	if (value == 0) {
		spdlog::error("Division by zero");
		throw std::invalid_argument("Division by zero");
	}
	Matrix<T>* res = new Matrix<T>(height, width);
	for (size_t i = 0; i < res->getHeight(); ++i) {
		for (size_t j = 0; j < res->getWidth(); ++j) {
			res->matrix[i][j] = matrix[i][j] / value;
		}
	}
	return *res;
}

template<class T>
Matrix<T>& Matrix<T>::operator+=(const Matrix& other)
{
	spdlog::debug("Operator+= on matrices");
	if (height != other.getHeight() || width != other.getWidth()) {
		spdlog::error("Don't equal matrices");
		throw std::invalid_argument("Matrices must have equal size");
	}
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			matrix[i][j] += other.matrix[i][j];
		}
	}
	return *this;
}

template<class T>
Matrix<T>& Matrix<T>::operator-=(const Matrix& other)
{
	spdlog::debug("Operator-= on matrices");
	if (height != other.getHeight() || width != other.getWidth()) {
		spdlog::error("Don't equal matrices");
		throw std::invalid_argument("Matrices must have equal size");
	}
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			matrix[i][j] -= other.matrix[i][j];
		}
	}
	return *this;
}

template<class T>
Matrix<T>& Matrix<T>::operator*=(const T value)
{
	spdlog::debug("Operator*= on matrices");
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			matrix[i][j] *= value;
		}
	}
	return *this;
}

template<class T>
Matrix<T>& Matrix<T>::operator/=(const T value)
{
	spdlog::debug("Operator/= on matrices");
	if (value == 0) {
		spdlog::error("Division by zero");
		throw std::invalid_argument("Division by zero");
	}
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			matrix[i][j] /= value;
		}
	}
	return *this;
}

template<class T>
bool Matrix<T>::operator==(const Matrix& other) const
{
	spdlog::debug("Operator== on matrices");
	if (width != other.getWidth() || height != other.getHeight()) {
		return false;
	}
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			if (matrix[i][j] != other.matrix[i][j]) {
				return false;
			}
		}
	}
	return true;
}

template<class T>
bool Matrix<T>::operator!=(const Matrix& other) const
{
	spdlog::debug("Operator!= on matrices");
	if (width != other.getWidth() || height != other.getHeight()) {
		return true;
	}
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			if (matrix[i][j] != other.matrix[i][j]) {
				return true;
			}
		}
	}
	return false;
}

#endif // !MATRIX_H