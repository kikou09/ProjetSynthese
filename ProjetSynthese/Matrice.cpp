#include "pch.h"
#include "Matrice.h"

#define PI 3.14159265359;

Matrice::Matrice(const double & x1, const double &y1, const double &x2, const double &y2) : l1(x1, y1), l2(x2, y2) {}

Matrice::Matrice(const Vecteur2D &v1, const Vecteur2D &v2) : l1(v1), l2(v2) {}

const Vecteur2D Matrice::getL1()const { return l1; }
const Vecteur2D Matrice::getL2()const { return l2; }

const Vecteur2D Matrice::operator *(const Vecteur2D &v) { return Vecteur2D(l1 * v, l2 * v); }

Matrice Matrice::getMatriceRotation(const double d) {

	double alpha = d / 180 * PI;
	Vecteur2D l1(cos(alpha), -sin(alpha));
	Vecteur2D l2(sin(alpha), cos(alpha));

	return Matrice(l1, l2);
}