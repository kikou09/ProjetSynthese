#include "pch.h"
#include "SauvegardeForme.h"


void SauvegardeForme::sauvegarde(const FormeGeometrique * f, const string nomFichier) const
{
	filebuf fb;
	fb.open(nomFichier, ios::out);
	ostream os(&fb);
	os << (string)*f;
	fb.close();
}
