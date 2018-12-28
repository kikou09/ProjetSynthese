#include "pch.h"
#include "FormeComposee.h"
#include <vector>
#include "VisiteurForme.h"

FormeComposee::FormeComposee(){}

FormeComposee::FormeComposee(const string &c) : FormeGeometrique(c){}

FormeComposee::FormeComposee(const FormeComposee &forme_c): FormeGeometrique(forme_c.couleur)
{
	groupe = forme_c.groupe;
}

FormeComposee * FormeComposee::clone() const
{
	return new FormeComposee(*this);
}

bool FormeComposee::contient(FormeGeometrique *f)
{
	for (int i = 0; i < groupe.size(); i++) {

		if (f == groupe[i])
			return true;
	}

	return false;
}

void FormeComposee::ajouterForme(FormeGeometrique *forme)
{
	if(!contient(forme))
		groupe.push_back(forme->clone()); //On rajoute la forme à la fin  
}

void FormeComposee::supprimerForme(const int indice)
{
	if (indice<0 || indice > groupe.size())
		throw Erreur("Indice incorrect");

	groupe.erase(groupe.begin() + indice);
}

void FormeComposee::supprimerForme(const FormeGeometrique *forme)
{
	vector<FormeGeometrique *>::iterator it = find(groupe.begin(), groupe.end(), forme);
	groupe.erase(it);
	delete *it;
}


/**
* \brief Effectue l'homothetie de toutes les formes contenues dans la forme composee
* \param[in] v
* \param[in] rapport
*/
FormeComposee * FormeComposee::homothetie(const Vecteur2D &v, const double rapport)const
{
	FormeComposee *groupe2 = new FormeComposee(*this);
	for (int i = 0; i < groupe2->groupe.size(); i++)
	{
		groupe2->groupe[i]->homothetie(v, rapport);
	}
	return groupe2;
}

const double FormeComposee::getAire() const {

	
	vector<FormeGeometrique *>::iterator it;
	double somme_aire = 0;

	/*for (it=groupe.begin() ; it != groupe.end() ; it++)
	{
		//somme_aire += it.getAire();
	}*/

	return somme_aire;


}

/**
* \brief Effectue la rotation de toutes les formes contenues dans la forme composee
* \param[in] v
* \param[in] angle : angle de rotation
*/
FormeComposee * FormeComposee::rotation(const Vecteur2D &v, const double angle)const
{
	FormeComposee *groupe2 = new FormeComposee(*this);
	for (int i = 0; i < groupe2->groupe.size(); i++)
	{
		groupe2->groupe[i]->rotation(v, angle);
	}
	return groupe2;
}


/**
* \brief Effectue la translation de toutes les formes contenues dans la forme composee
* \param[in] v :
*/
FormeComposee * FormeComposee::translation(const Vecteur2D &v)const
{
	FormeComposee *groupe2 = new FormeComposee(*this);
	for (int i = 0; i < groupe2->groupe.size(); i++)
	{
		groupe2->groupe[i]->translation(v);
	}
	return groupe2;
}

FormeComposee::~FormeComposee()
{
	for (int i = 0; i < groupe.size(); i++) {
		delete groupe[i];
	}
	groupe.clear();
}

FormeComposee::operator string() const
{
	return nullptr;
}

void FormeComposee::affiche() const
{
}

void FormeComposee::dessin(const VisiteurForme *visiteur)const
{
	return visiteur->dessiner(this);
}

