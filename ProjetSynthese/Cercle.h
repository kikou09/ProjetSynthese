#pragma once
#include "FormeSimple.h"
#include <math.h>
#include "Vecteur2D.h"
#include <iostream>
#include <sstream>

class Cercle :
	public FormeSimple
{
private:
	Vecteur2D centre; //Centre
	double rayon;
public:
	Cercle(string &c, const Vecteur2D &centre, const double r);
	Cercle(const Cercle&);
	Cercle();
	virtual ~Cercle();

	const double getAire() const;
	const Vecteur2D & getCentre() const;
	const double getRayon() const;

	void setCentre(Vecteur2D &);
	void setRayon(const double);

	virtual void homothetie(const double x, const double y, const double);
	virtual void rotation(const double x, const double y, const double angle);
	virtual void translation(const Vecteur2D *v);

	void operator = (const Cercle&);

	bool operator == (const Cercle &) const;
	bool operator != (const Cercle &cercle) const { return !(this == &cercle); }

	operator string() const;
	friend ostream & operator << (ostream &os, const Cercle &);
	friend istream & operator >> (istream &is, Cercle&);
};

