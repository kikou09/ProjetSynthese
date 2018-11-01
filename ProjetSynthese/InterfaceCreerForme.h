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

	void executerInteraction(vector <FormeGeometrique*> formes)const;
	virtual const char* toString()const ;
	virtual string getDescription()const ;
	InterfaceCreerForme(InterfaceUtilisateur *suivant);
	virtual ~InterfaceCreerForme();

protected:

	virtual bool peutExecuter(string &choix) const ;

};

