#pragma once
#include "FormeSimple.h"
#include <math.h>
#include "Vecteur2D.h"
#include <iostream>
#include <sstream>

using namespace std;

class VisiteurForme;
class FormeSimple;
/**
* \class Cercle
* \brief Classe Cercle qui modélise un cercle et qui dérive de FormeSimple
*  Le rayon ne peut ni être négatif ni égal à zero.
*/
class Cercle : public FormeSimple
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
	virtual void homothetie2(const Vecteur2D &v, const double);
	virtual Cercle * rotation(const Vecteur2D &v, const double angle)const;
	virtual void rotation2(const Vecteur2D &v, const double angle);
	virtual Cercle * translation(const Vecteur2D &v)const;
	virtual void translation2(const Vecteur2D &v);

	void operator = (const Cercle &c);
	virtual bool operator == (const Cercle &f)const;
	bool operator != (const Cercle &cercle) const { return !(this == &cercle); }

	operator string() const;
	void affiche() const;
	friend istream & operator >> (istream &is, Cercle&);

	/**
	*Methode lié au visiteur DessinJava
	*Accepte le dessin du visiteur
	*/
	void dessin(const VisiteurForme *)const;
	//void accepteSauvegarde(const VisiteurForme *);
};

