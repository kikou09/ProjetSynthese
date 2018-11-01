#include "pch.h"
#include "InterfaceSegment.h"
#include "Segment.h"


bool InterfaceSegment::peutExecuter(string & choix) const
{
	return choix == getDescription();
}

InterfaceSegment::InterfaceSegment(InterfaceForme * s) :InterfaceForme(s)
{
}

InterfaceSegment::~InterfaceSegment()
{
}

const char * InterfaceSegment::toString() const
{
	return nullptr;
}

string InterfaceSegment::getDescription() const
{
	return "Segment";
}

void InterfaceSegment::executerInteraction(FormeGeometrique *forme) const
{
	Segment segment;
	cin >> segment;
	forme = &segment;
	forme->affiche();
}
