#include "pch.h"
#include "InterfaceTriangle.h"
#include "Triangle.h"


bool InterfaceTriangle::peutExecuter(string & choix) const
{
	return choix == getDescription();
}

InterfaceTriangle::InterfaceTriangle(InterfaceForme * s):InterfaceForme(s)
{
}

InterfaceTriangle::~InterfaceTriangle()
{
}

const char * InterfaceTriangle::toString() const
{
	return nullptr;
}

string InterfaceTriangle::getDescription() const
{
	return "Triangle";
}

void InterfaceTriangle::executerInteraction(FormeGeometrique *forme) const
{
	Triangle triangle;
	cin >> triangle;
	forme = &triangle;
	forme->affiche();
}
