#include "pch.h"
#include "Polygone.h"
#include "VisiteurForme.h"


Polygone::Polygone(const string &couleur, Vecteur2D *p1, Vecteur2D *p2, Vecteur2D *p3) : FormeSimple(couleur) {

	formes.push_back(p1);
	formes.push_back(p2);
	formes.push_back(p3);
}

Polygone::Polygone() 
{
}

Polygone::Polygone(const Polygone &p): FormeSimple(p.couleur)
{
	formes = p.formes;
}


Polygone::~Polygone()
{
	for (int i = 0; i < formes.size(); i++) {

		delete formes[i];
	}
	formes.clear();
}


Polygone*  Polygone::clone() const {
	return new Polygone(*this);
}

Vecteur2D * Polygone::getVecteur(const int indice) const
{
	if (indice > formes.size())
		return nullptr;

	return formes[indice];
}

void Polygone::ajoutVecteur(Vecteur2D *v)
{
	formes.push_back(v->clone());
}

void Polygone::supprimerDernier()
{
	Vecteur2D *v = formes.back();
	formes.pop_back();
	delete v;
}

/**
* \brief Effectue l'homothetie du polygone
* \param[in] v
* \param[in] rapport
*/
Polygone * Polygone::homothetie(const Vecteur2D &v , const double rapport)const
{
	for (int i = 0; i < formes.size(); i++) {

		formes[i]->homothetie(v, rapport);
	}
}


/**
* \brief Effectue la rotation du polygone
* \param[in] v
* \param[in] angle : angle de rotation
*/
Polygone * Polygone::rotation(const Vecteur2D &v, const double angle)const 
{
	for (int i = 0; i < formes.size(); i++) {

		formes[i]->rotation(v, angle);
	}
}


/**
* \brief Effectue la translation du polygone
* \param[in] v :
*/
Polygone * Polygone::translation(const Vecteur2D &v)const
{
	for (int i = 0; i < formes.size(); i++) {

		formes[i]->translation(v);
	}
}

const double Polygone::getAire() const
{
	double somme = 0;
	for (int i = 0; i < formes.size() - 1; i++) {

		somme += (formes[i]->getX()*formes[i + 1]->getY()) - (formes[i + 1]->getX()*formes[i]->getY());
	}

	somme += (formes.back()->getX() * formes[0]->getY()) - (formes[0]->getX()*formes.back()->getY());
	return abs(somme / 2);
}

void Polygone::operator=(const Polygone &)
{
}

bool Polygone::operator==(const Polygone &) const
{
	return false;
}

Polygone::operator string() const
{
	return "ok";
}

void Polygone::affiche() const
{
	cout << "Couleur : " << couleur;
}

void Polygone::dessin(const VisiteurForme *visiteur)const
{
	visiteur->dessiner(this);
}
istream & operator>>(istream & is, Polygone &polygone)
{
	return (is);

}