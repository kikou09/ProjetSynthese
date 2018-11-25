#pragma once
#include "FormeSimple.h"
#include "Vecteur2D.h"


/**
* \class Segment
* \brief Classe Segment qui modélise un segment et qui dérive de FormeSimple
* Un segment est representé par 2 points
*/
class Segment :
	public FormeSimple
{
private:
	Vecteur2D pointA;
	Vecteur2D pointB;

public:
	Segment();
	Segment(const string &c, const Vecteur2D &, const Vecteur2D &);
	Segment(const Segment &);
	virtual ~Segment();
	Segment*  clone() const;

	const Vecteur2D & getPointA() const;
	const Vecteur2D & getPointB() const;

	const double getAire()const;

	void setPointA(const Vecteur2D &);
	void setPointB(const Vecteur2D &);

	virtual Segment * homothetie(const Vecteur2D &, const double)const;
	virtual Segment * rotation(const Vecteur2D &, const double angle)const;
	virtual Segment * translation(const Vecteur2D &v)const;

	void operator = (const Segment&);

	bool operator == (const Segment &) const;
	bool operator != (const Segment &segment) const { return !(this == &segment); }

	operator string() const;
	void affiche() const;
	friend ostream & operator << (ostream &os, const Segment &);
	friend istream & operator >> (istream &is, Segment&);

	void dessin(const VisiteurForme *)const;

};

