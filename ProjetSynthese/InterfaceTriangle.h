#pragma once
#include "InterfaceForme.h"
class InterfaceTriangle :
	public InterfaceForme
{
protected:
	virtual bool peutExecuter(string &choix)const;
public:
	InterfaceTriangle(InterfaceForme *s);
	virtual ~InterfaceTriangle();
	virtual const char* toString() const;
	virtual string getDescription() const;
	void executerInteraction(FormeGeometrique *) const;
};

