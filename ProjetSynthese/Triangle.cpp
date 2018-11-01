#include "pch.h"
#include "Triangle.h"
#include <sstream>

Triangle::Triangle() : FormeSimple("black"), base(nullptr), cote(nullptr)
{
}

Triangle::Triangle(string & couleur, Vecteur2D *b, Vecteur2D *c) : FormeSimple(couleur) 
{
	base = b;
	cote = c;
}

Triangle::Triangle(const Triangle &triangle): FormeSimple(triangle) , base(triangle.base), cote(triangle.cote)
{
}

Triangle::~Triangle(){

	delete base;
	delete cote;
}

void Triangle::setCote(Vecteur2D &c) throw (Erreur)
{
	if (cote != &c) {
		delete cote;
		cote = new Vecteur2D(c);
	}

}

void Triangle::setBase(Vecteur2D &b) throw (Erreur)
{
	if (base != &b) {
		delete base;
		base = new Vecteur2D(b);
	}
}

Triangle::operator string() const {

	ostringstream os;
	os << "( " << &base << ", " << &cote << "," << couleur << ")";
	return os.str();
}

void Triangle::affiche() const
{
	cout << "Couleur : " << couleur << " cote 1 x:" << base->getX() << "y: " << base->getY() << "cote 2 x:" << cote->getX() << " y:" << cote->getY() << endl;
}

bool Triangle::operator==(const Triangle &t) const
{
	if(FormeGeometrique::operator==(t))
		return (base == t.base && cote == t.cote);
}

void Triangle::operator=(const Triangle &t)
{
	if (this != &t) {
		setBase(*t.base);
		setCote(*t.cote);
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

istream & operator>>(istream & is, Triangle &triangle)
{

	Vecteur2D base;
	Vecteur2D cote;
	double xa, xb, ya, yb;

	cout << "Saisir le point x  du premier cote : " << endl;
	is >> xa;
	cout << "Saisir le point y du premier cote : " << endl;
	is >> ya;
	cout << "Saisir le point x  du deuxieme cote : " << endl;
	is >> xb;
	cout << "Saisir le point y du deuxieme cote : " << endl;
	is >> yb;

	base.setX(xa);
	base.setY(ya);

	cote.setX(xb);
	cote.setY(yb);

	cout << "Saisir la couleur : " << endl;
	cin >> triangle.couleur;
	triangle.setBase(base);
	triangle.setCote(cote);

	return (is);

}