#include "GaloisField.h"
#include "Matrix.h"

void intializeOutTap(Matrix<GaloisField> * M, int poly);
void intializeInTap(Matrix<GaloisField> * M, int poly);

int main(void) {
	int polyA = 0x000000b1; //1011_0001
	int polyB = 0x00000080; //1000_0000
	Matrix<GaloisField> Reg = Matrix<GaloisField>(8, 1);
	Matrix<GaloisField> TransferM = Matrix<GaloisField>(8, 8);

	//intialize
	intializeOutTap(&TransferM, polyA);

	return 0;
}

//intialize out-tap architecture Transfer Matrix
void intializeOutTap(Matrix<GaloisField> * M, int poly) {
	for (int clm = 0; clm < M->sizeCLM; clm++) {
		M->elements[1][clm] = (poly & (1<< clm)) != 0;
	}
	for (int row = 1, clm = 0; row < M->sizeRow; row++, clm++) {
		M->elements[row][clm] = true;
	}
}

//intialize out-tap architecture Transfer Matrix
void intializeInTap(Matrix<GaloisField> * M, int poly) {
	for (int row = 0; row < M->sizeRow; row++) {
		M->elements[row][4] = (poly & (1 << (M->sizeRow - row))) != 0;
	}
	for (int row = 1, clm = 0; row < M->sizeRow; row++, clm++) {
		M->elements[row][clm] = true;
	}
}