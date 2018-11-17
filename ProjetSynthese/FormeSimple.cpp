#include "pch.h"
#include "FormeSimple.h"


FormeSimple::FormeSimple(){}

FormeSimple::FormeSimple(const string &c) : FormeGeometrique(c){}

FormeSimple::FormeSimple(const FormeSimple &forme_s) : FormeGeometrique(forme_s)
{
}

FormeSimple::~FormeSimple(){}
