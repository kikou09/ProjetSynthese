#pragma once
#include "FormeSimple.h"
#include "Vecteur2D.h"
#include <iostream>

/**
* \class Polygone
* \brief Classe Polygone qui modélise un polygone et qui dérive de FormeSimple
*/
class Polygone :
	public FormeSimple
{
private :
	vector<Vecteur2D *> formes;

public:
	Polygone(string &couleur,const Vecteur2D &p1, const Vecteur2D &p2, const Vecteur2D &p3);
	Polygone();
	Polygone(const Polygone &);
	virtual ~Polygone();
	Polygone*  clone() const;

	Vecteur2D * getVecteur(const int indice)const;
	void ajoutVecteur(Vecteur2D *v);
	void supprimerDernier();

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

