#pragma once

#include <iostream>
#include <exception>

using namespace std;

class Erreur :
	public exception
{
public:

	string message;            //Description de l'erreur
	Erreur() throw() : message("Erreur !"){};
	Erreur(const string&phrase) throw()
		: message(phrase) {}
	Erreur(const char * messageErreur) throw() : Erreur((string)messageErreur) {}

	virtual ~Erreur() throw()
	{}

	virtual const char* getMessage() const throw()
	{
		return message.c_str();
	}

	operator string() const throw() { return this->message; }

	friend ostream & operator << (ostream &os , const Erreur &erreur)
	{ 
		return os << erreur.getMessage();
	}


};
