#pragma once
#include "FormeComposee.h"
#include "InterfaceChargement.h"
#include "InterfaceChargementCercle.h"
#include "InterfaceChargementPolygone.h"
#include "InterfaceChargementSegment.h"
#include "InterfaceChargementTriangle.h"

class InterfaceChargementFormeComposee :
	public InterfaceChargement
{
protected:
	virtual bool peutExecuter(string &contenu)const;
public:
	InterfaceChargementFormeComposee(InterfaceChargement *s);
	virtual ~InterfaceChargementFormeComposee();
	void executerInteraction(string contenu, vector <FormeGeometrique*> & formes) const;
};

