#pragma once
#include "FormeSimple.h"
#include "Erreur.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
class Triangle :
	public FormeSimple
{
private :
	Vecteur2D *base;
	Vecteur2D *cote;
public:
	Triangle(string &couleur , const Vecteur2D *b , const Vecteur2D *cote) throw (Erreur);
	Triangle(const Triangle &);
	virtual ~Triangle();
	const double getAire() const;
	const double getDeterminant() const;
	void setCote(Vecteur2D *) throw (Erreur);
	void setBase(Vecteur2D *) throw (Erreur);

	virtual void homothetie(const double x, const double y, const double rapport);
	virtual void rotation(const double x, const double y, const double angle);
	virtual void translation(const Vecteur2D *v);

	operator string() const;
	bool operator ==(const Triangle&)const;
	bool operator !=(const Triangle &t)const { return !(this == &t); }
	void operator = (const Triangle &);
	friend ostream &operator << (ostream &f, const Triangle&);
};

