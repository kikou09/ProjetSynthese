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

void InterfaceChargement::executer(string contenu,vector <FormeGeometrique *> & forme) const
{
	if (peutExecuter(contenu)) 			// cet expert a trouvé une solution 
		executerInteraction(contenu, forme);

	else            			// échec de cet expert
		if (this->suivant != NULL) {  		// le problème est transmis à   
			// l’expert suivant
			return this->suivant->executer(contenu, forme);
		}
		else {
			//exception
			throw new Erreur("Pas d'interaction possible");
		}
	
}
