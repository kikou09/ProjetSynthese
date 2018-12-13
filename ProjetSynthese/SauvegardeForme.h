#pragma once
#include "VisiteurForme.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
class SauvegardeForme :
	public VisiteurForme
{
public:

	void sauvegarde(const FormeGeometrique *f) const;
};

