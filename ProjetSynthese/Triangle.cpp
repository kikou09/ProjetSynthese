#include "pch.h"
#include "Triangle.h"
#include <sstream>
#include "VisiteurForme.h"

Triangle::Triangle() : FormeSimple("black"), p1(), p2(), p3(){}

Triangle::Triangle(const string & couleur, const Vecteur2D &pointA, const Vecteur2D &pointB , const Vecteur2D &pointC) : FormeSimple(couleur)
{
	try {
		setP1(pointA);
		setP2(pointB);
		setP3(pointC);
	}
	catch (Erreur e) {

		throw;
	}

}

Triangle::Triangle(const Triangle &triangle): FormeSimple(triangle){
	try {
		setP1(triangle.p1);
		setP2(triangle.p2);
		setP3(triangle.p3);
	}
	catch (Erreur e) {

		throw;
	}

}

Triangle::~Triangle(){}

Triangle * Triangle::clone() const
{
	return new Triangle(*this);
}

void Triangle::setP1(const Vecteur2D &b)
{
	if (p1 != b) {
		p1 = b;
	}

}

void Triangle::setP2(const Vecteur2D &b)
{
	if (p2 != b) {

		p2 = b;
	}
}

void Triangle::setP3(const Vecteur2D &b) 
{
	if (p3 != b) {

		p3 = b;
	}
}

Triangle::operator string() const {

	ostringstream os;
	os << "Triangle :" << p1.getX() << " " << p1.getY()
		<< " " << p2.getX() << " " << p2.getY()
		<< " " << p3.getX() << " " << p3.getY()
		<< " " << couleur;
	return os.str();
}

void Triangle::affiche() const
{
	cout << string(*this);
}

bool Triangle::operator==(const Triangle &t) const
{
	if (couleur == t.getCouleur())
		return (p1 == t.p1 && p2 == t.p2 && p3 == t.p3);
	else
		return false;
}

void Triangle::operator=(const Triangle &t)
{
	if (this != &t) {
		setCouleur(t.couleur);
		setP1(t.p1);
		setP2(t.p2);
		setP3(t.p3);
	}
}

void Triangle::dessin(const VisiteurForme *visiteur)const
{
	visiteur->dessiner(this);
}



const double Triangle::getAire() const {

	return 0.5*getDeterminant();
}

/**
* \brief Fonction qui calcul le determinant du triangle 
* \return la valeur du determinant (double)
*/
const double Triangle::getDeterminant() const {

	return p1.getX()*p2.getY() - p1.getY()*p2.getX();
}

/**
* \brief Effectue l'homothetie du triangle
* \param[in] x 
* \param[in] y
* \param[in] rapport
*/
Triangle *Triangle::homothetie(const Vecteur2D &v , const double rapport)const
{
	Vecteur2D *point1 = &p1.homothetie(v, rapport);
	Vecteur2D *point2 = &p2.rotation(v, rapport);
	Vecteur2D *point3 = &p3.rotation(v, rapport);
	Triangle *t = new Triangle(couleur, *point1, *point2, *point3);
	return t;

}

void Triangle::homothetie2(const Vecteur2D & v, const double rapport)
{
	Triangle * homothetie = this->homothetie(v, rapport);
	*this = *homothetie;
}


/**
* \brief Effectue la rotation du triangle
* \param[in] x
* \param[in] y
* \param[in] angle : angle de rotation
*/
Triangle * Triangle::rotation(const Vecteur2D & v, const double angle)const
{
	Vecteur2D *point1 = &p1.rotation(v,angle);
	Vecteur2D *point2 = &p2.rotation(v,angle);
	Vecteur2D *point3 = &p3.rotation(v,angle);
	Triangle *t = new Triangle(couleur, *point1, *point2,*point3);
	return t;
}

void Triangle::rotation2(const Vecteur2D & v, const double angle)
{
	Triangle* rotation = this->rotation(v, angle);
	*this = *rotation;
}


/**
* \brief Effectue la translation du triangle
* \param[in] v :
*/
Triangle * Triangle::translation(const Vecteur2D &v)const
{
	Vecteur2D *point1 = &p1.translation(v);
	Vecteur2D *point2 = &p2.translation(v);
	Vecteur2D *point3 = &p3.translation(v);
	Triangle *t = new Triangle(couleur, *point1, *point2, *point3);
	return t;
}

void Triangle::translation2(const Vecteur2D & v)
{
	Triangle* translation = this->translation(v);
	*this = *translation;
}

istream & operator>>(istream & is, Triangle &triangle)
{
	Vecteur2D point1;
	Vecteur2D point2;
	Vecteur2D point3;
	string couleur;

	cout << "--Saisie du triangle--" << endl;
	try {

		is >> point1;
		is >> point2;
		is >> point3;

		cout << "Saisir la couleur : " << endl;

		is >> couleur;

		triangle.setP1(point1);
		triangle.setP2(point2);
		triangle.setP3(point3);
		triangle.setCouleur(couleur);

	}
	catch (Erreur e) {

		cerr << e.getMessage();
		cin >> triangle;
	}

	return (is);

}