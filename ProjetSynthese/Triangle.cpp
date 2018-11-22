#include "pch.h"
#include "Triangle.h"
#include <sstream>

Triangle::Triangle() : FormeSimple("black"), base(), cote(){}

Triangle::Triangle(string & couleur, const Vecteur2D &b, const Vecteur2D &c) : FormeSimple(couleur) , base(b) , cote(c)
{
}

Triangle::Triangle(const Triangle &triangle): FormeSimple(triangle) , base(triangle.base), cote(triangle.cote){}

Triangle::~Triangle(){}

Triangle * Triangle::clone() const
{
	return new Triangle(*this);
}

void Triangle::setCote(const Vecteur2D &c) throw (Erreur)
{
	if (cote != c) {
		cote = c;
	}

}

void Triangle::setBase(const Vecteur2D &b) throw (Erreur)
{
	if (base != b) {
		base = b;
	}
}

Triangle::operator string() const {

	ostringstream os;
	os << "( " << &base << ", " << &cote << "," << couleur << ")";
	return os.str();
}

void Triangle::affiche() const
{
	cout << "Couleur : " << couleur << " cote 1 x:" << base.getX() << "y: " << base.getY() << "cote 2 x:" << cote.getX() << " y:" << cote.getY() << endl;
}

bool Triangle::operator==(const Triangle &t) const
{
	if(FormeGeometrique::operator==(t))
		return (base == t.base && cote == t.cote);
}

void Triangle::operator=(const Triangle &t)
{
	if (this != &t) {
		setBase(t.base);
		setCote(t.cote);
	}
}

void Triangle::accepte(const VisiteurForme *visiteur)
{
	visiteur->visite(this);
}

void Triangle::accepteSauvegarde(const VisiteurForme *visiteur)
{
	visiteur->sauvegarde(this);
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

/**
* \brief Fonction qui calcul le determinant du triangle 
* \return la valeur du determinant (double)
*/
const double Triangle::getDeterminant() const {

	return base.getX()*cote.getY() - base.getY()*cote.getX();
}

/**
* \brief Effectue l'homothetie du triangle
* \param[in] x 
* \param[in] y
* \param[in] rapport
*/
void Triangle::homothetie(const double x, const double y, const double rapport)
{

}


/**
* \brief Effectue la rotation du triangle
* \param[in] x
* \param[in] y
* \param[in] angle : angle de rotation
*/
void Triangle::rotation(const double x, const double y, const double angle)
{
}


/**
* \brief Effectue la translation du triangle
* \param[in] v :
*/
void Triangle::translation(const Vecteur2D * v)
{
}

istream & operator>>(istream & is, Triangle &triangle)
{
	Vecteur2D base;
	Vecteur2D cote;
	double xa, xb, ya, yb;

	//cin >> base;
	//cin >> cote;

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