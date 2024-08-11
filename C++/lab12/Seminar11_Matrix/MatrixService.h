#pragma once
#ifndef MATRIXSERVICE_H
#define MATRIXSERVICE_H
#include <iostream>
#include <vector>
#include "Matrix.h"
#include "spdlog/spdlog.h"

template<class T>
class MatrixService
{
public:
	friend void transposeMatrix(Matrix<T>& matr);
	friend double determinant(Matrix<T>& matr);
    static std::vector<std::vector<double>> makeVectorFromMatrix(Matrix<T>& matr);
    static double determinantOnVector(const std::vector<std::vector<double>>& matrix);
    
    friend void inverseMatrix(Matrix<T>& matr);
    friend Matrix<T>& solveEquation(Matrix<T>& a, Matrix<T>& b);
};

template<class T>
void transposeMatrix(Matrix<T>& matr)
{
    spdlog::info("Transpose of matrix");
	for (size_t i = 0; i < matr.getHeight(); ++i) {
		for (size_t j = i; j < matr.getWidth(); ++j) {
			T tmp = matr.getItem(i, j);
			matr.setItem(i, j, matr.getItem(j, i));
			matr.setItem(j, i, tmp);
		}
	}
}

template<class T>
std::vector<std::vector<double>> MatrixService<T>::makeVectorFromMatrix(Matrix<T>& matr)
{
    spdlog::debug("Function to make vector from matrix");
    size_t size = matr.getWidth();
    std::vector<std::vector<double>> res(size, std::vector<double>(size));
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            res[i][j] = matr.getItem(i, j);
        }
    }
    return res;
}

template<class T>
double MatrixService<T>::determinantOnVector(const std::vector<std::vector<double>>& matrix)
{
    spdlog::debug("Calculate determinant on vector");
    // Рекурсивное вычисление определителя
    size_t size = matrix.size();
    if (size == 1) {
        return matrix[0][0];
    }
    else if (size == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else {
        double det = 0.0;
        for (size_t i = 0; i < size; ++i) {
            // Вычисление минора
            std::vector<std::vector<double>> minor;
            for (size_t j = 1; j < size; ++j) {
                std::vector<double> row;
                for (size_t k = 0; k < size; ++k) {
                    if (k != i) {
                        row.push_back(matrix[j][k]);
                    }
                }
                minor.push_back(row);
            }
            // Рекурсивное вычисление определителя с учетом знака
            det += (i % 2 == 0 ? 1 : -1) * matrix[0][i] * determinantOnVector(minor);
        }
        return det;
    }
}

template<class T>
double determinant(Matrix<T>& matr)
{
    spdlog::info("Determinant of matrix");
    std::vector<std::vector<double>> matrix;
    matrix = MatrixService<T>::makeVectorFromMatrix(matr);
	return MatrixService<T>::determinantOnVector(matrix);
}

template<class T>
void inverseMatrix(Matrix<T>& matr)
{
    spdlog::info("Find inverse matrix");
    if (determinant(matr) == 0.) {
        spdlog::error("Determinant is zero");
        throw std::invalid_argument("Determinant can't be zero");
    }
    // создаем матрицу для заполнения туда алгебраических дополнений элементов исходной матрицы
    Matrix<T> newMatr(matr);
    size_t size = matr.getWidth();
    for (size_t l = 0; l < size; ++l) {
        for (size_t i = 0; i < size; ++i) {
            std::vector<std::vector<double>> minor;
            for (size_t j = 0; j < size; ++j) {
                std::vector<double> row;
                for (size_t k = 0; k < size; ++k) {
                    if (k != i && j != l) {
                        row.push_back(matr.getItem(j, k));
                    }
                }
                if (!row.empty()) {
                    minor.push_back(row);
                }
            }
            newMatr.setItem(i, l, ((i + l) % 2 == 0 ? 1 : -1) * MatrixService<T>::determinantOnVector(minor));
        }
    }
    matr = newMatr * (1 / determinant(matr));
}

template<class T>
Matrix<T>& solveEquation(Matrix<T>& a, Matrix<T>& b)
{
    spdlog::info("Solve matrix equation");
    Matrix<T>* res = new Matrix<T>(a.getHeight(), b.getWidth());
    inverseMatrix(a);
    *res = a * b;
    return *res;
}
    
#endif // !MATRIXSERVICE_H