#pragma once
#include "InterfaceForme.h"
class InterfaceSegment :
	public InterfaceForme
{
protected:
	virtual bool peutExecuter(string &choix)const;
public:
	InterfaceSegment(InterfaceForme *s);
	virtual ~InterfaceSegment();
	virtual const char* toString() const;
	virtual string getDescription() const;
	void executerInteraction(FormeGeometrique *) const;
};

