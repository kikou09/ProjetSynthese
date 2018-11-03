#include "pch.h"
#include "InterfaceDessiner.h"


void InterfaceDessiner::executerInteraction(FormeGeometrique *) const
{
}

InterfaceDessiner::InterfaceDessiner(InterfaceUtilisateur * s): InterfaceUtilisateur(s)
{
}

InterfaceDessiner::~InterfaceDessiner()
{
}

const char * InterfaceDessiner::toString() const
{
	return nullptr;
}

string InterfaceDessiner::getDescription() const
{
	return "Dessiner une forme";
}

bool InterfaceDessiner::peutExecuter(string & choix) const
{
	return choix == getDescription();
}
