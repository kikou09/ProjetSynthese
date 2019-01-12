#pragma once
#include "FormeGeometrique.h"
#include <vector>


/**
* \class FormeComposee
* \brief Classe FormeComposee qui modélise un forme composee ( qui contient plusieurs formes simples ou composees
* et qui dérive de FormeGeometrique
* Une forme ne peut pas appartenir simultanément à plusieurs groupes 	
*/
class FormeComposee :
	public FormeGeometrique
{
	private:
		vector<FormeGeometrique *> groupe;

	public:
		FormeComposee();
		FormeComposee(const string &);
		FormeComposee(const FormeComposee &);
		virtual FormeComposee*  clone() const;

		/**
		\brief Verfie si la forme appartient deja ou pas au groupe de formes 
		*\param[in] f : forme à verfier 
		*/
		bool contient(const FormeGeometrique *f)const;

		/**
		*\brief Ajoute la forme au groupe seulement si elle n'y appartient pas deja
		*\param[in] f : forme a ajouter 
		*/
		void ajouterForme(const FormeGeometrique *f);

		/**
		*\brief Supprime une forme 
		*\param[in] indice : indice de la forme à supprimer 
		*/
		void supprimerForme(const int indice);

		/**
		*\brief Supprime une forme
		* param[in] f : forme à supprimer
		*/
		void supprimerForme(const FormeGeometrique *f);

		const int getNbForme() const;
		const FormeGeometrique * getForme(const int indice)const;

		virtual FormeComposee* homothetie(const Vecteur2D &, const double)const;
		virtual void homothetie2(const Vecteur2D &v, const double);
		virtual FormeComposee * rotation(const Vecteur2D &, const double angle)const;
		virtual void rotation2(const Vecteur2D &v, const double angle);
		virtual FormeComposee * translation(const Vecteur2D &v) const;
		virtual void translation2(const Vecteur2D &v);


		/**
		*\brief Aire groupe = somme aires de toutes les formes contenues
		*/
		virtual const double getAire()const;

		virtual ~FormeComposee();

		virtual operator string() const;
		virtual void affiche()const;


		/**
		*\brief Accepte le visiteur qui va envoyer l'instruction de dessin au serveur 
		*\param[in] visiteur : visiteur qui souhaite envoyer l'instruction au serveur
		*/
		void dessin(const VisiteurForme *visiteur)const;
		//void accepteSauvegarde(const VisiteurForme *)const;

		FormeComposee & operator = (const FormeComposee &);
};

