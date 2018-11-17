#pragma once
#include "FormeSimple.h"

/**
* \class Polygone
* \brief Classe Polygone qui mod�lise un polygone et qui d�rive de FormeSimple
*/
class Polygone :
	public FormeSimple
{
public:
	Polygone();
	virtual ~Polygone();

	virtual void homothetie(const double x, const double y, const double);
	virtual void rotation(const double x, const double y, const double angle);
	virtual void translation(const Vecteur2D *v);

	const double getAire() const;

	void operator =(const Polygone&);
	bool operator ==(const Polygone&)const;
	bool operator != (const Polygone&polygone)const { return !(this == &polygone); }
	operator string() const;
	friend ostream & operator << (ostream &os, const Polygone &);
	friend istream &operator >> (istream& is, const Polygone &);

	void affiche() const;

	void accepte(const VisiteurForme *);
	void accepteSauvegarde(const VisiteurForme *);


};

