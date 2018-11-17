#pragma once
#include "VisiteurForme.h"
class Java :
	public VisiteurForme
{
public:

	virtual void visite(const Cercle *c) const;
	virtual void visite(const Triangle *t) const;
	virtual void visite(const Polygone *p) const;
	virtual void visite(const Segment *s) const;
	virtual void visite(const Vecteur2D *v) const;
	virtual void visite(const FormeComposee *f) const;

};

