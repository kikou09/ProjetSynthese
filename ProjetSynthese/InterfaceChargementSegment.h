#pragma once
#include "InterfaceChargement.h"

/**
* \class InterfaceChargementSegment
* \brief Interface permettant le chargement des segments sauvegardés dans un fichier
*/
class InterfaceChargementSegment :
	public InterfaceChargement
{
protected:
	virtual bool peutExecuter(string &contenu)const;
public:
	InterfaceChargementSegment(InterfaceChargement *s);
	virtual ~InterfaceChargementSegment();
	virtual FormeGeometrique * executerInteraction(string contenu) const;
};

