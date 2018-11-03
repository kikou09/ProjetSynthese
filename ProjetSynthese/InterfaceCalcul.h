#pragma once
#include "InterfaceUtilisateur.h"
class InterfaceCalcul :
	public InterfaceUtilisateur
{
public:
	void executerInteraction(FormeGeometrique *)const;
	InterfaceCalcul(InterfaceUtilisateur *s);
	virtual const char* toString()const;
	virtual string getDescription()const;
	virtual ~InterfaceCalcul();

protected:
	virtual bool peutExecuter(string &choix)const;
};

