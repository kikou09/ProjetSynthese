#pragma once
#include "InterfaceForme.h"
#include "Polygone.h"
class InterfacePolygone :
	public InterfaceForme
{
protected:
	virtual bool peutExecuter(string &choix)const;
public:
	InterfacePolygone(InterfaceForme *);
	virtual ~InterfacePolygone();
	virtual const char* toString() const;
	virtual string getDescription() const;
	void executerInteraction(FormeGeometrique *) const;
};

