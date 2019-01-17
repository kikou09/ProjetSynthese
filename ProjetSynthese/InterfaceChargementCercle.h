#pragma once
#include "InterfaceChargement.h"
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
