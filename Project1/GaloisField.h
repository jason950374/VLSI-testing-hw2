#ifndef GALOISFIELD_H
#define GALOISFIELD_H

//I only implement GF(2) here
class GaloisField {
public:
	bool value;

	GaloisField(bool value = false);
	GaloisField operator*(const GaloisField& m2);
	GaloisField operator+(const GaloisField& m2);
};

#endif