#pragma once

#include "Cercle.h"
#include "Polygone.h"
#include "Triangle.h"
#include "Segment.h"
#include "Vecteur2D.h"
#include "FormeComposee.h"

class VisiteurForme
{
public:
	virtual void dessiner(const Cercle *c) const = 0;
	virtual void dessiner(const Triangle *t) const = 0;
	virtual void dessiner(const Polygone *p) const = 0;
	virtual void dessiner(const Segment *s) const = 0;
	virtual void dessiner(const FormeComposee *f) const=0;


	virtual void sauvegarde(const FormeGeometrique *forme) const=0;

};

