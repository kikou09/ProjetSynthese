#pragma once
#include <iostream>
#include "Vecteur2D.h"
#include "Erreur.h"
#include <stdlib.h>
#include <sstream>;

using namespace std;

class FormeGeometrique
{
protected :
	string couleur;
public:
	FormeGeometrique();
	FormeGeometrique(const FormeGeometrique &);
	FormeGeometrique(const string &);
	virtual ~FormeGeometrique();
	virtual void homothetie(const double x , const double y ,const double)=0;
	virtual void rotation(const double x, const double y ,const double angle)=0;
	virtual void translation(const Vecteur2D *v)=0;

	virtual const double getAire()const = 0;
	const string getCouleur() const;
	void setCouleur(const string &);

	virtual operator string() const=0;
	virtual void affiche()const = 0;
	bool operator == (const FormeGeometrique &)const;
	bool operator != (const FormeGeometrique &f)const { return !(this == &f); }
	void operator = (const FormeGeometrique &);


};

