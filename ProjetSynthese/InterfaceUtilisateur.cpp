#include "pch.h"
#include "InterfaceUtilisateur.h"


InterfaceUtilisateur::InterfaceUtilisateur(InterfaceUtilisateur * suivant) : suivant(suivant)
{
}

void InterfaceUtilisateur::executer(string &choix ,FormeGeometrique *forme) const
{
	if (peutExecuter(choix)) 			// cet expert a trouv� une solution 
		executerInteraction(forme);

	else            			// �chec de cet expert
		if (this->suivant != NULL) {  		// le probl�me est transmis �   
			// l�expert suivant
			return this->suivant->executer(choix ,forme);
		}
		else {
			//exception
		}
}

InterfaceUtilisateur::~InterfaceUtilisateur()
{
}
