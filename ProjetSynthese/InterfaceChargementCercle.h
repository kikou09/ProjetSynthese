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
	void executerInteraction(string contenu, vector <FormeGeometrique*> & formes) const;

};
