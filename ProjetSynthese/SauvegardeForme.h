#pragma once
#include "VisiteurSauvegarde.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

/**
* \class SauvegardeForme
* \brief Permet la sauvegarde d'une forme g�om�trique dans un fichier
*/
class SauvegardeForme :
	public VisiteurSauvegarde
{
public:

	void sauvegarde(const FormeGeometrique *f) const;
};

