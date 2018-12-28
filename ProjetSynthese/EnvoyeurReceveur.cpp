#include "pch.h"
#include "EnvoyeurReceveur.h"

#pragma comment(lib, "ws2_32.lib") // spécifique à VISUAL C++

using namespace std;


static int active = 0; // Si les DLL sont ouvertes ou non

EnvoyeurReceveur* EnvoyeurReceveur::instance = nullptr;

EnvoyeurReceveur * EnvoyeurReceveur::getInstance() {

	if (instance == nullptr)
		instance = new EnvoyeurReceveur(ADRESSE_IP, PORT_SERVEUR);
	
	return instance;
}
EnvoyeurReceveur::EnvoyeurReceveur(const char * adresseIP, short portServeur)
{
	try {

		if (!active)	this->init(); // Pour ouvrir les dll qu'une fois

		//---------------------- création socket -------------------------------------------------

		int familleAdresses = AF_INET;         // IPv4
		int typeSocket = SOCK_STREAM;           // mode connecté TCP
		int protocole = IPPROTO_TCP;            // protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers paramètres
												// pour les valeurs des paramètres : cf. fct socket dans la doc sur winsock

		sock = socket(familleAdresses, typeSocket, protocole);

		if (sock == INVALID_SOCKET)
		{
			ostringstream oss;
			oss << "la création du socket a échoué : code d'erreur = " << WSAGetLastError() << endl;	// pour les valeurs renvoyées par WSAGetLastError() : cf. doc réf winsock
			throw Erreur(oss.str().c_str());
		}

		SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer

		sockaddr.sin_family = AF_INET;
		sockaddr.sin_addr.s_addr = inet_addr(adresseIP);   // inet_addr() convertit de l'ASCII en entier
		sockaddr.sin_port = htons(portServeur);                 //htons() assure que le port est bien inscrit dans le format du réseau (little-endian ou big-endian)

		//-------------- connexion du client au serveur ---------------------------------------

		int r = connect(sock, (SOCKADDR *)&sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'échec.
																		// Le code d'erreur peut être obtenu par un appel à WSAGetLastError()

		if (r == SOCKET_ERROR)
			throw Erreur("La connexion a échoué");
	}
	catch (Erreur erreur) {
		cerr << erreur << endl;
	}
}

EnvoyeurReceveur::~EnvoyeurReceveur() {}

void EnvoyeurReceveur::init() const {

	try {
		//-------------- initialisation ressources librairie winsock -------------------------------

		WSADATA wsaData; //TODO structure contenant les données de la librairie winsock à initialiser

		int r;

		r = WSAStartup(MAKEWORD(2, 0), &wsaData);       // MAKEWORD(2,0) sert à indiquer la version de la librairie à utiliser : 1 pour winsock et 2 pour winsock2

		/* en cas de succès, wsaData a été initialisée et l'appel a renvoyé la valeur 0 */

		if (r) throw Erreur("L'initialisation a échoué");

		active = 1;

	}
	catch (Erreur erreur) {
		cerr << erreur << endl;
	}
}

void EnvoyeurReceveur::close() const {

	try {

		int r = shutdown(sock, SD_BOTH);							// on coupe la connexion pour l'envoi et la réception
																// renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()
		if (r == SOCKET_ERROR)
			throw Erreur("la coupure de connexion a échoué");


		r = closesocket(sock);                          // renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()
		if (r) throw Erreur("La fermeture du socket a échoué");

		WSACleanup();

		active = 0;
	}
	catch (Erreur erreur) {
		cerr << erreur << endl;
	}
}

void EnvoyeurReceveur::envoyer(const char* message) const {

	try {

		int l = strlen(message);
		int r = send(sock, message, l, 0);             //------------------ envoi de la requête au serveur -------------------------------
														// envoie au plus  l octets
		if (r == SOCKET_ERROR)
			throw Erreur("échec de l'envoi de la requête");
	}
	catch (Erreur erreur) {
		cerr << erreur << endl;
	}
}
const string EnvoyeurReceveur::recevoir() const {

	char reponse[L];

	try {

		int r = recv(sock, reponse, L, 0);             //----------- réception de la réponse du serveur -----------------------------
													// reçoit au plus L octets
													// en cas de succès, r contient le nombre d'octets reçus
		if (r == SOCKET_ERROR)
			throw Erreur("La réception de la réponse a échoué");

		char * p = strchr(reponse, '\n');
		*(p + 1) = '\0';

	}
	catch (Erreur erreur) {
		cerr << erreur << endl;
	}
	string msg(reponse);
	return msg;
}
