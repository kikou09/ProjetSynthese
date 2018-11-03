#pragma once
#include "InterfaceUtilisateur.h"
class InterfaceDessiner :
	public InterfaceUtilisateur
{
public:
	void executerInteraction(FormeGeometrique *)const;
	InterfaceDessiner(InterfaceUtilisateur *s);
	virtual ~InterfaceDessiner();
	virtual const char* toString()const;
	virtual string getDescription()const;

protected:
	virtual bool peutExecuter(string &choix)const;
};

