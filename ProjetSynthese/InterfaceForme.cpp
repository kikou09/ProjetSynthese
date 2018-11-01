#include "pch.h"
#include "InterfaceForme.h"


InterfaceForme::InterfaceForme(InterfaceForme * suivant) : suivant(suivant)
{
}

void InterfaceForme::executer(string &choix , vector <FormeGeometrique*> formes) const
{
	if (peutExecuter(choix)) 			// cet expert a trouvé une solution 
		executerInteraction(formes);

	else            			// échec de cet expert
		if (this->suivant != NULL) {  		// le problème est transmis à   
			// l’expert suivant
			return this->suivant->executer(choix, formes);
		}
		else {
			//exception
		}
}

InterfaceForme::~InterfaceForme()
{
}
