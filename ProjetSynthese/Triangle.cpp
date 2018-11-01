#include "pch.h"
#include "Triangle.h"
#include <sstream>

Triangle::Triangle(const Triangle &triangle): FormeSimple(triangle) , base(triangle.base), cote(triangle.cote)
{
}

Triangle::~Triangle(){

	delete base;
	delete cote;
}

void Triangle::setCote(Vecteur2D *c) throw (Erreur)
{
	if (c == NULL)
		throw Erreur("Pointeur null");
	else {
		if (cote != c) {
			delete cote;
			cote = new Vecteur2D(*c);
		}
	}
}

void Triangle::setBase(Vecteur2D *b) throw (Erreur)
{
	if (b == NULL)
		throw Erreur("Pointeur null");
	else {
		if (base != b) {
			delete base;
			base = new Vecteur2D(*b);
		}
	}
}

Triangle::operator string() const {

	ostringstream os;
	os << "( " << &base << ", " << &cote << "," << couleur << ")";
	return os.str();
}

bool Triangle::operator==(const Triangle &t) const
{
	return (base == t.base && cote == t.cote);
}

void Triangle::operator=(const Triangle &t)
{
	if (this != &t) {
		setBase(t.base);
		setCote(t.cote);
	}
}

ostream & operator << (ostream & os, const Triangle &t)
{
	string v = (string)t;
	os << v;
	return os;
}

const double Triangle::getAire() const {

	return 0.5*getDeterminant();
}

const double Triangle::getDeterminant() const {

	return base->getX()*cote->getY() - base->getY()*cote->getX();
}

void Triangle::homothetie(const double x, const double y, const double rapport)
{

}

void Triangle::rotation(const double x, const double y, const double angle)
{
}

void Triangle::translation(const Vecteur2D * v)
{
}
