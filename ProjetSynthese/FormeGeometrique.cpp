#include "pch.h"
#include "FormeGeometrique.h"
#include "VisiteurSauvegarde.h"
#include "InterfaceChargement.h"

FormeGeometrique::FormeGeometrique(){}

FormeGeometrique::FormeGeometrique(const FormeGeometrique &forme) : couleur(forme.couleur){}

FormeGeometrique::FormeGeometrique(const string &c)
{
	try {
		setCouleur(c);
	}
	catch (Erreur e) {
		
		throw;
	}
}

FormeGeometrique::~FormeGeometrique(){}


const string FormeGeometrique::getCouleur() const
{
	return couleur;
}

void FormeGeometrique::setCouleur(const string &c)
{
	if (c.compare("black") != 0 && c.compare("blue") != 0
		&& c.compare("red") != 0 && c.compare("green") != 0
		&& c.compare("yellow") != 0 && c.compare("cyan") != 0) {

		throw Erreur("Couleur incorrecte");

	}


	couleur = c;

}




void FormeGeometrique::accepteSauvegarde(const VisiteurSauvegarde *visiteur) const
{
	visiteur->sauvegarde(this);
}

vector<FormeGeometrique *> FormeGeometrique::ChargerFormes(InterfaceChargement * cor)
{
	vector<FormeGeometrique *> formes;
	FormeGeometrique * forme;
	string contenu;
	ifstream fichierEntree("FormesSauvegardees.txt", ios::in);
	if (! fichierEntree) {
		cerr << "Probl�me d'ouverture de fichier" << endl;
		exit(1);
	}
	while (getline(fichierEntree, contenu) && !contenu.empty()) {
		cout << "Lecture :\t" << contenu << endl;
		forme=cor->executer(contenu);
		formes.push_back(forme);
	}
	return formes;
}

ostream & operator << (ostream & os, const FormeGeometrique &f)
{
	string v = string(f);
	os << v;
	return os;

}
