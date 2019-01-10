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
	void executerInteraction(string contenu, vector <FormeGeometrique*> & formes) const;

};

