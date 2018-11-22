#pragma once
#include <iostream>
#include "VisiteurForme.h"

using namespace std;

template <class T>
inline const T operator - (const T & u, const T & v)
{
	return u + -v;
}

/**
* \class Vecteur2D
* \brief Classe Vecteur2D qui mod�lise un vecteur en 2D par un point x,y
*/
class Vecteur2D 
{
public:
	
	double x, y;

	Vecteur2D(const double & x = 0, const double & y = 0);

	/**
	 * DONNEES : s respectant le format "(  nombre r�el, nombre r�el)"
	 *
	 * */
	Vecteur2D(const char * s);
	Vecteur2D(const Vecteur2D &);
	Vecteur2D*  clone() const;

	const Vecteur2D operator + (const Vecteur2D & u) const;
	const Vecteur2D operator * (const double & a) const;
	bool operator ==(const Vecteur2D &)const;
	bool operator != (const Vecteur2D &v)const { return !(this == &v); }
	/**
	 * - unaire (c'est-�- dire oppos� d'un vecteur)
	 * */
	const Vecteur2D operator - () const;

	const double getAire() const;
	const double getX() const;
	const double getY() const;

	void setX(const double x);
	void setY(const double y);

	virtual void homothetie(const double x, const double y, const double rapport);
	virtual void rotation(const double x, const double y, const double angle);
	virtual void translation(const Vecteur2D *v);

	operator string() const;
	friend ostream & operator << (ostream &os ,const Vecteur2D &u);
	friend istream & operator >>(istream &is, const Vecteur2D &u);

	void accepte(const VisiteurForme *);
	void accepteSauvegarde(const VisiteurForme *);
}; 



