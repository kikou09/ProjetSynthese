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

	vector<string> formes_chaine;

	InterfaceChargement *corCercle = new InterfaceChargementCercle(NULL);
	InterfaceChargement *corTriangle = new InterfaceChargementTriangle(corCercle);
	InterfaceChargement *corSegment = new InterfaceChargementSegment(corTriangle);
	InterfaceChargement *corPolygone = new InterfaceChargementPolygone(corSegment);
	InterfaceChargement *corFormeComposee = new InterfaceChargementFormeComposee(corPolygone);
	InterfaceChargement *cor = corFormeComposee;
	vector<FormeGeometrique*> vformescomposees;

	size_t pos = contenu.find(";");
	contenu = contenu.substr(pos + 1); // Suppression de "Forme Composee ;"

	//split
	size_t pos_precedente = 0;
	pos = 0;
	while ((pos = contenu.find(";",pos)) != string::npos) {

		string souschaine = contenu.substr(pos_precedente, pos - pos_precedente);
		formes_chaine.push_back(souschaine);
		pos++;
		pos_precedente = pos;
	}
	
	formes_chaine.push_back(contenu.substr(pos_precedente, pos - pos_precedente));

	couleur = formes_chaine[0];

	FormeComposee* fc = new FormeComposee(couleur);

	for (int i = 1; i < formes_chaine.size(); i++) {

		if(formes_chaine[i]!="/" )
			corFormeComposee->executer(formes_chaine[i], vformescomposees);
	}

	for (vector<FormeGeometrique*>::iterator it = vformescomposees.begin(); it != vformescomposees.end(); it++) {
		fc->ajouterForme(*it);
	}
	
	FormeGeometrique *figure = new FormeComposee(*fc);
	formes.push_back(figure);

	delete fc; 
	delete corCercle;
	delete corFormeComposee;
	delete corPolygone;
	delete corSegment;
	delete corTriangle;
}

InterfaceChargementFormeComposee::~InterfaceChargementFormeComposee()
{
}
