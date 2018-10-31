#include "pch.h"
#include "FormeComposee.h"
#include <vector>

FormeComposee::FormeComposee(){}

FormeComposee::FormeComposee(const string &c) : FormeGeometrique(c){}

FormeComposee::FormeComposee(const FormeComposee &forme_c): FormeGeometrique(forme_c.couleur)
{
	groupe = forme_c.groupe;
}

void FormeComposee::ajouterForme(FormeGeometrique *forme)
{
	groupe.push_back(forme); //On rajoute la forme à la fin  
}

void FormeComposee::supprimerForme(const int indice)
{
	groupe.erase(groupe.begin() + indice);
}

void FormeComposee::supprimerForme(const FormeGeometrique *forme)
{
	vector<FormeGeometrique *>::iterator it = find(groupe.begin(), groupe.end(), forme);
	groupe.erase(it);
}

void FormeComposee::homothetie(const double x, const double y, const double rapport)
{
	for (int i = 0; i < groupe.size(); i++)
	{
		groupe[i]->homothetie(x, y, rapport);
	}
}

const double FormeComposee::getAire() const {

	
	vector<FormeGeometrique *>::iterator it;
	double somme_aire = 0;

	for (it=groupe.begin ; it != groupe.end() ; it++)
	{
		somme_aire += it.getAire();
	}

	return somme_aire;


}

void FormeComposee::rotation(const double x, const double y, const double angle)
{
	for (int i = 0; i < groupe.size(); i++)
	{
		groupe[i]->rotation(x, y, angle);
	}
}

void FormeComposee::translation(const Vecteur2D * v)
{
	for (int i = 0; i < groupe.size(); i++)
	{
		groupe[i]->translation(v);
	}
}

FormeComposee::~FormeComposee()
{
	groupe.erase(groupe.begin(), groupe.end());
}
