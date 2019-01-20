#include "pch.h"
#include "InterfaceChargementCercle.h"
#include "Cercle.h"


bool InterfaceChargementCercle::peutExecuter(string & contenu) const
{
	size_t trouve = contenu.find("Cercle :"); // si contenu contient "cercle :" alors la forme a charger est un cercle
	if (trouve != string::npos)
		return true;
	else
		return false;
}

InterfaceChargementCercle::InterfaceChargementCercle(InterfaceChargement * s) : InterfaceChargement(s)
{
}

InterfaceChargementCercle::~InterfaceChargementCercle()
{
}

FormeGeometrique * InterfaceChargementCercle::executerInteraction(string contenu) const
{
	double rayon;
	int i = 0; 
	size_t pos = contenu.find(":");
	contenu = contenu.substr(pos + 1); // suppression de "Cercle :"
	
	char* texteCercle = strdup(contenu.c_str()); // on transforme le texte string en char*
	char* coordonnees = strtok(texteCercle, " "); // on utilise la fonction strtok pour créer un tableau avec le délimiteur espace

	char * points[NBVALMAX]; 

	while (coordonnees != NULL) {
		points[i] = coordonnees;
		i++;
		coordonnees = strtok(NULL, " ");
	}

	rayon = stod(points[2]); // on récupère le rayon dans la troisième case
	string couleur(points[3]); // on récupère la couleur dans la quatrième case

	Vecteur2D centre(stod(points[0]), stod(points[1]));
	FormeGeometrique *figure = new Cercle(couleur, centre, rayon);

	return figure;
}

