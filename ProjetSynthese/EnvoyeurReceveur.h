#pragma once
#include <iostream>
#include <string>
#include <winsock2.h>
#include <sstream>
#include "Erreur.h" 

using namespace std;

#define ADRESSE_IP "192.168.1.73"
#define PORT_SERVEUR 9111

const static int L = 200;

/*! \class EnvoyeurReceveur
*\brief Classe EnvoyeurReceveur
*
*\La classe permet la connection à un socket distant à partir
* de ses champs
*/
class EnvoyeurReceveur{

private:
	SOCKET sock;

public:

	EnvoyeurReceveur(const char* adresseIP, short portServeur);
	~EnvoyeurReceveur();

	void init() const;

	void close() const;

	/*!
	*\brief permet d'envoyer une chaine de caractère
	*au serveur java
	*
	*/
	void envoyer(const char* message) const;

	/*!
	*\brief permet de récuperer le message du serveur java
	*
	*\return string : message du serveur java
	*/
	const string recevoir() const;

};