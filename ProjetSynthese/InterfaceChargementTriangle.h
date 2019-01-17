#pragma once
#include "InterfaceChargement.h"

/**
* \class InterfaceChargementTriangle
* \brief Interface permettant le chargement des triangles sauvegard�s dans un fichier
*/
class InterfaceChargementTriangle :
	public InterfaceChargement
{
protected:
	virtual bool peutExecuter(string &contenu)const;
public:
	InterfaceChargementTriangle(InterfaceChargement *s);
	virtual ~InterfaceChargementTriangle();
	FormeGeometrique * executerInteraction(string contenu) const;
};

