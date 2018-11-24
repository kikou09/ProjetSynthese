#pragma once
#include "VisiteurForme.h"
#include <iostream>
#include <sstream>
#include <fstream>
class SauvegardeForme :
	public VisiteurForme
{
public:

	virtual void sauvegarde(const FormeGeometrique *f , const string nomFichier) const;
};

