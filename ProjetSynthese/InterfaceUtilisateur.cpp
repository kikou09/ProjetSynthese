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
	if (peutExecuter()) 			// cet expert a trouv� une solution 
		executer();

	else            			// �chec de cet expert
		if (this->suivant != NULL)  		// le probl�me est transmis �   
			// l�expert suivant
			return this->suivant->executer(f);
		else
			//exception

InterfaceUtilisateur::~InterfaceUtilisateur()
{
}
