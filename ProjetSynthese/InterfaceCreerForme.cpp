#include "pch.h"
#include "InterfaceCreerForme.h"


void InterfaceCreerForme::executer(FormeGeometrique *) const
{
	InterfaceForme *forme;
	InterfaceForme *cercle, *triangle, *polygone, *segment;

	cercle = new InterfaceCercle(NULL);
	polygone = new InterfacePolygone(cercle);
	triangle = new InterfaceTriangle(polygone);
	segment = new InterfaceSegment(triangle);

	forme = segment;

	while (forme != NULL) {

		cout << forme.getDescription();
		forme.suivant;
	}
	cout << "Quelle forme veux tu créer ? " << endl;
	
}

string InterfaceCreerForme::getDescription()
{
	return "Créer une forme";
}

InterfaceCreerForme::InterfaceCreerForme(InterfaceUtilisateur * suivant) : InterfaceUtilisateur(suivant)
{
}

InterfaceCreerForme::~InterfaceCreerForme()
{
}

bool InterfaceCreerForme::peutExecuter(string choix)
{
	return choix==getDescription();
}
