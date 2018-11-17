#include "pch.h"
#include "Polygone.h"


Polygone::Polygone()
{
}


Polygone::~Polygone()
{
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
	return 0.0;
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