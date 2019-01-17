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

FormeGeometrique * InterfaceChargementFormeComposee::executerInteraction(string contenu) const {
	string forme,temp;
	string couleur;
	size_t i ;

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
	formes_chaine = split(contenu);

	couleur = formes_chaine[0];
	FormeComposee* fc = new FormeComposee(couleur);

	i = 1;
	while(i<formes_chaine.size()) {

		if (formes_chaine[i] == "Forme Composee") {

			size_t j = i;
			while (formes_chaine[j] != "/")
				j++;

			while (i <= j)
			{
				temp += formes_chaine[i] + ";";
				i++;
			}
			fc->ajouterForme(corFormeComposee->executer(temp));

		}
		else {
			if (formes_chaine[i] != "/" && formes_chaine[i] !="" )
				fc->ajouterForme(corFormeComposee->executer(formes_chaine[i]));
			i++;
		}
	}

	delete corCercle;
	delete corFormeComposee;
	delete corPolygone;
	delete corSegment;
	delete corTriangle;

	return fc;
}

InterfaceChargementFormeComposee::~InterfaceChargementFormeComposee()
{
}

const vector<string> InterfaceChargementFormeComposee::split(string chaine) const
{
	vector<string> chaines;
	size_t pos_precedente = 0;
	size_t pos = 0;
	while ((pos = chaine.find(";", pos)) != string::npos) {

		string souschaine = chaine.substr(pos_precedente, pos - pos_precedente);
		if (souschaine[0] == '/') {
			string car = souschaine;
			car = car.substr(0, 1);
			chaines.push_back(car);
			souschaine = souschaine.substr(1);
		}
		chaines.push_back(souschaine);
		pos++;
		pos_precedente = pos;
	}

	//Derniere partie
	chaines.push_back(chaine.substr(pos_precedente, pos - pos_precedente));

	return chaines;
}

