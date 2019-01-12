#include "pch.h"
#include "Segment.h"
#include "Vecteur2D.h"
#include "VisiteurForme.h"
#include <sstream>

Segment::Segment() :FormeSimple("black"), pointA(), pointB()
{
}

Segment::Segment(const string &c, const Vecteur2D &pa, const Vecteur2D &pb): FormeSimple(c) 
{
	try {

		setPointA(pa);
		setPointB(pb);
	}
	catch (Erreur e) {

		throw;
	}
}

Segment::Segment(const Segment &segment): FormeSimple(segment),pointA(segment.pointA) , pointB(segment.pointB)
{
}


Segment::~Segment()
{
}

Segment * Segment::clone() const
{
	return new Segment(*this);
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
	/*if (pa.getX() < -1 || pa.getX()>20)
		throw Erreur("x doit etre entre -1 et 20");
	if (pa.getY() < -1 || pa.getY() > 12)
		throw Erreur("y doit etre entre -1 et 12");*/
	pointA = pa;
}

void Segment::setPointB(const Vecteur2D &pb)
{
	/*if (pb.getX() < -1 || pb.getX() > 20)
		throw Erreur("x doit etre entre -1 et 20");
	if (pb.getY() < -1 || pb.getY() > 12)
		throw Erreur("y doit etre entre -1 et 12");*/
	pointB = pb;
}


/**
* \brief Effectue l'homothetie du segment
* \param[in] x
* \param[in] y
* \param[in] rapport
*/
Segment * Segment::homothetie(const Vecteur2D &v, const double rapport) const 
{
	Vecteur2D *p1 = &pointA.homothetie(v, rapport);
	Vecteur2D *p2 = &pointB.homothetie(v, rapport);
	Segment *s = new Segment(couleur, *p1, *p2);
	return s;

}


/**
* \brief Effectue la rotation du segment
* \param[in] x
* \param[in] y
* \param[in] angle : angle de rotation
*/
Segment *Segment::rotation(const Vecteur2D &v ,const double angle) const
{
	Vecteur2D *p1 = &pointA.rotation(v, angle);
	Vecteur2D *p2 = &pointB.rotation(v, angle);
	Segment *s =new Segment(couleur, *p1, *p2);
	return s;
}


/**
* \brief Effectue la translation du segment
* \param[in] v :
*/
Segment * Segment::translation(const Vecteur2D &v)const
{
	Vecteur2D *p1 = &pointA.translation(v);
	Vecteur2D *p2 = &pointB.translation(v);
	Segment *s =new Segment(couleur, *p1, *p2);
	return s;
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
	ostringstream os;
	os << "Segment :" << pointA.getX() << " " << pointA.getY() << " " << pointB.getX() << " " << pointB.getY() << " " << couleur;
	return os.str();
}

void Segment::affiche() const
{
	cout << string(*this);
}

void Segment::dessin(const VisiteurForme *visiteur)const
{
	visiteur->dessiner(this);
}

istream & operator>>(istream & is, Segment &segment)
{

	Vecteur2D pointa;
	Vecteur2D pointb;
	string couleur;

	try {
		is >> pointa;
		is >> pointb;


		cout << "Saisir la couleur : " << endl;
		is >> couleur;

		segment.setPointA(pointa);
		segment.setPointB(pointb);
		segment.setCouleur(couleur);
	}
	catch (Erreur e) {

		cerr << e.getMessage();
		cin >> segment;
	}

	return (is);
	
}
