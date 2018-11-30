#include "pch.h"
#include "Java.h"

Java::Java(EnvoyeurReceveur * c):connexion(c){}

Java::~Java(){}

void Java::dessiner(const Cercle * c) const
{
	string message = (string)*c;
	cout << message;
	connexion->envoyer(message.c_str());

	if (connexion->recevoir() == "") {
		cout << "le serveur a bien reçu le cercle" << endl;
	}
	else {
		cout << "il y a eu une erreur lors de l'envoie" << endl;
	}

}

void Java::dessiner(const Triangle * t) const
{
	string message = (string)*t;
	cout << message;
	connexion->envoyer(message.c_str());

	if (connexion->recevoir() != "") {
		cout << "le serveur a bien reçu le triangle" << endl;
	}
	else {
		cout << "il y a eu une erreur lors de l'envoie" << endl;
	}

}

void Java::dessiner(const Polygone * p) const
{
	string message = (string)*p;
	cout << message;
	connexion->envoyer(message.c_str());

	if (connexion->recevoir() != "") {
		cout << "le serveur a bien reçu le polygone" << endl;
	}
	else {
		cout << "il y a eu une erreur lors de l'envoie" << endl;
	}
}

void Java::dessiner(const Segment * s) const
{
	string message = (string)*s;
	cout << message;
	connexion->envoyer(message.c_str());

	if (connexion->recevoir() != "") {
		cout << "le serveur a bien reçu le segment" << endl;
	}
	else {
		cout << "il y a eu une erreur lors de l'envoie" << endl;
	}
}

void Java::dessiner(const FormeComposee * f) const
{
	string message = (string)*f;
	cout << message;
	connexion->envoyer(message.c_str());

	if (connexion->recevoir() != "") {
		cout << "le serveur a bien reçu la forme composee " << endl;
	}
	else {
		cout << "il y a eu une erreur lors de l'envoie" << endl;
	}
}
