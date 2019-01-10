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
	virtual void executerInteraction(string contenu, vector <FormeGeometrique*> & formes) const;
};

