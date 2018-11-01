#include "pch.h"
#include "InterfaceUtilisateur.h"


InterfaceUtilisateur::InterfaceUtilisateur(InterfaceUtilisateur * suivant) : suivant(suivant)
{
}

void InterfaceUtilisateur::executer(string &choix ,FormeGeometrique *forme) const
{
	if (peutExecuter(choix)) 			// cet expert a trouvé une solution 
		executerInteraction(forme);

	else            			// échec de cet expert
		if (this->suivant != NULL) {  		// le problème est transmis à   
			// l’expert suivant
			return this->suivant->executer(choix ,forme);
		}
		else {
			//exception
		}
}

InterfaceUtilisateur::~InterfaceUtilisateur()
{
}
