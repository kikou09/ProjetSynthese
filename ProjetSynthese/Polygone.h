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
	Polygone(const string &couleur,const Vecteur2D &p1, const Vecteur2D &p2, const Vecteur2D &p3);
	Polygone();
	Polygone(const Polygone &);
	virtual ~Polygone();
	Polygone*  clone() const;

	Vecteur2D * getVecteur(const int indice)const;
	void ajoutVecteur(Vecteur2D *v);
	void supprimerDernier();

	virtual Polygone * homothetie(const Vecteur2D &v,  const double)const ;
	virtual Polygone * rotation(const Vecteur2D &v , const double angle)const;
	virtual Polygone * translation(const Vecteur2D &v)const;

	const double getAire() const;

	void operator =(const Polygone&);
	bool operator ==(const Polygone&)const;
	bool operator != (const Polygone&polygone)const { return !(this == &polygone); }
	operator string() const;
	friend ostream & operator << (ostream &os, const Polygone &);
	friend istream &operator >> (istream& is, const Polygone &);

	void affiche() const;

	void dessin(const VisiteurForme *)const;


};

