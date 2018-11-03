#include "pch.h"
#include "InterfaceCreerForme.h"


void InterfaceCreerForme::executerInteraction(FormeGeometrique *f) const
{
	InterfaceForme *forme , *forme_aux , *triangle , *polygone , *segment , *cercle ;
	string choix;
	vector <string> menu_formes;
	int i, c;

	cercle = new InterfaceCercle(nullptr);
	polygone = new InterfacePolygone(cercle);
	triangle = new InterfaceTriangle(polygone);
	segment = new InterfaceSegment(triangle);

	forme = segment;
	
	cout << "Quelle forme veux tu créer ? " << endl;

	forme_aux = forme;
	while (forme_aux != nullptr) {
		menu_formes.push_back(forme_aux->getDescription());
		forme_aux = forme_aux->suivant;
	}

	for (i = 0; i < menu_formes.size(); i++)
	{
		cout << i + 1 << ":" << menu_formes[i] << endl;
	}

	cout << "Quelle est votre choix ? " << endl;
	cin >> c;

	choix = menu_formes[c - 1];
	forme->executer(choix, f);

	delete triangle , polygone , cercle , segment ,forme,forme_aux;
}

const char * InterfaceCreerForme::toString() const 
{
	return nullptr;
}

string InterfaceCreerForme::getDescription() const
{
	return "Creer une forme";
}

InterfaceCreerForme::InterfaceCreerForme(InterfaceUtilisateur * suivant) : InterfaceUtilisateur(suivant)
{
}

InterfaceCreerForme::~InterfaceCreerForme()
{
}

bool InterfaceCreerForme::peutExecuter(string &choix)const 
{
	return choix==getDescription();
}
