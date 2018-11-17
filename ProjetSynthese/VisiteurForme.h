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
	virtual void visite(const Cercle *c) const = 0;
	virtual void visite(const Triangle *t) const = 0;
	virtual void visite(const Polygone *p) const = 0;
	virtual void visite(const Segment *s) const = 0;
	virtual void visite(const Vecteur2D *v) const = 0;
	virtual void visite(const FormeComposee *f) const=0;


	virtual void sauvegarde(const Cercle *c) const=0;
	virtual void sauvegarde(const Triangle *t) const=0;
	virtual void sauvegarde(const Polygone *p) const=0;
	virtual void sauvegarde(const Segment *s) const=0;
	virtual void sauvegarde(const Vecteur2D *v) const=0;
	virtual void sauvegarde(const FormeComposee *f) const=0;
};

