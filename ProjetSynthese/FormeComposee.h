#pragma once
#include "FormeGeometrique.h"
#include <vector>


/**
* \class FormeComposee
* \brief Classe FormeComposee qui modélise un forme composee ( qui contient plusieurs formes simples ou composees
	et qui dérive de FormeGeometrique
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
		FormeComposee*  clone() const;

		void ajouterForme(FormeGeometrique *);
		void supprimerForme(const int indice);
		void supprimerForme(const FormeGeometrique *);

		virtual FormeComposee* homothetie(const Vecteur2D &, const double)const;
		virtual FormeComposee * rotation(const Vecteur2D &, const double angle)const;
		virtual FormeComposee * translation(const Vecteur2D &v) const;
		virtual const double getAire()const;

		virtual ~FormeComposee();

		virtual operator string() const;
		virtual void affiche()const;

		void dessin(const VisiteurForme *)const;
		void accepteSauvegarde(const VisiteurForme *)const;
};

