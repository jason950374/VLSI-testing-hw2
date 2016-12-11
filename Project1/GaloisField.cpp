#include "GaloisField.h"

GaloisField::GaloisField(bool value){
	this->value = value;
}

GaloisField GaloisField::operator*(const GaloisField & m2){
	return GaloisField(value && m2.value);
}

GaloisField GaloisField::operator+(const GaloisField & m2){
	return GaloisField(value != m2.value);
}
