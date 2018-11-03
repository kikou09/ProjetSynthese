#include "pch.h"
#include "InterfaceCalcul.h"


void InterfaceCalcul::executerInteraction(FormeGeometrique *) const
{
}

InterfaceCalcul::InterfaceCalcul(InterfaceUtilisateur * s) : InterfaceUtilisateur(s)
{
}

const char * InterfaceCalcul::toString() const
{
	return nullptr;
}

string InterfaceCalcul::getDescription() const
{
	return "Calculer l'aire";
}

InterfaceCalcul::~InterfaceCalcul()
{
}

bool InterfaceCalcul::peutExecuter(string & choix) const
{
	return choix == getDescription();
}
