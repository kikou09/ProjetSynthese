#pragma once

#include "Vecteur2D.h"
#include <math.h>

class Vecteur2D;

/**
* \class Matrice
* \brief Classe Matrice pour effectuer les transformations géometriques
*/
class Matrice{


private:

	Vecteur2D l1;
	Vecteur2D l2;
public:

	Matrice(const Vecteur2D &v1, const Vecteur2D &v2);
	Matrice(const double & x1, const double &y1, const double &x2, const double &y2);
	const Vecteur2D getL1()const;
	const Vecteur2D getL2()const;
	const Vecteur2D operator *(const Vecteur2D &v);

	/**
	*Matrice rotation à partir de l'angle d mit en radian 
	*Matrice(cos(alpha),-sin(alpha)
			sin(alpha) , cos(alpha))
	*/
	static Matrice getMatriceRotation(const double d);

	virtual ~Matrice() {}

};

