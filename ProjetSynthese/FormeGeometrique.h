#pragma once
#include <iostream>
#include "Vecteur2D.h"
#include "Erreur.h"
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

class VisiteurForme;
class VisiteurSauvegarde;
class InterfaceChargement;

/**
* \class FormeGeometrique
* \brief Classe FormeGeometrique qui modélise une forme . Classe mère 
*/
class FormeGeometrique
{
protected :
	string couleur;
public:
	FormeGeometrique();
	FormeGeometrique(const FormeGeometrique &);
	FormeGeometrique(const string &);
	virtual ~FormeGeometrique();

	virtual FormeGeometrique * clone() const= 0;

	/**
	* \brief Effectue l'homothetie d'une forme géométrique
	* Renvoie un nouvel objet
	* \param[in] v : centre d'homothetie
	* \param[in] rapport
	*/
	virtual FormeGeometrique * homothetie(const Vecteur2D &,const double)const =0;

	/**
	* \brief Effectue l'homothetie d'une forme géométrique
	* Modifie l'objet this
	* \param[in] v : centre d'homothetie
	* \param[in] rapport
	*/
	virtual void homothetie2(const Vecteur2D &, const double)=0;

	/**
	* \brief Effectue la rotation d'une forme géométrique
	* Renvoie un nouvel objet
	* \param[in] v : centre de rotation
	* \param[in] angle : angle de rotation
	*/
	virtual FormeGeometrique* rotation(const Vecteur2D &,const double angle)const=0;

	/**
	* \brief Effectue la rotation d'une forme géométrique
	* Modifie l'objet this
	* \param[in] v : centre de rotation
	* \param[in] angle : angle de rotation
	*/
	virtual void rotation2(const Vecteur2D &, const double)=0;

	/**
	* \brief Effectue la translation d'une forme geometrique
	* Renvoie un nouvel objet
	* \param[in] v : vecteur par rapport auquel on effectue la translation
	*/
	virtual FormeGeometrique *translation(const Vecteur2D &v)const=0;

	/**
	* \brief Effectue la translation d'une forme geometrique
	* Modifie l'objet this
	* \param[in] v : vecteur par rapport auquel on effectue la translation
	*/
	virtual void translation2(const Vecteur2D &)=0;

	virtual const double getAire()const = 0;
	const string getCouleur() const;
	void setCouleur(const string &);

	virtual operator string() const=0;
	virtual void affiche()const = 0;

	bool operator != (const FormeGeometrique &f)const { return !(this == &f); }

	/**
	*\brief Accepte le visiteur qui va envoyer l'instruction de desssin au serveur
	*/
	virtual void dessin(const VisiteurForme *)const=0;

	/**
	*\brief Accepte le visiteur qui va sauvegarder la forme dans un fichier
	*/
	void accepteSauvegarde(const VisiteurSauvegarde *visiteur)const;

	friend ostream &operator << (ostream &os, const FormeGeometrique &f);
	//virtual friend istream &operator >>(istream &is, FormeGeometrique *f)=0;

	static void ChargerFormes(vector <FormeGeometrique*> &formes, InterfaceChargement *cor);

};

