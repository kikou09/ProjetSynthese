#include "pch.h"
#include "FormeComposee.h"
#include <vector>
#include "VisiteurForme.h"

FormeComposee::FormeComposee(){}

FormeComposee::FormeComposee(const string &c) : FormeGeometrique(c){}

FormeComposee::FormeComposee(const FormeComposee &forme_c): FormeGeometrique(forme_c.couleur)
{
	for (int i = 0; i < groupe.size(); i++) {

		delete groupe[i];
	}
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

	for (int i = 0; i < groupe.size()-1; i++) {

		groupe[i]->setCouleur(forme->getCouleur());
	}

	couleur = forme->getCouleur();

	
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
	FormeComposee *groupe2 = this->clone();
	for (int i = 0; i < groupe2->groupe.size(); i++)
	{
		groupe2->groupe[i]=groupe2->groupe[i]->homothetie(v, rapport);
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
	for (int i = 1; i < groupe.size(); i++) {

		cout << groupe[i];
		delete groupe[i];
	}
	groupe.clear();
}

FormeComposee::operator string() const
{
	ostringstream os;
	os << "Forme Composee [ ";
	for (int i = 0; i < groupe.size(); i++) {

		os << *groupe[i];
	}

	os << "] " << couleur << "\n";

	return os.str();
}

void FormeComposee::affiche() const
{
	cout << string(*this);
}

void FormeComposee::dessin(const VisiteurForme *visiteur)const
{
	return visiteur->dessiner(this);
}

istream & operator>>(istream & is, FormeComposee & fc)
{
	int nbformes;
	int i=0;
	int choix;

	cout << "Combien de formes voulez vous ajouter ? \n";
	is >> nbformes;

	try {

		while (i != nbformes && (choix >5 || choix <1)) {

			cout << "Quel forme voulez vous ajouter ?\n";
			cout << "1. Un Cercle\n";
			cout << "2. Un Segment\n";
			cout << "3. Un Triangle\n";
			cout << "4. Un Polygone\n";
			cout << "5. Une forme composee\n";

			is >> choix;

			//obligé de faire un while donc pas bon 

		}


	}
	catch (Erreur e) {

		cerr << e.getMessage();
		cin >> fc;
	}

	return is;
}
