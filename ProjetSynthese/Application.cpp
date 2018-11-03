#include "pch.h"
#include "Vecteur2D.h"
#include "Cercle.h"
#include "FormeGeometrique.h"
#include "InterfaceUtilisateur.h"
#include "InterfaceCalcul.h"
#include "InterfaceCreerForme.h"
#include "InterfaceQuitter.h"
#include "InterfaceDessiner.h"

#include <iostream>
#include "Application.h"

using namespace std;

int main()
{

	vector <string> menu;
	InterfaceUtilisateur *ihm,*ihm_aux , *creer_forme , *calcul , *dessiner , *quitter ;
	Cercle cercle;
	int choix=0;
	string c;
	FormeGeometrique *f=nullptr;
	class forme;
	int i;

	quitter = new InterfaceQuitter(nullptr);
	creer_forme = new InterfaceCreerForme(quitter);
	calcul = new InterfaceCalcul(creer_forme);
	dessiner = new InterfaceDessiner(calcul);

	ihm = creer_forme;
	ihm_aux = ihm;

	while (ihm_aux != nullptr) {
		menu.push_back(ihm_aux->getDescription());
		ihm_aux=ihm_aux->suivant;
	}

	while (choix != 2) {
		for (i = 0; i < menu.size(); i++)
		{
			cout << i + 1 << ":" << menu[i] << endl;
		}

		cout << "Quelle est votre choix ? " << endl;
		cin >> choix;

		c = menu[choix - 1];
		ihm->executer(c, f);
	}
	
	system("pause");

	delete f, quitter, creer_forme, dessiner, calcul,ihm , ihm_aux;
	return 0;
}