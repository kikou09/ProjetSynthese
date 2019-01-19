#include "pch.h"
#include "InterfaceChargement.h"

InterfaceChargement::InterfaceChargement()
{
}


InterfaceChargement::InterfaceChargement(InterfaceChargement * suivant) : suivant(suivant)
{
}


InterfaceChargement::~InterfaceChargement()
{
}

FormeGeometrique * InterfaceChargement::executer(string contenu) const
{
	if (peutExecuter(contenu)) 			// cet expert a trouv� une solution 
		return executerInteraction(contenu);

	else            						// �chec de cet expert
		if (this->suivant != NULL) {  		// le probl�me est transmis �   
			// l�expert suivant
			return this->suivant->executer(contenu);
		}
		else {
			//exception
			throw new Erreur("Pas d'interaction possible");
		}
	
}

