#include "pch.h"
#include "Cercle.h"
#include "VisiteurForme.h"


Cercle::Cercle(const string &c, const Vecteur2D &centre, const double r) : FormeSimple(c), centre(centre)
{
	try {
		rayon = r;
		if (r <= 0) {

			throw Erreur("Le rayon doit être > 0");
		}
	}
	catch (Erreur e)
	{
		cout << e;

	}
}

Cercle::Cercle(const Cercle &cercle): FormeSimple(cercle), centre(cercle.centre) , rayon(cercle.rayon){}

Cercle::Cercle() : FormeSimple("black"), rayon(0)
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
	centre = c;
}

void Cercle::setRayon(const double r)
{
	rayon = r;
}

Cercle * Cercle::homothetie(const Vecteur2D &v, const double rapport)const
{
	Vecteur2D * c = &centre.homothetie(v, rapport);
	cout << &c;
	Cercle* cercle = new Cercle(couleur, *c, rayon * rapport);
	//delete c;
	return cercle;
}

Cercle * Cercle::rotation(const Vecteur2D &v, const double angle)const
{
	Vecteur2D * c = &centre.rotation(v, angle);
	Cercle* cercle = new Cercle(couleur, *c, rayon);
	//delete c;
	return cercle;
}

Cercle * Cercle::translation(const Vecteur2D &v)const
{
	Vecteur2D*c = &centre.translation(v);
	Cercle* cercle = new Cercle(couleur, *c, rayon);
	//delete c;
	return cercle;
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
	oss << "cercle: " << couleur << ", " << centre << ", " << rayon;
	return oss.str();
}

void Cercle::affiche() const
{
	cout << "Couleur : " << couleur << " centre : x:" << centre.getX() << " y:" << centre.getY() << " rayon : " << rayon << endl;
}

void Cercle::dessin(const VisiteurForme *visiteur)const
{
	visiteur->dessiner(this);
}

ostream & operator<<(ostream & os, const FormeGeometrique &cercle)
{
	cercle.affiche();
	return os;
}

istream & operator>>(istream & is, Cercle &c)
{
	Vecteur2D centre;
	double rayon , x ,y;

	cout << "Saisir le point x : " << endl;
	is >> x;
	cout << "Saisir le point y : " << endl;
	is >> y;

	centre.setX(x);
	centre.setY(y);

	cout << "Saisir le rayon : " << endl;
	is >> rayon;
	
	cout << "Saisir la couleur : " << endl;
	is >> c.couleur;

	c.setCentre(centre);
	c.setRayon(rayon);

	return (is);
	
}
