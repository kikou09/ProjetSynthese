#pragma once
#include "FormeSimple.h"
#include <math.h>
#include "Vecteur2D.h"
#include <iostream>
#include <sstream>


/**
* \class Cercle
* \brief Classe Cercle qui modélise un cercle et qui dérive de FormeSimple
*/
class Cercle :
	public FormeSimple
{
private:
	Vecteur2D centre; //Centre
	double rayon;
public:
	Cercle(const string &c, const Vecteur2D &centre, const double r);
	Cercle(const Cercle&);
	Cercle();
	virtual ~Cercle();
	Cercle*  clone() const;

	const double getAire() const;
	const Vecteur2D & getCentre() const;
	const double getRayon() const;

	void setCentre(const Vecteur2D &);
	void setRayon(const double);

	virtual Cercle * homothetie(const Vecteur2D & v, const double)const;
	virtual Cercle * rotation(const Vecteur2D &v , const double angle)const;
	virtual Cercle * translation(const Vecteur2D &v)const;

	void operator = (const Cercle&);

	bool operator == (const Cercle &) const;
	bool operator != (const Cercle &cercle) const { return !(this == &cercle); }

	operator string() const;
	void affiche() const;
	friend ostream & operator << (ostream &os, const Cercle &);
	friend istream & operator >> (istream &is, Cercle&);

	void dessin(const VisiteurForme *)const;
	void accepteSauvegarde(const VisiteurForme *);
};

