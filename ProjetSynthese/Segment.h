#pragma once
#include "FormeSimple.h"
#include "Vecteur2D.h"

class Segment :
	public FormeSimple
{
private:
	Vecteur2D pointA;
	Vecteur2D pointB;

public:
	Segment();
	Segment(string c, const Vecteur2D &, const Vecteur2D &);
	Segment(const Segment &);
	virtual ~Segment();


	const Vecteur2D & getPointA() const;
	const Vecteur2D & getPointB() const;

	const double getAire()const;

	void setPointA(const Vecteur2D &);
	void setPointB(const Vecteur2D &);

	virtual void homothetie(const double x, const double y, const double);
	virtual void rotation(const double x, const double y, const double angle);
	virtual void translation(const Vecteur2D *v);

	void operator = (const Segment&);

	bool operator == (const Segment &) const;
	bool operator != (const Segment &segment) const { return !(this == &segment); }

	operator string() const;
	void affiche() const;
	friend ostream & operator << (ostream &os, const Segment &);
	friend istream & operator >> (istream &is, Segment&);
};
