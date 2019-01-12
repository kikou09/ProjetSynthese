#include "pch.h"
#include "Vecteur2D.h"
#include "Cercle.h"
#include "FormeGeometrique.h"

#include "InterfaceChargement.h"
#include "InterfaceChargementCercle.h"
#include "InterfaceChargementPolygone.h"
#include "InterfaceChargementSegment.h"
#include "InterfaceChargementTriangle.h"
#include "InterfaceChargementFormeComposee.h"
#include "VisiteurForme.h"
#include "SauvegardeForme.h"
#include <iostream>
#include "Application.h"
#include "VisiteurDessinJava.h"

using namespace std;
/**
*	Pour que la forme s'affiche sur l'ecran lors du dessin 
*	Coordoonnes : X entre -1.5 et 40 et Y entre -2 et 20
*	Donc difficultés à dessiner les rotations ... car les coordonnees risquent de dépasser l'écran
*/
int main()
{

	/*vector <string> menu;
	InterfaceUtilisateur *ihm,*ihm_aux , *creer_forme , *calcul , *dessiner , *quitter ;
	int choix=0;
	string c;*/


	double aire;
	FormeGeometrique *forme;
	Cercle cercle;
	Triangle triangle;
	Segment segment;
	Polygone polygone;
	FormeComposee fc("red");
	Vecteur2D rotation(5, 4);
	int i;
	vector<FormeGeometrique *> formes;

	InterfaceChargement *corCercle = new InterfaceChargementCercle(NULL);
	InterfaceChargement *corTriangle = new InterfaceChargementTriangle(corCercle);
	InterfaceChargement *corSegment = new InterfaceChargementSegment(corTriangle);
	InterfaceChargement *corPolygone = new InterfaceChargementPolygone(corSegment);
	InterfaceChargement *corFormeComposee = new InterfaceChargementFormeComposee(corPolygone);
	InterfaceChargement *cor = corFormeComposee;

	try {
		
		/*cin >> segment;
		cout << "Aire du segment : " << segment.getAire() << endl;
		cout << "Rotation du segment : " << *(segment.rotation(rotation, 30)) << endl;
		cout << "Homothetie du segment : " << *(segment.homothetie(rotation, 30)) << endl;
		cout << "Translation du segment : " << *(segment.translation(rotation)) << endl << endl;*/

		//Test cercle 
		//cin >> cercle;
		/*cout << "Aire du cercle : " << cercle.getAire() << endl;
		cout << "Rotation du cercle : " << *(cercle.rotation(rotation, 30)) << endl;
		cout << "Homothetie du cercle : " << *(cercle.homothetie(rotation, 30)) << endl;
		cout << "Translation du cercle : " << *(cercle.translation(rotation)) << endl << endl;*/

		/*cin >> triangle;
		cout << "Aire du triangle : " << triangle.getAire() << endl;
		cout << "Rotation du triangle : " << *(triangle.rotation(rotation, 30)) << endl;
		cout << "Homothetie du triangle : " << *(triangle.homothetie(rotation, 30)) << endl;
		cout << "Translation du triangle : " << *(triangle.translation(rotation)) << endl << endl;*/

		/*cin >> polygone;
		cout << "Aire du polygone : " << polygone.getAire() << endl;
		cout << "Rotation du polygone : " << *(polygone.rotation(rotation, 30)) << endl;
		cout << "Homothetie du polygone : " << *(polygone.homothetie(rotation, 30)) << endl;
		cout << "Translation du polygone : " << *(polygone.translation(rotation)) << endl << endl;*/

		/*fc.ajouterForme(&segment);
		fc.ajouterForme(&triangle);
		cout << "Aire de la forme composee : " << fc.getAire() << endl;
		cout << "Rotation de la forme composee : " << *(fc.rotation(rotation, 30)) << endl;
		cout << "Homothetie de la forme composee : " << *(fc.homothetie(rotation, 30)) << endl;
		cout << "Translation de la forme composee : " << *(fc.translation(rotation)) << endl;*/
	
		//forme->dessin(new VisiteurDessinJava);

		//cercle.dessin(new VisiteurDessinJava);
		//triangle.dessin(new VisiteurDessinJava);
		//cout << "Test de la sauvegarde" << endl;
		//segment.accepteSauvegarde(new SauvegardeForme);
		//fc.accepteSauvegarde(new SauvegardeForme);
		FormeGeometrique::ChargerFormes(formes, cor);
		//cout << formes.empty();
		cout << *formes[0];
		cout << "\ndeuxieme forme\n" << *formes[1];
		//cout << "\ntroisieme forme\n" << *formes[2];
		//cout << "\npremier polygone :\n" << *formes[3];
		//cout << "\nl'autre\n" << *formes[4];
		//cout << "Tremblez mon enfant voici la FC\n" << *formes[5];*/
		
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
	*/
	system("pause");
	return 0;
}