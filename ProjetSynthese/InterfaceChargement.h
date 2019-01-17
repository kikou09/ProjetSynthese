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

	/**
	* Reconstruit la forme recup�rer du fichier texte
	* \param[in] contenu forme recuper� du fichier texte
	* \return la forme cr�e 
	*/
	virtual FormeGeometrique * executerInteraction(string contenu)const = 0;
	FormeGeometrique * executer(string contenu) const;
	virtual ~InterfaceChargement();
	InterfaceChargement();
};

