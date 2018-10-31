#include "pch.h"
#include "InterfaceQuitter.h"


void InterfaceQuitter::executer() const
{
	exit(0);
}

bool InterfaceQuitter::peutExecuter(string choix) const
{
	return choix == getDescription();
}

InterfaceQuitter::InterfaceQuitter()
{
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
