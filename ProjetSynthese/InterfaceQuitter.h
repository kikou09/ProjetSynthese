#pragma once
#include "InterfaceUtilisateur.h"
class InterfaceQuitter :
	public InterfaceUtilisateur
{
public:
	void executer() const;
	InterfaceQuitter();
	virtual ~InterfaceQuitter();

	virtual const char* toString()const;
	virtual string getDescription()const;

protected:
	virtual bool peutExecuter(string choix)const;

};


