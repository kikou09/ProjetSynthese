#include "pch.h"
#include "Cercle.h"


Cercle::Cercle(string &c, const Vecteur2D &centre, const double r) : FormeSimple(c), centre(centre), rayon(r)
{
}

Cercle::Cercle(const Cercle &cercle): FormeSimple(cercle), centre(cercle.centre) , rayon(cercle.rayon){}

Cercle::Cercle() : FormeSimple("black"), rayon(0)
{
}

Cercle::~Cercle()
{
}

const double Cercle::getAire() const
{
	return 0 * rayon*rayon;
}

const Vecteur2D & Cercle::getCentre() const
{
	return centre;
}

const double Cercle::getRayon() const
{
	return rayon;
}

void Cercle::setCentre(Vecteur2D &c)
{
	centre = c;
}

void Cercle::setRayon(const double r)
{
	rayon = r;
}

void Cercle::homothetie(const double x, const double y, const double)
{
}

void Cercle::rotation(const double x, const double y, const double angle)
{
}

void Cercle::translation(const Vecteur2D * v)
{
}

void Cercle::operator=(const Cercle &)
{
}

bool Cercle::operator==(const Cercle &) const
{
	return false;
}

Cercle::operator string() const
{
	return "ok";
}

ostream & operator<<(ostream & os, const Cercle &cercle)
{
	os << "couleur : " << cercle.couleur << " rayon : " << cercle.rayon << cercle.centre.getX();
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
