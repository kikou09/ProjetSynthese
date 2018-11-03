#pragma once
#include "pch.h"
#include "Vecteur2D.h"
#include <sstream>

using namespace std;


const Vecteur2D operator *(const double & a, const Vecteur2D & u) { return u * a; }

//------------ implémentation des fonctions inline ----------------------


Vecteur2D::Vecteur2D(const double &x, const double &y) : x(x), y(y) {}

Vecteur2D::Vecteur2D(const char * s)
{
	double x, y;
	sscanf_s(s, "(%f,%f)", &x, &y);
	this->x = x;
	this->y = y;
}

Vecteur2D::Vecteur2D(const Vecteur2D &v) : x(v.x), y(v.y) {}

const Vecteur2D Vecteur2D::operator + (const Vecteur2D & u) const
{
	return Vecteur2D(x + u.x, y + u.y);
}

const Vecteur2D Vecteur2D::operator * (const double & a) const
{

	return Vecteur2D(x*a, y*a);
}

bool Vecteur2D::operator==(const Vecteur2D &v) const
{
	return x == v.x && y == v.y;
}

const Vecteur2D Vecteur2D::operator - () const
{
	return Vecteur2D(-x, -y);
}

const double Vecteur2D::getAire() const
{
	return 0.0;
}

const double Vecteur2D::getX() const
{
	return x;
}

const double Vecteur2D::getY() const
{
	return y;
}

void Vecteur2D::setX(const double px)
{
	x = px;
}

void Vecteur2D::setY(const double py)
{
	y = py;
}

void Vecteur2D::homothetie(const double x, const double y, const double rapport)
{
}

void Vecteur2D::rotation(const double x, const double y, const double angle)
{
}

void Vecteur2D::translation(const Vecteur2D * v)
{
}

Vecteur2D::operator string() const
{
	ostringstream os;
	os << "( " << x << ", " << y << ")";
	return os.str();
}

ostream & operator << (ostream & os, const Vecteur2D & u)
{
	string v = (string)u;
	os << v;
	return os;
}

istream & operator>>(istream & is, Vecteur2D &u)
{
		double x, y;

		cout << "Saisir le point x : " << endl;
		is >> x;
		cout << "Saisir le point y : " << endl;
		is >> y;

		u.setX(x);
		u.setY(y);

		return (is);

}
