#pragma once
#include <istream>

using namespace std;

template <class T>
inline const T operator - (const T & u, const T & v)
{
	return u + -v;
}

/**
	\class
	\author 
*/
class Vecteur2D : FormeSimple
{
public:
	
	double x, y;

	inline explicit Vecteur2D(const double & x = 0, const double & y = 0);
	/**
	 * DONNEES : s respectant le format "(  nombre réel, nombre réel)"
	 *
	 * */
	inline Vecteur2D(const char * s);
	inline const Vecteur2D operator + (const Vecteur2D & u) const;
	inline const Vecteur2D operator * (const double & a) const;
	/**
	 * - unaire (c'est-à- dire opposé d'un vecteur)
	 * */
	inline const Vecteur2D operator - () const;

	const double getAire() const;
	const double getX() const;
	const double getY() const;

	virtual void homothetie(const double x, const double y, const double rapport);
	virtual void rotation(const double x, const double y, const double angle);
	virtual void translation(const Vecteur2D *v);

	operator string() const;
	friend ostream & operator << (ostream &os ,const Vecteur2D &u);

}; 



