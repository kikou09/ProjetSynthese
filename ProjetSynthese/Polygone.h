#pragma once
#include "FormeSimple.h"
#include "Vecteur2D.h"
#include <iostream>
#include <vector>

using namespace std;

class FormeSimple;
/**
* \class Polygone
* \brief Classe Polygone qui modélise un polygone et qui dérive de FormeSimple
* Un polygone est un ensemble de points
* Un polygone a au moins 3 points
 * Les points sont reliés dans l'ordre donnée: si on insère un point dans un polygone, il sera relié au premier et dernier point
*/
class Polygone : public FormeSimple
{
private :
	vector <Vecteur2D*> formes;

public:
	Polygone(const string &couleur,Vecteur2D *p1, Vecteur2D *p2, Vecteur2D *p3);
	Polygone();
	Polygone(const Polygone &);
	virtual ~Polygone();
	Polygone*  clone() const;


	/**
	 * \brief getVecteur
	 * \param indice
	 * \return Une copie du point à la position demandée, ou NULL si l'indice est incorrect.
	 */
	Vecteur2D * getVecteur(const int indice)const;

	/**
	* \brief ajoutVecteur
	* \param p
	* Ajoute un point à la suite des autres
	*/
	void ajoutVecteur(Vecteur2D *v);
	void supprimerDernier();

	virtual Polygone * homothetie(const Vecteur2D &v,  const double)const ;
	virtual Polygone * rotation(const Vecteur2D &v , const double angle)const;
	virtual Polygone * translation(const Vecteur2D &v)const;

	const double getAire() const;

	void operator =(const Polygone&);
	bool operator ==(const Polygone&)const;
	bool operator != (const Polygone&polygone)const { return !(this == &polygone); }
	operator string() const;
	friend ostream & operator << (ostream &os, const Polygone &);
	friend istream &operator >> (istream& is, const Polygone &);

	void affiche() const;

	void dessin(const VisiteurForme *)const;


};

