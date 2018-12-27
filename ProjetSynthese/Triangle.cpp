#include "pch.h"
#include "Triangle.h"
#include <sstream>
#include "VisiteurForme.h"

Triangle::Triangle() : FormeSimple("black"), p1(), p2(), p3(){}

Triangle::Triangle(const string & couleur, const Vecteur2D &pointA, const Vecteur2D &pointB , const Vecteur2D &pointC) : FormeSimple(couleur) , p1(pointA) , p2(pointB) , p3(pointC)
{
}

Triangle::Triangle(const Triangle &triangle): FormeSimple(triangle) , p1(triangle.p1), p2(triangle.p2) , p3(triangle.p3){}

Triangle::~Triangle(){}

Triangle * Triangle::clone() const
{
	return new Triangle(*this);
}

void Triangle::setP1(const Vecteur2D &c) throw (Erreur)
{
	if (p1 != c) {
		p1 = c;
	}

}

void Triangle::setP2(const Vecteur2D &b) throw (Erreur)
{
	if (p2 != b) {
		p2 = b;
	}
}

void Triangle::setP3(const Vecteur2D &b) throw (Erreur)
{
	if (p3 != b) {
		p3 = b;
	}
}

Triangle::operator string() const {

	ostringstream os;
	os << "triangle : " << p1.getX() << " " << p1.getY()
		<< " " << p2.getX() << " " << p2.getY()
		<< " " << p3.getX() << " " << p3.getY()
		<< " " << couleur;
	return os.str();
}

void Triangle::affiche() const
{
	cout << "Couleur : " << couleur << " cote 1 x:" << p1.getX() << "y: " << p1.getY() << "cote 2 x:" << p2.getX() << " y:" << p2.getY() << "cote 3 x : " << p3.getX() << "y: " << p3.getY() << endl;
}

bool Triangle::operator==(const Triangle &t) const
{
	if(FormeGeometrique::operator==(t))
		return (p1 == t.p1 && p2 == t.p2 && p3==t.p3);
}

void Triangle::operator=(const Triangle &t)
{
	if (this != &t) {
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
	delete point1, point2, point3;
	return t;

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
	delete point1, point2 ,point3;
	return t;
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
	delete point1, point2, point3;
	return t;
}

istream & operator>>(istream & is, Triangle &triangle)
{
	Vecteur2D point1;
	Vecteur2D point2;
	Vecteur2D point3;
	double xa, xb, ya, yb,xc,yc;

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
	cout << "Saisir le point x  du troisieme cote : " << endl;
	is >> xc;
	cout << "Saisir le point y du troisieme cote : " << endl;
	is >> yc;

	point1.setX(xa);
	point1.setY(ya);

	point2.setX(xb);
	point2.setY(yb);

	point3.setX(xc);
	point3.setY(yc);

	cout << "Saisir la couleur : " << endl;
	cin >> triangle.couleur;
	triangle.setP1(point1);
	triangle.setP2(point2);
	triangle.setP3(point3);
	

	return (is);

}