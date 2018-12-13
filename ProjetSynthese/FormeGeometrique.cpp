#include "pch.h"
#include "FormeGeometrique.h"
#include "VisiteurForme.h"


FormeGeometrique::FormeGeometrique(){}

FormeGeometrique::FormeGeometrique(const FormeGeometrique &forme) : couleur(forme.couleur){}

FormeGeometrique::FormeGeometrique(const string &c)
{
	try {
		couleur = c;
		if (c != "black" && c != "blue" && c != "red" && c != "green" && c != "yellow" && c != "cyan")
			throw Erreur("Couleur incorrecte");
	}
	catch (Erreur e)
	{
		cout << e;

	}
}

FormeGeometrique::~FormeGeometrique(){}

const string FormeGeometrique::getCouleur() const
{
	return couleur;
}

void FormeGeometrique::setCouleur(const string &c)
{
	if (c != "black" || c != "blue" || c != "red" || c != "green" || c != "yellow" || c != "cyan")
		throw Erreur("Couleur incorrecte");
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

void FormeGeometrique::accepteSauvegarde(const VisiteurForme *visiteur) const
{
	visiteur->sauvegarde(this);
}

