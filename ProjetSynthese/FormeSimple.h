#pragma once
#include "FormeGeometrique.h"
class FormeSimple :
	public FormeGeometrique
{
public:
	FormeSimple();
	FormeSimple(const string &);
	FormeSimple(const FormeSimple &);
	virtual ~FormeSimple();

	virtual const double getAire()const = 0;
	virtual operator string() const = 0;
	void affiche() const = 0;

	virtual FormeSimple * homothetie(const Vecteur2D &, const double) const= 0;
	virtual FormeSimple * rotation(const Vecteur2D &, const double angle)const = 0;
	virtual FormeSimple * translation(const Vecteur2D &v) const= 0;

	virtual void accepte(const VisiteurForme *) = 0;
	void accepteSauvegarde(const VisiteurForme *)=0;
};

