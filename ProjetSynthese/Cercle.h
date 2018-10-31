#pragma once
#include "FormeSimple.h"
#include <math.h>
#include <iostream>
#include <sstream>

class Cercle :
	public FormeSimple
{
private:
	double x, y; //Centre
	double rayon;
public:
	Cercle(string &c, double x, double y, double r);
	Cercle(const Cercle&);
	Cercle();
	virtual ~Cercle();
	const double getAire() const;

	virtual void homothetie(const double x, const double y, const double);
	virtual void rotation(const double x, const double y, const double angle);
	virtual void translation(const Vecteur2D *v);

	void operator = (const Cercle&);

	bool operator == (const Cercle &) const;
	bool operator != (const Cercle &cercle) const { return !(this == &cercle); }

	operator string() const;
	friend ostream & operator << (ostream &os, const Cercle &);
};

