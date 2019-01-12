#pragma once
#include <iostream>

using namespace std;
class InterfaceFormes
{
public:
	InterfaceFormes *suivant;

protected:
	InterfaceFormes(InterfaceFormes *s);
	virtual bool peutExecuter(string &choix) const = 0;
public:
	~InterfaceFormes();
};

