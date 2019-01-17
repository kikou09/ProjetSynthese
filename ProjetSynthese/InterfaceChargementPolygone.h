#pragma once
#include "InterfaceChargement.h"
class InterfaceChargementPolygone :
	public InterfaceChargement
{
protected:
	virtual bool peutExecuter(string &contenu)const;
public:
	InterfaceChargementPolygone(InterfaceChargement *s);
	virtual ~InterfaceChargementPolygone();
	FormeGeometrique * executerInteraction(string contenu) const;

};

