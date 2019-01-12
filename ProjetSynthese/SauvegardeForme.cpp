#include "pch.h"
#include "SauvegardeForme.h"


void SauvegardeForme::sauvegarde(const FormeGeometrique * f) const
{
	ofstream fichier("C:/Users/Alexis/source/kikou09/ProjetSynthese/ProjetSynthese/Nouveau_Dossier/FormesSauvegardees.txt", ios::app);
	//Test d'ouverture
	if (fichier.is_open())
		cout << "ok";

	if (! fichier) {
		cerr << "Problème d'ouverture de fichier" << endl;
		exit(1);
	}
	fichier << (string)*f << "\n";
	// fermeture du fichier
	fichier.close();
}
