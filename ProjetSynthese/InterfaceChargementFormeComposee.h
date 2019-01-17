#pragma once
#include "FormeComposee.h"
#include "InterfaceChargement.h"
#include "InterfaceChargementCercle.h"
#include "InterfaceChargementPolygone.h"
#include "InterfaceChargementSegment.h"
#include "InterfaceChargementTriangle.h"

/**
* \class InterfaceChargementFormeComposee
* \brief Interface permettant le chargement des formes compos�es sauvegard�es dans un fichier
* Relance la cha�ne de responsabilit� pour chaque composante
*/
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
	* Coupe la chaine de caract�res et met chaque partie dans un vector 
	*\param[in] chaine : contenu � couper 
	*/
	const vector<string> split(string chaine) const;
};

