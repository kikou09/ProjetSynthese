#pragma once
#include "InterfaceUtilisateur.h"
#include "InterfaceForme.h"
#include "InterfaceCercle.h"
#include "InterfacePolygone.h"
#include "InterfaceSegment.h"
#include "InterfaceTriangle.h"

class InterfaceCreerForme :
	public InterfaceUtilisateur
{
public:
	void executer(FormeGeometrique *) const;
	virtual const char* toString();
	virtual string getDescription();
	InterfaceCreerForme(InterfaceUtilisateur *suivant);
	virtual ~InterfaceCreerForme();

protected:

	virtual bool peutExecuter(string choix);

};

