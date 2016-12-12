#include "GaloisField.h"
#include "Matrix.h"
#include <fstream>

using namespace std;

void intializeOutTap(Matrix<GaloisField> * M, int poly);
void intializeInTap(Matrix<GaloisField> * M, int poly);

int main(void) {
	int polyA = 0x000000b1; //1011_0001
	int polyB = 0x00000080; //1000_0000
	Matrix<GaloisField> Reg = Matrix<GaloisField>(8, 1);
	Matrix<GaloisField> TransferOutTap = Matrix<GaloisField>(8, 8);
	Matrix<GaloisField> TransferInTap = Matrix<GaloisField>(8, 8);
	ofstream fsOutTap("OutTap.txt");
	ofstream fsInTap("InTap.txt");

	//intialize
	intializeOutTap(&TransferOutTap, polyA);
	Reg.elements[0][0].value = true;

	for (int i = 0; i < (1<<8); i++) {
		Reg = TransferOutTap * Reg;
		for (int j = 0; j < Reg.sizeRow; j++) {
			fsOutTap << ((Reg.elements)[j][0]).value << ' ';
		}
		fsOutTap << endl;
	}
	fsOutTap.close();
	
	//intialize
	intializeInTap(&TransferInTap, polyA);

	for (int i = 0; i < (1 << 8); i++) {
		Reg = TransferInTap * Reg;
		for (int j = 0; j < Reg.sizeRow; j++) {
			fsInTap << ((Reg.elements)[j][0]).value << ' ';
		}
		fsInTap << endl;
	}
	fsInTap.close();

	return 0;
}

//intialize out-tap architecture Transfer Matrix
//only valid when the elements in Matrix is all false (right after claim)
void intializeOutTap(Matrix<GaloisField> * M, int poly) {
	for (int clm = 0; clm < M->sizeCLM; clm++) {
		M->elements[0][clm] = (poly & (1<< clm)) != 0;
	}
	for (int row = 1, clm = 0; row < M->sizeRow; row++, clm++) {
		M->elements[row][clm] = true;
	}
}

//intialize out-tap architecture Transfer Matrix
//only valid when the elements in Matrix is all false (right after claim)
void intializeInTap(Matrix<GaloisField> * M, int poly) {
	for (int row = 0; row < M->sizeRow; row++) {
		M->elements[row][M->sizeCLM - 1] = (poly & (1 << (M->sizeRow - 1 - row))) != 0;
	}
	for (int row = 1, clm = 0; row < M->sizeRow; row++, clm++) {
		M->elements[row][clm] = true;
	}
}
