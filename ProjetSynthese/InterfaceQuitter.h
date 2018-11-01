#pragma once
#include "InterfaceUtilisateur.h"
class InterfaceQuitter :
	public InterfaceUtilisateur
{
public:
	void executerInteraction(vector <FormeGeometrique*> formes)const;
	InterfaceQuitter(InterfaceUtilisateur *suivant);
	virtual ~InterfaceQuitter();
	virtual const char* toString()const;
	virtual string getDescription()const;

protected:
	virtual bool peutExecuter(string &choix)const;

};


