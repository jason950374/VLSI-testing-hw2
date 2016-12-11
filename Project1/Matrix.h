#ifndef MATRIX_H
#define MATRIX_H

template <class T> class Matrix {
public:
	T ** elements;
	int sizeRow;
	int sizeCLM;

	Matrix(int sizeRow, int sizeCLM);
	// To use this constructor, need "new" the elements 
	Matrix(T ** elements, int sizeRow, int sizeCLM);
	// Copy Constructor, for assignment to prevent pointer (T ** elements) aliasing
	Matrix(const Matrix &M);
	~Matrix();
	Matrix operator*(const Matrix& m2);
	Matrix operator+(const Matrix& m2);
};

#endif
