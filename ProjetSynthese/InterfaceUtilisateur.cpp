#include "pch.h"
#include "InterfaceUtilisateur.h"


InterfaceUtilisateur::InterfaceUtilisateur()
{
}


InterfaceUtilisateur::InterfaceUtilisateur(InterfaceUtilisateur * suivant) : suivant(suivant)
{
}

void InterfaceUtilisateur::executer(istream & fichier) const
{
	if (peutExecuter()) 			// cet expert a trouvé une solution 
		executer();

	else            			// échec de cet expert
		if (this->suivant != NULL)  		// le problème est transmis à   
			// l’expert suivant
			return this->suivant->executer(f);
		else
			//exception

InterfaceUtilisateur::~InterfaceUtilisateur()
{
}
