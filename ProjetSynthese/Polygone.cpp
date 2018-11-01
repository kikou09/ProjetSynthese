#include "pch.h"
#include "Polygone.h"


Polygone::Polygone()
{
}


Polygone::~Polygone()
{
}

void Polygone::homothetie(const double x, const double y, const double)
{
}

void Polygone::rotation(const double x, const double y, const double angle)
{
}

void Polygone::translation(const Vecteur2D * v)
{
}

const double Polygone::getAire() const
{
	return 0.0;
}

void Polygone::operator=(const Polygone &)
{
}

bool Polygone::operator==(const Polygone &) const
{
	return false;
}

Polygone::operator string() const
{
	return "ok";
}

ostream & operator<<(ostream & os, const Polygone &)
{
	os << "ok";
	return os;
}
