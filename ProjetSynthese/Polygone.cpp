#include "pch.h"
#include "Polygone.h"
#include "VisiteurForme.h"


Polygone::Polygone(const string &couleur, Vecteur2D *p1, Vecteur2D *p2, Vecteur2D *p3) : FormeSimple(couleur) {

	this->ajoutPoint(p1);
	this->ajoutPoint(p2);
	this->ajoutPoint(p3);
}

Polygone::Polygone() : FormeSimple("black") 
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
		throw Erreur("indice incorrecte\n");

	return formes[indice];
}

void Polygone::ajoutPoint(Vecteur2D *v)
{
	/*if (v->getX() < -1 || v->getX()>20)
		throw Erreur("x doit etre entre -1 et 20\n");
	if (v->getY() < -1 || v->getY() >12)
		throw Erreur("y doit etre entre -1 et 12\n");*/
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
	Polygone *polygone = this->clone();
	for (int i = 0; i < polygone->formes.size(); i++) {

		*polygone->formes[i]=polygone->formes[i]->homothetie(v, rapport);
	}
	return polygone;
}


/**
* \brief Effectue la rotation du polygone
* \param[in] v
* \param[in] angle : angle de rotation
*/
Polygone * Polygone::rotation(const Vecteur2D &v, const double angle)const 
{
	Polygone *polygone = this->clone();
	for (int i = 0; i < polygone->formes.size(); i++) {

		*polygone->formes[i]=polygone->formes[i]->rotation(v, angle);
	}
	return polygone;
}


/**
* \brief Effectue la translation du polygone
* \param[in] v :
*/
Polygone * Polygone::translation(const Vecteur2D &v)const
{
	Polygone *polygone = this->clone();
	for (int i = 0; i < polygone->formes.size(); i++) {

		*polygone->formes[i]=polygone->formes[i]->translation(v);
	}
	return polygone;
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

void Polygone::operator=(const Polygone &p)
{
	if (this != &p) {
		setCouleur(p.couleur);
		for (int i = 0; i < formes.size(); i++) {
			delete formes[i];
		}
		formes = p.formes;
	}
}

bool Polygone::operator==(const Polygone &p) const
{
	if (couleur == p.getCouleur())
	{
		for (int i = 0; i < formes.size(); i++) {

			if (formes[i] != p.formes[i])
				return false;
		}

		return true;
	}
	else
		return false;
}

Polygone::operator string() const
{
	ostringstream os;
	os << "Polygone :";
	for (int i = 0; i < formes.size(); i++) {

		os << formes[i]->getX() << " " << formes[i]->getY() << " ";
	}

	os << couleur << " \n";
	
	return os.str();
}

void Polygone::affiche() const
{
	cout << string(*this);
}

void Polygone::dessin(const VisiteurForme *visiteur)const
{
	visiteur->dessiner(this);
}
istream & operator>>(istream & is, Polygone &polygone)
{
	string couleur;
	int nbpoints;
	Vecteur2D point;
	try {

		cout << "Saisir la couleur du polygone :";
		is >> couleur;

		cout << "Saisir le nombre de points du polygone ( au minimum 3 )\n";
		is >> nbpoints;

		if (nbpoints < 3)
			throw Erreur("Le nombre de points doit etre superieur a 3\n");

		for (int i = 0; i < nbpoints; i++) {

			is >> point;
			polygone.ajoutPoint(&point);
		}

		polygone.setCouleur(couleur);

	}
	catch(Erreur e){

		cerr << e.getMessage();
		cin >> polygone;

	}
	return (is);

}