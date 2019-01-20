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
	groupe.clear();
	for (int i = 0; i < forme_c.groupe.size(); i++) {

		this->ajouterForme(forme_c.groupe[i]);

	}

}

FormeComposee * FormeComposee::clone() const
{
	return new FormeComposee(*this);
}

bool FormeComposee::contient(const FormeGeometrique *f)const
{
	for (int i = 0; i < groupe.size(); i++) {

		if (f == groupe[i])
			return true;
	}

	return false;
}

void FormeComposee::ajouterForme(const FormeGeometrique *forme)
{

	if(!contient(forme))
		groupe.push_back(forme->clone()); //On rajoute la forme à la fin 

	for (int i = 0; i < groupe.size(); i++) {
		groupe[i]->setCouleur(forme->getCouleur());
	}
	couleur = forme->getCouleur();

	
}

void FormeComposee::supprimerForme(const int indice)
{
	if (indice<0 || indice > groupe.size())
		throw Erreur("Indice incorrect");

	FormeGeometrique *forme = groupe.at(indice) ;
	groupe.erase(groupe.begin() + indice);
	delete forme;
}

void FormeComposee::supprimerForme(const FormeGeometrique *forme)
{
	vector<FormeGeometrique *>::iterator it = find(groupe.begin(), groupe.end(), forme);
	groupe.erase(it);
	delete *it;
}

const int FormeComposee::getNbForme() const
{
	return (int)groupe.size();
}

const FormeGeometrique * FormeComposee::getForme(const int indice) const
{
	if (indice < 0 || indice > groupe.size())
		throw Erreur("indice incorrect");
	return groupe[indice];
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

void FormeComposee::homothetie2(const Vecteur2D & v, const double rapport)
{
	FormeComposee * homothetie = this->homothetie(v, rapport);
	*this = *homothetie;
}

const double FormeComposee::getAire() const {

	
	int i;
	double somme_aire = 0;

	for (i=0 ; i<groupe.size() ; i++)
	{
		somme_aire += groupe[i]->getAire();
	}

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

void FormeComposee::rotation2(const Vecteur2D & v, const double angle)
{
	FormeComposee* rotation = this->rotation(v, angle);
	*this = *rotation;
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

void FormeComposee::translation2(const Vecteur2D & v)
{
	FormeComposee* translation = this->translation(v);
	*this = *translation;
}

FormeComposee::~FormeComposee()
{
	for (int i = 1; i < groupe.size(); i++) {
		delete groupe[i];
	}
	groupe.clear();
}

FormeComposee::operator string() const
{
	ostringstream os;
	os << "Forme Composee;"<< couleur << ";";
	for (int i = 0; i < groupe.size()-1; i++) {
		os << *groupe[i]<< ";";
	}

	os << *groupe[groupe.size()-1];
	os << ";/";

	return os.str();
}

void FormeComposee::affiche() const
{
	cout << string(*this);
}

void FormeComposee::dessin(const VisiteurForme *visiteur)const
{
	visiteur->dessiner(this);
}

FormeComposee & FormeComposee::operator=(const FormeComposee &fc)
{
	if (this != &fc) {

		this->couleur = fc.getCouleur();
		this->groupe = fc.groupe;
	}

	return *this;
}
