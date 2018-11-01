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
	InterfaceUtilisateur *ihm,*ihm_aux;
	Cercle cercle;
	int choix;
	string c;
	FormeGeometrique *f=nullptr;
	class forme;
	int i;

	ihm = new InterfaceQuitter(nullptr);
	ihm = new InterfaceCreerForme(ihm);

	ihm_aux = ihm;
	while (ihm_aux != nullptr) {
		menu.push_back(ihm_aux->getDescription());
		ihm_aux=ihm_aux->suivant;
	}

	for (i=0; i < menu.size() ; i++)
	{
		cout << i+1 << ":" << menu[i]<< endl;
	}

	cout << "Quelle est votre choix ? " << endl;
	cin >> choix;
	
	c = menu[choix - 1];
	ihm->executer(c, f);
	
	system("pause");
	return 0;
}