#include "pch.h"
#include "Cercle.h"
#include "VisiteurForme.h"


Cercle::Cercle(const string &c, const Vecteur2D &centre, const double r) : FormeSimple(c), centre(centre)
{
	try {
		setRayon(r);
		setCentre(centre);
	}
	catch (Erreur e)
	{
		cerr << e;
	}
}

Cercle::Cercle(const Cercle &cercle): FormeSimple(cercle){

	try {
		setCentre(cercle.centre);
		setRayon(cercle.rayon);
	}
	catch (Erreur e) {

		cerr << e.getMessage();
	}
}

Cercle::Cercle() : FormeSimple("black"), rayon(1)
{
}

Cercle::~Cercle()
{
}

Cercle * Cercle::clone() const
{
	return new Cercle(*this);
}

const double Cercle::getAire() const
{
	return 3.14159265359 * rayon*rayon;
}

const Vecteur2D & Cercle::getCentre() const
{
	return centre;
}

const double Cercle::getRayon() const
{
	return rayon;
}

void Cercle::setCentre(const Vecteur2D &c)
{
	/*if (c.getX() < -1 || c.getX() > 20)
		throw Erreur("x doit être entre -1 et 20\n");
	if (c.getY() < -1 || c.getY() > 10)
		throw Erreur("y doit être entre -1 et 10\n");*/
	
	centre = c;
}

void Cercle::setRayon(const double r)
{
	/*if (rayon <= 0 && rayon > 25)
		throw Erreur("Le rayon doit être entre 0 et 25 \n");*/
	rayon = r;
}

/**
* \brief Effectue l'homothetie du cercle
* \param[in] v
* \param[in] rapport
*/
Cercle * Cercle::homothetie(const Vecteur2D &v, const double rapport)const
{
	Vecteur2D * c = &centre.homothetie(v, rapport);
	Cercle* cercle = new Cercle(couleur, *c, rayon * rapport);
	return cercle;
}
void Cercle::homothetie2(const Vecteur2D & v, const double rapport)
{
	Cercle * homothetie = this->homothetie(v, rapport);
	*this = *homothetie;
}

/**
* \brief Effectue la rotation du cercle
* \param[in] v
* \param[in] angle : angle de rotation
*/
Cercle * Cercle::rotation(const Vecteur2D &v, const double angle)const
{
	Vecteur2D * c = &centre.rotation(v, angle);
	Cercle* cercle = new Cercle(couleur, *c, rayon);
	//delete c;
	return cercle;
}
void Cercle::rotation2(const Vecteur2D &v, const double d)
{
	Cercle* rotation = this->rotation(v, d);
	*this = *rotation;
	//delete rotation;
}

/**
* \brief Effectue la translation du cercle
* \param[in] v :
*/
Cercle * Cercle::translation(const Vecteur2D &v)const
{
	Vecteur2D*c = &centre.translation(v);
	Cercle* cercle = new Cercle(couleur, *c, rayon);
	//delete c;
	return cercle;
}
void Cercle::translation2(const Vecteur2D & v)
{
	Cercle* translation = this->translation(v);
	*this = *translation;
}

void Cercle::operator=(const Cercle &c)
{
	if (this != &c) {

		setCentre(c.centre);
		setRayon(c.rayon);
	}
}

bool Cercle::operator==(const Cercle &c) const
{
	return(couleur==c.getCouleur() && rayon==c.rayon && centre==c.centre);
}

Cercle::operator string() const
{
	ostringstream oss;
	oss << "Cercle :" << centre.getX() << " " << centre.getY() << " " << rayon << " " << couleur;
	return oss.str();
}

void Cercle::affiche() const
{
	cout << string(*this);
}

void Cercle::dessin(const VisiteurForme *visiteur)const
{
	visiteur->dessiner(this);
}

istream & operator>>(istream & is, Cercle &c)
{
	Vecteur2D centre;
	double rayon;
	string couleur;

	cout << "--Saisie du cercle--" << endl;
	try {
		is >> centre;

		cout << "Saisir le rayon : " << endl;
		is >> rayon;

		cout << "Saisir la couleur : " << endl;
		is >> couleur;

		c.setCentre(centre);
		c.setRayon(rayon);
		c.setCouleur(couleur);
	}
	catch (Erreur e) {

		cerr << e.getMessage();
		cin >> c;
	}

	return is;
	
}
