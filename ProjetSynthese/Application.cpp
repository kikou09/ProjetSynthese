#include "pch.h"
#include "Vecteur2D.h"
#include "Cercle.h"
#include "FormeGeometrique.h"
#include "InterfaceUtilisateur.h"
#include "InterfaceCalcul.h"
#include "InterfaceCreerForme.h"
#include "InterfaceQuitter.h"
#include "InterfaceDessiner.h"
#include "VisiteurForme.h"
#include "SauvegardeForme.h"
#include <iostream>
#include "Application.h"
#include "VisiteurDessinJava.h"

using namespace std;

int main()
{

	/*vector <string> menu;
	InterfaceUtilisateur *ihm,*ihm_aux , *creer_forme , *calcul , *dessiner , *quitter ;
	int choix=0;
	string c;*/


	double aire;
	FormeGeometrique *forme;
	Cercle cercle;
	Triangle *triangle=new Triangle();
	Segment *segment=new Segment();
	Polygone polygone;
	FormeComposee fc("red");
	FormeComposee fc2("black");

	int i;


	//Test cercle 
	Vecteur2D v(8, 6);
	Vecteur2D v2(3, 4);
	Vecteur2D v3(6, 4);
	Vecteur2D v4(4, 6);
	//Vecteur2D rotation(5, 8);
	try {

		cin >> cercle;

		//forme = new Cercle("red", v, 8);
		//f = new Triangle("cyan", v2, v3, v4);
		//aire = forme->getAire();
		//cout << aire << endl;
		//f = forme->rotation(rotation, 50);
		//f->affiche();

		/*f = forme->homothetie(rotation, 50);
		cout << "Homothetie : " << endl;
		f->affiche();

		f = forme->translation(rotation);
		cout << "Rotation : " << endl;
		f->affiche();*/

		//forme->dessin(new VisiteurDessinJava);
		//f->dessin(new VisiteurDessinJava);
	}
	catch (Erreur e) {

		cout << e.getMessage();
	}

	/*quitter = new InterfaceQuitter(nullptr);
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

	delete f, quitter, creer_forme, dessiner, calcul,ihm , ihm_aux;*/

	// Test de la sauvegarde
	//création d'un cercle
	/*Vecteur2D centre(2, 10);
	forme = new Cercle("blue", centre, 5);
	cout << "voici la forme créée" << endl;
	forme->affiche();
	cout << "Test de la surchage string" << endl;
	//string(forme);
	cout << "Test de la sauvegarde" << endl;
	forme->accepteSauvegarde(new SauvegardeForme);*/
	system("pause");
	return 0;
}