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
	FormeGeometrique * executerInteraction(string contenu) const;

	/**
	* Coupe la chaine de caractères et met chaque partie dans un vector 
	*\param[in] chaine : contenu à couper 
	*/
	const vector<string> split(string chaine) const;
};

