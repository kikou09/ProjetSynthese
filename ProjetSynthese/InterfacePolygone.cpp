#include "pch.h"
#include "InterfacePolygone.h"
#include "Polygone.h"


bool InterfacePolygone::peutExecuter(string & choix) const
{
	return choix == getDescription();
}

InterfacePolygone::InterfacePolygone(InterfaceForme *s):InterfaceForme(s)
{
}

InterfacePolygone::~InterfacePolygone()
{
}

const char * InterfacePolygone::toString() const
{
	return nullptr;
}

string InterfacePolygone::getDescription() const
{
	return "Polygone";
}

void InterfacePolygone::executerInteraction(FormeGeometrique *forme) const
{
	Polygone polygone;
	cin >> polygone;
	forme = &polygone;
	forme->affiche();
}
