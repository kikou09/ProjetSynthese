#pragma once

#include "Cercle.h"
#include "Polygone.h"
#include "Triangle.h"
#include "Segment.h"
#include "Vecteur2D.h"
#include "FormeComposee.h"

/*
*\class VisiteurForme
*\brief classe de base du visteur pour les formes géométriques
* Visteur pour le dessin de la forme 
*/
class VisiteurForme
{
public:
	virtual void dessiner(const FormeGeometrique *) const = 0;

};

