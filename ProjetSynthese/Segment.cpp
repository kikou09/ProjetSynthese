#include "pch.h"
#include "Segment.h"
#include "Vecteur2D.h"


Segment::Segment() :FormeSimple("black"), pointA(), pointB()
{
}

Segment::Segment(string c, const Vecteur2D &pa, const Vecteur2D &pb): FormeSimple(c) , pointA(pa) , pointB(pb)
{

}

Segment::Segment(const Segment &segment): FormeSimple(segment),pointA(segment.pointA) , pointB(segment.pointB)
{
}


Segment::~Segment()
{
}

const Vecteur2D & Segment::getPointA() const
{
	return pointA;
}

const Vecteur2D & Segment::getPointB() const
{
	return pointB;
}

const double Segment::getAire() const
{
	return 0.0;
}

void Segment::setPointA(const Vecteur2D &pa)
{
	pointA = pa;
}

void Segment::setPointB(const Vecteur2D &pb)
{
	pointB = pb;
}

void Segment::homothetie(const double x, const double y, const double)
{
}

void Segment::rotation(const double x, const double y, const double angle)
{
}

void Segment::translation(const Vecteur2D * v)
{
}

void Segment::operator=(const Segment &segment)
{
	if (this != &segment) {
		couleur = segment.couleur;
		setPointA(segment.pointA);
		setPointB(segment.pointB);
	}
}

bool Segment::operator==(const Segment &segment) const
{
	if (couleur == segment.couleur)
		if (pointA == segment.pointA && pointB == segment.pointB)
			return true;
	return false;
}

Segment::operator string() const
{
	return nullptr;
}

void Segment::affiche() const
{
	cout << "Couleur : " << couleur << "point A x:" << pointA.getX() << " y:" << pointA.getY() << " point B x:" << pointB.getX() << " y:" << pointB.getY() << endl;
}

ostream & operator<<(ostream & os, const Segment &)
{
	return os;
}

istream & operator>>(istream & is, Segment &segment)
{

	Vecteur2D pointa;
	Vecteur2D pointb;
	double xa, xb, ya, yb;
	
	cout << "Saisir le point x  du point A : " << endl;
	is >> xa;
	cout << "Saisir le point y du point A : " << endl;
	is >> ya;
	cout << "Saisir le point x  du point B : " << endl;
	is >> xb;
	cout << "Saisir le point y du point B : " << endl;
	is >> yb;

	pointa.setX(xa);
	pointa.setY(ya);

	pointb.setX(xb);
	pointb.setY(yb);

	cout << "Saisir la couleur : " << endl;
	is >> segment.couleur;

	segment.setPointA(pointa);
	segment.setPointB(pointb);

	return (is);
	
}
