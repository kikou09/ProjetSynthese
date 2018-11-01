#pragma once
#include "InterfaceForme.h"
#include <vector>

class InterfaceCercle :
	public InterfaceForme
{
protected:
	virtual bool peutExecuter(string &choix)const;
public:
	InterfaceCercle(InterfaceForme *s);
	virtual ~InterfaceCercle();
	virtual const char* toString() const;
	virtual string getDescription() const;
	void executerInteraction(FormeGeometrique *) const;

};

