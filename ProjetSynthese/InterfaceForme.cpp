#include "pch.h"
#include "InterfaceForme.h"


InterfaceForme::InterfaceForme(InterfaceForme * suivant) : suivant(suivant)
{
}

void InterfaceForme::executer(string &choix , vector <FormeGeometrique*> formes) const
{
	if (peutExecuter(choix)) 			// cet expert a trouv� une solution 
		executerInteraction(formes);

	else            			// �chec de cet expert
		if (this->suivant != NULL) {  		// le probl�me est transmis �   
			// l�expert suivant
			return this->suivant->executer(choix, formes);
		}
		else {
			//exception
		}
}

InterfaceForme::~InterfaceForme()
{
}
