#pragma once
#include "VisiteurForme.h"
#include "EnvoyeurReceveur.h"


/**
 * @brief Java class
 * Cette classe est chargé de dessiner les formes géometriques.
 * Le dessin est fait en envoyant les formes géometriques à un serveur afin que celui-ci dessine.
 */
class Java :
	public VisiteurForme
{

private:

	EnvoyeurReceveur* connexion;

public:

	Java(EnvoyeurReceveur *c);
	virtual ~Java();

	void dessiner(const Cercle *c) const;
	void dessiner(const Triangle *t) const;
	void dessiner(const Polygone *p) const;
	void dessiner(const Segment *s) const;
	void dessiner(const FormeComposee *f) const;

};

