#pragma once

#include <vector>
#include "FormeGeometrique.h"
using namespace std;
class InterfaceUtilisateur
{
public:
	InterfaceUtilisateur *suivant;

protected:
	InterfaceUtilisateur (InterfaceUtilisateur*suivant);
	virtual bool peutExecuter(string choix)const = 0;
	//virtual Fraction* peutExecuter(string *f)const = 0;

public:

	//Fraction * Charge(const char *f) const;
	void executer(FormeGeometrique *) const;
	virtual ~InterfaceUtilisateur();
	virtual const char* toString() const = 0;
	virtual string getDescription() const = 0;
};

