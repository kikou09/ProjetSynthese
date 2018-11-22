#include "pch.h"
#include "Polygone.h"


Polygone::Polygone(string &couleur, const Vecteur2D &p1, const Vecteur2D &p2, const Vecteur2D &p3) : FormeSimple(couleur) {

	formes.push_back(&p1);
	formes.push_back(&p2);
	formes.push_back(&p3);
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
	formes.erase(formes.begin(), formes.end());
}


Polygone*  Polygone::clone() const {
	return new Polygone(*this);
}

Vecteur2D * Polygone::getVecteur(const int indice) const
{
	if (indice > formes.size())
		//exception
		return formes[indice];
}

void Polygone::ajoutVecteur(Vecteur2D *v)
{
	formes.push_back(v);
}

void Polygone::supprimerDernier()
{
	Vecteur2D *v = formes.back();
	formes.pop_back();
	delete v;
}

/**
* \brief Effectue l'homothetie du polygone
* \param[in] x
* \param[in] y
* \param[in] rapport
*/
void Polygone::homothetie(const double x, const double y, const double)
{
}


/**
* \brief Effectue la rotation du polygone
* \param[in] x
* \param[in] y
* \param[in] angle : angle de rotation
*/
void Polygone::rotation(const double x, const double y, const double angle)
{
}


/**
* \brief Effectue la translation du polygone
* \param[in] v :
*/
void Polygone::translation(const Vecteur2D * v)
{
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

void Polygone::accepte(const VisiteurForme *visiteur)
{
	visiteur->visite(this);
}

void Polygone::accepteSauvegarde(const VisiteurForme *visiteur)
{
	visiteur->sauvegarde(this);
}

ostream & operator<<(ostream & os, const Polygone &)
{
	os << "ok";
	return os;
}

istream & operator>>(istream & is, Polygone &polygone)
{
	return (is);

}