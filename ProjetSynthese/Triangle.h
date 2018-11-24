#pragma once
#include "FormeSimple.h"
#include "Vecteur2D.h"
#include "Erreur.h"
#include <iostream>
#include <stdlib.h>

using namespace std;


/**
* \class Triangle
* \brief Classe Triangle qui mod�lise un triangle et qui d�rive de FormeSimple
*/
class Triangle : public FormeSimple
{
private :
	Vecteur2D p1;
	Vecteur2D p2;
	Vecteur2D p3;
public:
	Triangle();
	Triangle(const string &couleur , const Vecteur2D &pointA , const Vecteur2D &pointB , const Vecteur2D &pointC) throw (Erreur);
	Triangle(const Triangle &);
	virtual ~Triangle();
	Triangle*  clone() const;

	const double getAire() const;
	const double getDeterminant() const;
	void setP1(const Vecteur2D &) throw (Erreur);
	void setP2(const Vecteur2D &) throw (Erreur);
	void setP3(const Vecteur2D &) throw (Erreur);

	virtual Triangle * homothetie(const Vecteur2D &v, const double rapport)const;
	virtual Triangle * rotation(const Vecteur2D &v, const double angle)const;
	virtual Triangle * translation(const Vecteur2D &v)const;

	operator string() const;
	void affiche() const;
	bool operator ==(const Triangle&)const;
	bool operator !=(const Triangle &t)const { return !(this == &t); }
	void operator = (const Triangle &);
	friend ostream &operator << (ostream &f, const Triangle&);
	friend istream & operator>>(istream & is, Triangle &triangle);

	void dessin(const VisiteurForme *)const;
};

