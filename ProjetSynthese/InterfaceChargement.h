#pragma once
#include "FormeGeometrique.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define NBVALMAX 50

using namespace std;
class InterfaceChargement
{
public:
	InterfaceChargement *suivant;

protected:
	InterfaceChargement(InterfaceChargement*suivant);
	virtual bool peutExecuter(string &choix)const = 0;
public:

	virtual void executerInteraction(string contenu, vector <FormeGeometrique*> & formes)const = 0;
	void executer(string contenu, vector <FormeGeometrique*> & formes) const;
	virtual ~InterfaceChargement();
	InterfaceChargement();
};

