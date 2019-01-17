#pragma once
#include "InterfaceChargement.h"
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

