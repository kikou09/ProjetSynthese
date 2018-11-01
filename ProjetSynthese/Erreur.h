#pragma once

#include <iostream>
#include <exception>

using namespace std;

class Erreur :
	public exception
{
public:

	string message;            //Description de l'erreur
	Erreur() : message("Erreur !") {};
	Erreur(const string&phrase)
		: message(phrase) {}
	Erreur(const char * messageErreur) : Erreur((string)messageErreur) {}

	virtual ~Erreur()
	{}

	virtual const char* getMessage() const 
	{
		return message.c_str();
	}

	operator string() const { return this->message; }

	friend ostream & operator << (ostream &os , const Erreur &erreur)
	{ 
		return os << erreur;
	}


};
