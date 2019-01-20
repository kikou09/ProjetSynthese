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
#include <stdlib.h> 

using namespace std;

int main()
{

	Vecteur2D centre(7, 30);
	Vecteur2D centre2(5, 100);

	Vecteur2D point1(40, 180);
	Vecteur2D point2(80, 220);


	Cercle cercle1("red", Vecteur2D(0,0), 40);
	Triangle triangle1("cyan", Vecteur2D(-5,-2),Vecteur2D(-5,30), Vecteur2D(-2,10));

	FormeComposee fc("black");
	fc.ajouterForme(&cercle1);
	fc.ajouterForme(&triangle1);

	Segment segment1("black", Vecteur2D(100, 80), Vecteur2D(120, 60));

	Polygone polygone1("yellow", &Vecteur2D(-1, 50), &Vecteur2D(-2, 100), &Vecteur2D(1, 50));
	polygone1.ajoutPoint(&point1);
	polygone1.ajoutPoint(&point2);

	
	int i;

	InterfaceChargement *corCercle = new InterfaceChargementCercle(NULL);
	InterfaceChargement *corTriangle = new InterfaceChargementTriangle(corCercle);
	InterfaceChargement *corSegment = new InterfaceChargementSegment(corTriangle);
	InterfaceChargement *corPolygone = new InterfaceChargementPolygone(corSegment);
	InterfaceChargement *corFormeComposee = new InterfaceChargementFormeComposee(corPolygone);
	InterfaceChargement *cor = corFormeComposee;

	try {
		
		Vecteur2D rotation(5, 4);

		//Test Segment 
		Segment *s;
		s = segment1.rotation(rotation, 30);
		cout << "Aire du segment : " << segment1.getAire() << endl;
		cout << "Rotation du segment : " << *s << endl;

		s = segment1.homothetie(rotation, 30);
		cout << "Homothetie du segment : " << *s << endl;

		s = segment1.translation(rotation);
		cout << "Translation du segment : " << *s << endl << endl;

		//Test cercle 
		Cercle *c;
		cout << "Aire du cercle : " << cercle1.getAire() << endl;

		c = cercle1.rotation(rotation, 30);
		cout << "Rotation du cercle : " << *c << endl;

		c = cercle1.homothetie(rotation, 30);
		cout << "Homothetie du cercle : " << *c << endl;

		c = cercle1.translation(rotation);
		cout << "Translation du cercle : " << *c << endl << endl;

		//Test triangle
		Triangle *t;
		cout << "Aire du triangle : " << triangle1.getAire() << endl;

		t = triangle1.rotation(rotation, 30);
		cout << "Rotation du triangle : " << *t << endl;

		t = triangle1.homothetie(rotation, 30);
		cout << "Homothetie du triangle : " << *t << endl;

		t = triangle1.translation(rotation);
		cout << "Translation du triangle : " << *t << endl << endl;

		//Test polygone
		Polygone *p;
		cout << "Aire du polygone : " << polygone1.getAire() << endl;

		p = polygone1.rotation(rotation, 30);
		cout << "Rotation du polygone : " << *p << endl;

		p = polygone1.homothetie(rotation, 30);
		cout << "Homothetie du polygone : " << *p << endl;

		p = polygone1.translation(rotation);
		cout << "Translation du polygone : " << *p << endl << endl;

		//Test forme composee
		FormeComposee *f;
		cout << "Aire de la forme composee : " << fc.getAire() << endl;

		f = fc.rotation(rotation, 30);
		cout << "Rotation  de la forme composee : " << *f << endl;

		f = fc.homothetie(rotation, 30);
		cout << "Homothetie  de la forme composee : " << *f << endl;

		f = fc.translation(rotation);
		cout << "Translation  de la forme composee : " << *f << endl << endl;


		//Test Chargement
		vector<FormeGeometrique *> formes_chargees;
		formes_chargees=FormeGeometrique::ChargerFormes(cor);

		//Test Sauvegarde 
		SauvegardeForme *sauv = new SauvegardeForme;
		segment1.accepteSauvegarde(sauv);
		fc.accepteSauvegarde(sauv);
		polygone1.accepteSauvegarde(sauv);
		cercle1.accepteSauvegarde(sauv);
		triangle1.accepteSauvegarde(sauv);

		//Test dessin
		VisiteurDessinJava *visiteurDessin = new VisiteurDessinJava;
		for (int i = 0; i < formes_chargees.size(); i++) {
			formes_chargees[i]->dessin(visiteurDessin);
		}

		//Liberation pointeurs
		delete corCercle, corSegment, corPolygone, corFormeComposee, corTriangle,cor;
		for (i = 0; i < formes_chargees.size(); i++) {

			delete formes_chargees[i];

		}
		formes_chargees.clear();

		delete s, f, c, t, p;
		delete sauv, visiteurDessin;
	}
	catch (Erreur e) {

		cerr << e.getMessage();
		exit(1);
	}

	getchar();
	return 0;
}