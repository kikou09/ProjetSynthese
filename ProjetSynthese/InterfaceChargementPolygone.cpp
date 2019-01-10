#include "pch.h"
#include "InterfaceChargementPolygone.h"
#include "Polygone.h"

bool InterfaceChargementPolygone::peutExecuter(string & contenu) const
{
	size_t trouve = contenu.find("Polygone:"); // si contenu contient "Polygone:" alors la forme a charger est un polygone
	if (trouve != string::npos)
		return true;
	else
		return false;
}

InterfaceChargementPolygone::InterfaceChargementPolygone(InterfaceChargement * s):InterfaceChargement(s)
{
}

InterfaceChargementPolygone::~InterfaceChargementPolygone()
{
}

void InterfaceChargementPolygone::executerInteraction(string contenu, vector<FormeGeometrique*> & formes) const
{
	int nbPoints;
	int indice = 7;
	int i = 0;
	size_t pos = contenu.find(":");
	contenu = contenu.substr(pos + 1); // suppression de "Polygone:"

	char* textePolygone = strdup(contenu.c_str());
	char* coordonnees = strtok(textePolygone, " "); 

	char * points[NBVALMAX]; 

	while (coordonnees != NULL) {
		points[i] = coordonnees;
		i++;
		coordonnees = strtok(NULL, " ");
	}

	nbPoints = stoi(points[0]);

	// il y au moins trois points
	Vecteur2D point1(stod(points[1]), stod(points[2]));
	Vecteur2D point2(stod(points[3]), stod(points[4]));
	Vecteur2D point3(stod(points[5]), stod(points[6]));
	string couleur(points[nbPoints*2+1]);

	Polygone figure(couleur, &point1, &point2, &point3);
	
	if (nbPoints > 3) {
		for (i = 3; i < nbPoints; i++) {
			Vecteur2D point(stod(points[indice]), stod(points[indice+1]));
			figure.ajoutPoint(&point);
			indice = indice + 2;
		}
	}

	FormeGeometrique* forme = new Polygone(figure);
	formes.push_back(forme);

}
