#include "pch.h"
#include "SauvegardeForme.h"


void SauvegardeForme::sauvegarde(const FormeGeometrique * f) const
{
	ofstream fichier("FormesSauvegardees.txt", ios::app);
	//Test d'ouverture
	if (fichier.is_open())
		cout << "Fichier ouvert \n";

	if (! fichier) {
		cerr << "Problème d'ouverture de fichier" << endl;
		exit(1);
	}
	fichier << (string)*f << "\n";
	// fermeture du fichier
	fichier.close();
}
