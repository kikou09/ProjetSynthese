#include "pch.h"
#include "Vecteur2D.h"
#include "Cercle.h"
#include "FormeGeometrique.h"

#include "InterfaceChargement.h"
#include "InterfaceChargementCercle.h"
#include "InterfaceChargementPolygone.h"
#include "InterfaceChargementSegment.h"
#include "InterfaceChargementTriangle.h"
#include "VisiteurForme.h"
#include "SauvegardeForme.h"
#include <iostream>
#include "Application.h"
#include "VisiteurDessinJava.h"

using namespace std;
/**
*	Pour que la forme s'affiche sur l'ecran lors du dessin 
*	Coordoonnes : X entre -1.5 et 40 et Y entre -2 et 20
*	Donc difficult�s � dessiner les rotations ... car les coordonnees risquent de d�passer l'�cran
*/
int main()
{

	FormeGeometrique *forme;
	Cercle cercle;
	Triangle triangle;
	Segment segment;
	Polygone polygone;
	FormeComposee fc("red");
	Vecteur2D rotation(5, 4);
	int i;
	vector<FormeGeometrique *> formes;

	//Chaine de responsabilit�es pour le chargement des formes
	InterfaceChargement *corCercle = new InterfaceChargementCercle(NULL);
	InterfaceChargement *corTriangle = new InterfaceChargementTriangle(corCercle);
	InterfaceChargement *corSegment = new InterfaceChargementSegment(corTriangle);
	InterfaceChargement *corPolygone = new InterfaceChargementPolygone(corSegment);
	InterfaceChargement *cor = corPolygone;

	try {

		//cin >> segment;
		/*cout << "Aire du segment : " << segment.getAire() << endl;
		cout << "Rotation du segment : " << *(segment.rotation(rotation, 30)) << endl;
		cout << "Homothetie du segment : " << *(segment.homothetie(rotation, 30)) << endl;
		cout << "Translation du segment : " << *(segment.translation(rotation)) << endl << endl;*/

		//Test cercle 
		cin >> cercle;
		/*cout << "Aire du cercle : " << cercle.getAire() << endl;
		cout << "Rotation du cercle : " << *(cercle.rotation(rotation, 30)) << endl;
		cout << "Homothetie du cercle : " << *(cercle.homothetie(rotation, 30)) << endl;
		cout << "Translation du cercle : " << *(cercle.translation(rotation)) << endl << endl;*/

		cin >> triangle;
		//fc.ajouterForme(&triangle);
		//fc.ajouterForme(&cercle);
		//fc.dessin(new VisiteurDessinJava);

		cout << triangle;
		/*cout << "Aire du triangle : " << triangle.getAire() << endl;
		cout << "Rotation du triangle : " << *(triangle.rotation(rotation, 30)) << endl;
		cout << "Homothetie du triangle : " << *(triangle.homothetie(rotation, 30)) << endl;
		cout << "Translation du triangle : " << *(triangle.translation(rotation)) << endl << endl;*/

		/*cin >> polygone;
		cout << "Aire du polygone : " << polygone.getAire() << endl;
		cout << "Rotation du polygone : " << *(polygone.rotation(rotation, 30)) << endl;
		cout << "Homothetie du polygone : " << *(polygone.homothetie(rotation, 30)) << endl;
		cout << "Translation du polygone : " << *(polygone.translation(rotation)) << endl << endl;

		fc.ajouterForme(&triangle);
		fc.ajouterForme(&cercle);
		cout << "Aire de la forme composee : " << fc.getAire() << endl;
		cout << "Rotation de la forme composee : " << *(fc.rotation(rotation, 30)) << endl;
		cout << "Homothetie de la forme composee : " << *(fc.homothetie(rotation, 30)) << endl;
		cout << "Translation de la forme composee : " << *(fc.translation(rotation)) << endl;
	

		//cercle.dessin(new VisiteurDessinJava);
		//triangle.dessin(new VisiteurDessinJava);
		//fc.dessin(new VisiteurDessinJava);

		//cout << "Test de la sauvegarde" << endl;
		//cercle.accepteSauvegarde(new SauvegardeForme);


		//FormeGeometrique::ChargerFormes(formes, cor);
		//cout << *formes[0];
		/*out << "\ndeuxieme forme\n" << *formes[1];
		cout << "\ntroisieme forme\n" << *formes[2];
		cout << "\npremier polygone :\n" << *formes[3];
		cout << "\nl'autre\n" << *formes[4];
		*/

		
	}
	catch (Erreur e) {

		cout << e.getMessage();
	}
	
	system("pause");

	return 0;
}