#include "pch.h"
#include "InterfaceChargementTriangle.h"
#include "Triangle.h"

bool InterfaceChargementTriangle::peutExecuter(string & contenu) const
{
	size_t trouve = contenu.find("Triangle :"); // si contenu contient "Triangle:" alors la forme a charger est un Triangle
	if (trouve != string::npos)
		return true;
	else
		return false;
}

InterfaceChargementTriangle::InterfaceChargementTriangle(InterfaceChargement * s) :InterfaceChargement(s)
{
}

InterfaceChargementTriangle::~InterfaceChargementTriangle()
{
}

void InterfaceChargementTriangle::executerInteraction(string contenu, vector<FormeGeometrique*> & formes) const
{
	int i = 0;
	size_t pos = contenu.find(":");
	contenu = contenu.substr(pos + 1); // suppression de "Triangle:"

	char* texteTriangle = strdup(contenu.c_str()); // copie de contenu dans une variable char*
	char* coordonnees = strtok(texteTriangle, " "); // Séparation des coordonnées contenues dans texteTriangle séparées par espace

	char * points[NBVALMAX]; 

	while (coordonnees != NULL) {
		points[i] = coordonnees;
		i++;
		coordonnees = strtok(NULL, " ");
	}

	Vecteur2D point1(stod(points[0]), stod(points[1]));
	Vecteur2D point2(stod(points[2]), stod(points[3]));
	Vecteur2D point3(stod(points[4]), stod(points[5]));
	string couleur(points[6]);

	FormeGeometrique* figure = new Triangle(couleur, point1, point2, point3);

	formes.push_back(figure);
}
