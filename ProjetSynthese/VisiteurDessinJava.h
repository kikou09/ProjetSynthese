#pragma once
#include "VisiteurForme.h"
#include "EnvoyeurReceveur.h"


/**
* \brief Visiteur qui envoie l'instruction de dessin d'une forme au serveur JAVA 
* Affiche le message de retour du serveur si tout s'est bien passé
*/
class VisiteurDessinJava :
	public VisiteurForme
{
private :
	EnvoyeurReceveur *connexion;
public:
	
	VisiteurDessinJava(EnvoyeurReceveur *e);
	virtual ~VisiteurDessinJava();

	virtual void dessiner(const Cercle *c) const;
	virtual void dessiner(const Triangle *t) const;
	virtual void dessiner(const Polygone *p) const;
	virtual void dessiner(const Segment *s) const;
	virtual void dessiner(const FormeComposee *f) const;
};

