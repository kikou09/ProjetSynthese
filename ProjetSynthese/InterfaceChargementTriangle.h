#pragma once
#include "InterfaceChargement.h"
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

