#pragma once

#include "FormeGeometrique.h"

/*
*\class VisiteurForme
*\brief classe de base du visteur pour les formes g�om�triques
* Visteur pour le dessin de la forme
*/
class VisiteurSauvegarde
{
public:

	virtual void sauvegarde(const FormeGeometrique *forme) const = 0;

};
