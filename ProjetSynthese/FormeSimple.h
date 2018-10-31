#pragma once
#include "FormeGeometrique.h"
class FormeSimple :
	public FormeGeometrique
{
public:
	FormeSimple();
	FormeSimple(const string &);
	FormeSimple(const FormeSimple &);
	virtual ~FormeSimple();
};

