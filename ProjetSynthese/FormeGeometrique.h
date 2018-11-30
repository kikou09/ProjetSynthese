#pragma once
#include <iostream>
#include "Vecteur2D.h"
#include "Erreur.h"
#include <stdlib.h>
#include <sstream>;
using namespace std;

class VisiteurForme;

/**
* \class FormeGeometrique
* \brief Classe FormeGeometrique qui modélise une forme . Classe mère 
*/
class FormeGeometrique
{
protected :
	string couleur;
public:
	FormeGeometrique();
	FormeGeometrique(const FormeGeometrique &);
	FormeGeometrique(const string &);
	virtual ~FormeGeometrique();

	virtual FormeGeometrique * clone() const= 0;
	virtual FormeGeometrique * homothetie(const Vecteur2D &,const double)const =0;
	virtual FormeGeometrique* rotation(const Vecteur2D &,const double angle)const=0;
	virtual FormeGeometrique *translation(const Vecteur2D &v)const=0;

	virtual const double getAire()const = 0;
	const string getCouleur() const;
	void setCouleur(const string &);

	virtual operator string() const=0;
	virtual void affiche()const = 0;
	bool operator == (const FormeGeometrique &)const;
	bool operator != (const FormeGeometrique &f)const { return !(this == &f); }
	void operator = (const FormeGeometrique &);

	virtual void dessin(const VisiteurForme *)const=0;
	void accepteSauvegarde(const VisiteurForme *visiteur, const string nomFichier)const;


};

