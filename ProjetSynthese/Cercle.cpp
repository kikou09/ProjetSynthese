#include "pch.h"
#include "Cercle.h"


Cercle::Cercle(string &c, double x, double y, double r): FormeSimple(c),x(x),y(y),rayon(r)
{
}

Cercle::Cercle(const Cercle &cercle): FormeSimple(cercle), x(cercle.x), y(cercle.y),rayon(cercle.rayon)
{
}

Cercle::Cercle()
{
}


Cercle::~Cercle()
{
}

const double Cercle::getAire() const
{
	return M_PI * rayon*rayon;
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
}

ostream & operator<<(ostream & os, const Cercle &)
{
	// TODO: insérer une instruction return ici
}
