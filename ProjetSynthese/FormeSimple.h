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

	virtual void homothetie(const double x, const double y, const double) = 0;
	virtual void rotation(const double x, const double y, const double angle) = 0;
	virtual void translation(const Vecteur2D *v) = 0;

	virtual void accepte(const VisiteurForme *) = 0;
	void accepteSauvegarde(const VisiteurForme *)=0;
};

