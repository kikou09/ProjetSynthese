#include "pch.h"
#include "VisiteurDessinJava.h"
#include "EnvoyeurReceveur.h"
#include <time.h>

VisiteurDessinJava::VisiteurDessinJava() {}

VisiteurDessinJava::~VisiteurDessinJava(){}

void VisiteurDessinJava::dessiner(const Cercle * c) const
{
	string message = string(*c);
	cout << message;
	EnvoyeurReceveur::getInstance()->envoyer(message.c_str());
	string reponse = EnvoyeurReceveur::getInstance()->recevoir();

	if ( reponse != "") {
		cout << reponse << endl;
	}
	else {
		cout << "il y a eu une erreur lors de l'envoi" << endl;
	}
}

void VisiteurDessinJava::dessiner(const Triangle * t) const
{
	string message = string(*t);
	cout << message;
	EnvoyeurReceveur::getInstance()->envoyer(message.c_str());

	string reponse = EnvoyeurReceveur::getInstance()->recevoir();

	if (reponse!= "") {
		cout << reponse << endl;
	}
	else {
		cout << "il y a eu une erreur lors de l'envoi" << endl;
	}
}

void VisiteurDessinJava::dessiner(const Polygone * p) const
{
	string message = string(*p);
	cout << message;
	EnvoyeurReceveur::getInstance()->envoyer(message.c_str());

	string reponse = EnvoyeurReceveur::getInstance()->recevoir();

	if (reponse != "") {
		cout << reponse << endl;
	}
	else {
		cout << "il y a eu une erreur lors de l'envoi" << endl;
	}
}

void VisiteurDessinJava::dessiner(const Segment * s) const
{
	string message = string(*s);
	cout << message;
	EnvoyeurReceveur::getInstance()->envoyer(message.c_str());

	string reponse = EnvoyeurReceveur::getInstance()->recevoir();

	if (reponse != "") {
		cout << reponse << endl;
	}
	else {
		cout << "il y a eu une erreur lors de l'envoi" << endl;
	}
}

void VisiteurDessinJava::dessiner(const FormeComposee * f) const
{

}
