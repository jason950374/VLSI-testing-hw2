#include "Matrix.h"
#include <iostream>

using namespace std;

template <class T> Matrix<T>::Matrix(int sizeRow, int sizeCLM) {
	elements = new T[sizeRow][sizeCLM];
	this->sizeRow = sizeRow;
	this->sizeCLM = sizeCLM;
}

template <class T> Matrix<T>::Matrix(T ** elements, int sizeRow, int sizeCLM) {
	this->elements = elements;
	this->sizeRow = sizeRow;
	this->sizeCLM = sizeCLM
}

template<class T> Matrix<T>::Matrix(const Matrix & M)
{
	elements = T[sizeRow][sizeCLM];
	sizeRow = M.sizeRow;
	sizeCLM = M.sizeCLM;
	for (int row = 0; row < sizeRow; row++) {
		for (int clm = 0; clm < sizeCLM; clm++) {
			elements[row][clm] = M.elements[row][clm];
		}
	}
}

template<class T> Matrix<T>::~Matrix()
{
	delete elements;
}

template<class T> Matrix<T> Matrix<T>::operator*(const Matrix & m2)
{
	if (sizeCLM != m2.sizeRow) {
		cerr << "matrix size mismatch" << endl; return;
	}
	Matrix<T> newM = Matrix<T>(sizeRow, m2.sizeCLM);

	for (int row = 0; row < sizeRow; row++) {
		for (int clm = 0; clm < m2.sizeCLM; clm++) {
			newM.elements[row][clm] = 0;
			for (int sumCnt = 0; sumCnt < sizeCLM; sumCnt++) {
				newM.elements[row][clm] += (elements[row][sumCnt] * m2.elements[sumCnt][clm]);
			}
		}
	}
	return newM;
}

template<class T> Matrix<T> Matrix<T>::operator+(const Matrix & m2)
{
	if ((sizeRow != m2.sizeRow) || (sizeCLM != m2.sizeCLM)) {
		cerr << "matrix size mismatch" << endl;
	}

	Matrix<T> newM = Matrix<T>(sizeRow, m2.sizeCLM);
	for (int row = 0; row < sizeRow; row++) {
		for (int clm = 0; clm < sizeCLM; clm++) {
			newM.elements[row][clm] = elements[row][clm] + m2.elements[row][clm];
		}
	}
	return newM;
}

