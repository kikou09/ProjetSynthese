#pragma once
#include "VisiteurForme.h"
#include "connexion.h"


/**
 * @brief Java class
 * Cette classe est charg� de dessiner les formes g�ometriques.
 * Le dessin est fait en envoyant les formes g�ometriques � un serveur afin que celui-ci dessine.
 */
class Java :
	public VisiteurForme
{

private:

	Connexion* connexion;

public:

	Java(Connexion *c);
	virtual ~Java();

	virtual void dessiner(const Cercle *c) const;
	virtual void dessiner(const Triangle *t) const;
	virtual void dessiner(const Polygone *p) const;
	virtual void dessiner(const Segment *s) const;
	virtual void dessiner(const FormeComposee *f) const;

};

