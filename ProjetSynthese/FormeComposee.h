#pragma once
#include "FormeGeometrique.h"
#include <vector>

class FormeComposee :
	public FormeGeometrique
{
	private:
		vector<FormeGeometrique *> groupe;

	public:
		FormeComposee();
		FormeComposee(const string &);
		FormeComposee(const FormeComposee &);

		void ajouterForme(FormeGeometrique *);
		void supprimerForme(const int indice);
		void supprimerForme(const FormeGeometrique *);

		virtual void homothetie(const double x, const double y, const double);
		virtual void rotation(const double x, const double y, const double angle);
		virtual void translation(const Vecteur2D *v) ;
		virtual const double getAire()const;

		virtual ~FormeComposee();
};
