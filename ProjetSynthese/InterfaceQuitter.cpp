#include "pch.h"
#include "InterfaceQuitter.h"


void InterfaceQuitter::executerInteraction(vector <FormeGeometrique*> formes) const
{
	cout << "Au revoir !" << endl;
	exit(0);
}

InterfaceQuitter::InterfaceQuitter(InterfaceUtilisateur * suivant): InterfaceUtilisateur(suivant)
{
}

bool InterfaceQuitter::peutExecuter(string &choix) const
{
	return choix == getDescription();
}

InterfaceQuitter::~InterfaceQuitter()
{
}

const char * InterfaceQuitter::toString() const
{
	return nullptr;
}

string InterfaceQuitter::getDescription() const
{
	return "Quitter";
}
