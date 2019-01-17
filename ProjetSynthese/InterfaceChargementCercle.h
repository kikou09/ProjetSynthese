#pragma once
#include "InterfaceChargement.h"

/**
* \class InterfaceChargementCercle
* \brief Interface permettant le chargement des cercles sauvegardés dans un fichier
*/
class InterfaceChargementCercle :
	public InterfaceChargement
{
protected:
	virtual bool peutExecuter(string &contenu)const;
public:
	InterfaceChargementCercle(InterfaceChargement *s);
	virtual ~InterfaceChargementCercle();
	FormeGeometrique * executerInteraction(string contenu) const;

};
