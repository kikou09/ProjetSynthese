#pragma once
#include <iostream>

using namespace std;

template <class T>
inline const T operator - (const T & u, const T & v)
{
	return u + -v;
}

/**
* \class Vecteur2D
* \brief Classe Vecteur2D qui modélise un vecteur en 2D par un point x,y
*/
class Vecteur2D 
{
public:
	
	double x, y;

	Vecteur2D(const double & x = 0, const double & y = 0);

	/**
	 * DONNEES : s respectant le format "(  nombre réel, nombre réel)"
	 *
	 * */
	Vecteur2D(const char * s);
	Vecteur2D(const Vecteur2D &p1, const Vecteur2D &p2);
	Vecteur2D(const Vecteur2D &);
	Vecteur2D*  clone() const;

	const Vecteur2D operator + (const Vecteur2D & u) const;
	const Vecteur2D operator * (const double & a) const;
	double operator * (const Vecteur2D &v)const;

	bool operator ==(const Vecteur2D &)const;
	bool operator != (const Vecteur2D &v)const { return !(this == &v); }
	/**
	 * - unaire (c'est-à- dire opposé d'un vecteur)
	 * */
	const Vecteur2D operator - () const;

	const double getAire() const;
	const double getX() const;
	const double getY() const;

	void setX(const double x);
	void setY(const double y);

	virtual Vecteur2D homothetie(const Vecteur2D &v , const double rapport)const;
	virtual Vecteur2D rotation(const Vecteur2D &v, const double angle)const ;
	virtual Vecteur2D translation(const Vecteur2D &v)const;

	operator string() const;
	friend ostream & operator << (ostream &os ,const Vecteur2D &u);
	friend istream & operator >>(istream &is, Vecteur2D &u);
}; 



