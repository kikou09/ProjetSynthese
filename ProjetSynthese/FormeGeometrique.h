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

	bool operator == (const FormeGeometrique &)const;
	bool operator != (const FormeGeometrique &f)const { return !(this == &f); }
	void operator = (const FormeGeometrique &);
	operator string() const;
	friend ostream & operator << (ostream &os, const FormeGeometrique &);


};

