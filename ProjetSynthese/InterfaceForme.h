#pragma once
#include "FormeGeometrique.h"
#include <vector>

using namespace std;

class InterfaceForme
{
public:
	InterfaceForme *suivant;

protected:
	InterfaceForme(InterfaceForme*suivant);
	virtual bool peutExecuter(string &choix)const = 0;

public:

	virtual void executerInteraction(FormeGeometrique *)const=0;
	void executer(string &choix, FormeGeometrique *) const;
	virtual ~InterfaceForme();
	virtual const char* toString() const = 0;
	virtual string getDescription() const = 0;
};

