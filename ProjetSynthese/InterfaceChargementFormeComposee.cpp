#include "pch.h"
#include "InterfaceChargementFormeComposee.h"


InterfaceChargementFormeComposee::InterfaceChargementFormeComposee(InterfaceChargement *s):InterfaceChargement(s)
{
}

bool InterfaceChargementFormeComposee::peutExecuter(string & contenu) const {
	size_t trouve = contenu.find("Forme");
	if (trouve != string::npos)
		return true;
	else
		return false;
}

void InterfaceChargementFormeComposee::executerInteraction(string contenu, vector <FormeGeometrique*> & formes) const {
	string forme;
	string couleur;
	int i = 1;
	int maj = 0; 
	int taille = 0;

	InterfaceChargement *corCercle = new InterfaceChargementCercle(NULL);
	InterfaceChargement *corTriangle = new InterfaceChargementTriangle(corCercle);
	InterfaceChargement *corSegment = new InterfaceChargementSegment(corTriangle);
	InterfaceChargement *corPolygone = new InterfaceChargementPolygone(corSegment);
	InterfaceChargement *cor = corPolygone;
	vector<FormeGeometrique*> vformescomposees;

	size_t pos = contenu.find("[");
	contenu = contenu.substr(pos + 2); // Suppression de "Forme Composee [ "
	pos = contenu.find("]");
	couleur = contenu.substr(pos + 2); // la couleur est entre "] " et la fin
	contenu = contenu.substr(0, pos); // on garde contenu de son début jusqu'à la position de "]"
	FormeComposee fc(couleur);
	
	// Les composantes de la forme sont séparées par des Maj,
	char* texteFC = strdup(contenu.c_str()); // on transforme le texte string en char*
	while (i<=contenu.length()) {
		if (!isupper(contenu[i]) && i!=contenu.length()) taille++;
		else {
			forme = contenu.substr(maj, taille+1);
			cor->executer(forme, vformescomposees);
			maj = i;
			taille = 0;
		}
		i++;
	}
	
	// avec le vecteur de forme, on ajoute chaque composante à la forme composée
	for (vector<FormeGeometrique*>::iterator it = vformescomposees.begin(); it != vformescomposees.end(); it++) {
		fc.ajouterForme(*it);
	}

	FormeGeometrique *figure = new FormeComposee(fc);
	formes.push_back(figure);
}

InterfaceChargementFormeComposee::~InterfaceChargementFormeComposee()
{
}
