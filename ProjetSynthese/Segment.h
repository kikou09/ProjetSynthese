#pragma once
#include "FormeSimple.h"
#include "Vecteur2D.h"

using namespace std;

class FormeSimple;
/**
* \class Segment
* \brief Classe Segment qui mod�lise un segment et qui d�rive de FormeSimple
* Un segment est represent� par 2 points
*/
class Segment : public FormeSimple
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
	virtual void homothetie2(const Vecteur2D &v, const double);
	virtual Segment * rotation(const Vecteur2D &, const double angle)const;
	virtual void rotation2(const Vecteur2D &v, const double angle);
	virtual Segment * translation(const Vecteur2D &v)const;
	virtual void translation2(const Vecteur2D &v);

	virtual void operator = (const Segment&);

	virtual bool operator == (const Segment &) const;
	bool operator != (const Segment &segment) const { return !(this == &segment); }

	operator string() const;
	void affiche() const;
	friend istream & operator >> (istream &is, Segment&);

	/**
	*Methode li� au visiteur DessinJava
	*Accepte le dessin du visiteur
	*/
	void dessin(const VisiteurForme *)const;

};

