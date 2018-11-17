#pragma once
#include "VisiteurForme.h"
class SauvegardeForme :
	public VisiteurForme
{
public:

	virtual void sauvegarde(const Cercle *c) const;
	virtual void sauvegarde(const Triangle *t) const;
	virtual void sauvegarde(const Polygone *p) const;
	virtual void sauvegarde(const Segment *s) const;
	virtual void sauvegarde(const Vecteur2D *v) const;
	virtual void sauvegarde(const FormeComposee *f) const;
};

