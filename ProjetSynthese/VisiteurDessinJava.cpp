#include "pch.h"
#include "VisiteurDessinJava.h"

VisiteurDessinJava::VisiteurDessinJava(EnvoyeurReceveur * e) : connexion(e) {}

VisiteurDessinJava::~VisiteurDessinJava(){}

void VisiteurDessinJava::dessiner(const Cercle * c) const
{
	string message = string(*c);
	cout << message;
	connexion->envoyer(message.c_str());

	string reponse = connexion->recevoir();

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
	connexion->envoyer(message.c_str());

	string reponse = connexion->recevoir();

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
	connexion->envoyer(message.c_str());

	string reponse = connexion->recevoir();

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
	connexion->envoyer(message.c_str());

	string reponse = connexion->recevoir();

	if (reponse != "") {
		cout << reponse << endl;
	}
	else {
		cout << "il y a eu une erreur lors de l'envoi" << endl;
	}
}

void VisiteurDessinJava::dessiner(const FormeComposee * f) const
{
	string message = string(*f);
	cout << message;
	connexion->envoyer(message.c_str());

	string reponse = connexion->recevoir();

	if (reponse != "") {
		cout << reponse << endl;
	}
	else {
		cout << "il y a eu une erreur lors de l'envoi" << endl;
	}
}
