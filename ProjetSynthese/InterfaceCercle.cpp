#include "pch.h"
#include "InterfaceCercle.h"
#include "Cercle.h"


bool InterfaceCercle::peutExecuter(string & choix) const
{
	return choix == getDescription();
}

InterfaceCercle::InterfaceCercle(InterfaceForme * s): InterfaceForme(s)
{
}

InterfaceCercle::~InterfaceCercle()
{
}

const char * InterfaceCercle::toString() const
{
	return nullptr;
}


void InterfaceCercle::executerInteraction(FormeGeometrique *forme) const
{
	Cercle cercle;
	cin >> cercle ;
	forme = &cercle;
	forme->affiche();

	
}
string InterfaceCercle::getDescription() const
{
	return "Cercle";
}
