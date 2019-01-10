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
	void executerInteraction(string contenu, vector <FormeGeometrique*> & formes) const;
};

