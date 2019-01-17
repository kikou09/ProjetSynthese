#include "pch.h"
#include "InterfaceChargementSegment.h"
#include "Segment.h"



bool InterfaceChargementSegment::peutExecuter(string & contenu) const
{
	size_t trouve = contenu.find("Segment:"); // si contenu contient "Segment:" alors la forme a charger est un segment
	if (trouve != string::npos)
		return true;
	else
		return false;
}

InterfaceChargementSegment::InterfaceChargementSegment(InterfaceChargement * s): InterfaceChargement(s)
{
}

InterfaceChargementSegment::~InterfaceChargementSegment()
{
}

FormeGeometrique * InterfaceChargementSegment::executerInteraction(string contenu) const
{
	int i = 0;
	size_t pos = contenu.find(":");
	contenu = contenu.substr(pos + 1); // suppression de "Segment:"

	char* texteSegment = strdup(contenu.c_str());
	char* coordonnees = strtok(texteSegment, " ");

	char * points[NBVALMAX]; 

	while (coordonnees != NULL) {
		points[i] = coordonnees;
		i++;
		coordonnees = strtok(NULL, " ");
	}

	string couleur(points[4]);

	Vecteur2D point1(stod(points[0]), stod(points[1]));
	Vecteur2D point2(stod(points[2]), stod(points[3]));
	FormeGeometrique *figure = new Segment(couleur, point1, point2);

	return figure;
}
