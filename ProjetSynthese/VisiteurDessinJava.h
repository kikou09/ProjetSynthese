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
public:
	
	VisiteurDessinJava();
	virtual ~VisiteurDessinJava();

	virtual void dessiner(const FormeGeometrique *c) const;

};

