#include "pch.h"
#include "FormeGeometrique.h"
#include "VisiteurSauvegarde.h"

FormeGeometrique::FormeGeometrique(){}

FormeGeometrique::FormeGeometrique(const FormeGeometrique &forme) : couleur(forme.couleur){}

FormeGeometrique::FormeGeometrique(const string &c)
{
	try {
		setCouleur(c);
	}
	catch (Erreur e) {
		
		throw;
	}
}

FormeGeometrique::~FormeGeometrique(){}

void FormeGeometrique::homothetie2(const Vecteur2D &v, const double d)
{
	FormeGeometrique* homothetie = this->homothetie(v, d);
	*this = *homothetie;
}

void FormeGeometrique::translation2(const Vecteur2D &v)
{
	FormeGeometrique* translation = this->translation(v);
	*this = *translation;
}

const string FormeGeometrique::getCouleur() const
{
	return couleur;
}

void FormeGeometrique::setCouleur(const string &c)
{
	if (c.compare("black") != 0 && c.compare("blue") != 0
		&& c.compare("red") != 0 && c.compare("green") != 0
		&& c.compare("yellow") != 0 && c.compare("cyan") != 0) {

		throw Erreur("Couleur incorrecte");

	}


	couleur = c;

}

bool FormeGeometrique::operator==(const FormeGeometrique &forme) const
{
	if (couleur==forme.couleur)
		return true;
	else
		return false;
}

void FormeGeometrique::operator=(const FormeGeometrique &forme)
{
	setCouleur(forme.couleur);
}

void FormeGeometrique::accepteSauvegarde(const VisiteurSauvegarde *visiteur) const
{
	visiteur->sauvegarde(this);
}

ostream & operator << (ostream & os, const FormeGeometrique &f)
{
	string v = string(f);
	os << v;
	return os;

}

void FormeGeometrique::rotation2(const Vecteur2D &v, const double d)
{
	FormeGeometrique* rotation = this->rotation(v, d);
	*this = *rotation;
}
