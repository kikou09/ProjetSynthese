#include "pch.h"
#include "SauvegardeForme.h"


void SauvegardeForme::sauvegarde(const FormeGeometrique * f) const
{
	ofstream fichier("C:/Users/Alexis/source/kikou09/ProjetSynthese/ProjetSynthese/Nouveau_Dossier/FormesSauvegardees.txt", ios::app);
	//Test d'ouverture
	if (fichier.is_open())
		cout << "ok";

	if (! fichier) {
		cerr << "Probl�me d'ouverture de fichier" << endl;
		exit(1);
	}
	fichier << (string)*f << endl;
	// fermeture du fichier
	//fichier.close();
	/*
	// ouverture du fichier de sauvegarde
	ofstream fichierEntree("formesSauvegardees.txt", ios::in);
	if (!fichierEntree) {
		cerr << "Probl�me d'ouverture de fichier" << endl;
		exit(1);
	}

	char buf[1024]; // Y'aurait-il un bufsiz ?
	//Tant qu'on a des formes, on traite
	while (!fichierEntree.eof()) {
		fichierEntree.getline(buf, 1024); // ouch
		// pour voir la ligne r�cup�r�e :
		cout << buf << endl;
		// on veut d'abord r�cup�rer la forme
		int i = 0;
		while(buf[i] != ':'){
			i++;
		}
		// r�cup�rer le texte qui contient la forme
		char forme[];
		for (int j=0; j<i-2; j++){
			forme[j] = buf[i];
		}
		// r�cup�rer la liste des points (alternance x,y) (tant que c'est un double et pas un char)

		// d�s qu'on rencontre un char, on a la couleur
		// on cr�e la forme

		// il doit y avoir une m�thode plus simple !!!
	}
	*/
}
