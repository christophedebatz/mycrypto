/**
* Scytale
*
* Chez les Spartiates, la scytale était un bâton de bois utilisé pour lire ou écrire une dépêche chiffrée. Considérée
* comme le plus ancien dispositif de cryptographie militaire connue, elle permettait l'inscription d'un message chiffré
* sur une fine lanière de cuir ou de parchemin que le messager pouvait porter à sa ceinture.
* Après avoir enroulé la ceinture sur la scytale, le message était écrit en plaçant une lettre sur chaque circonvolution. Pour
* le déchiffrer, le destinataire devait posséder un bâton d'un diamètre identique à celui utilisé pour l'encodage. Il lui suffit
* d'enrouler la scytale autour de ce bâton pour obtenir le message en clair.
*
*
* Le diamètre du scytale sera la clé de cryptage. Le diamètre représentera le nombre de lettre que l'on peut mettre en faisant un tour du scytale.
* Pour un diamètre de 1, on peut positionner 1 lettre par tour complet.
*/


#ifndef SCYTALE
#define SCYTALE
#include <iostream>
#include <string>
#include "FonctionsTraitement.h"

using namespace std;

class Scytale : FonctionsTraitement
{
private:
    string codeNonChiffre;
    string codeChiffre;
    int diametre;


private:
//Setters
    void setCodeNonChiffre (string);
    void setCodeChiffre (string);
    void setDiametre (unsigned int);
public:
//Constructeur
    Scytale ();
//Destructeur
    ~Scytale ();
//Getters
    string getCodeNonChiffre ();
    string getCodeChiffre ();
    unsigned int getDiametre();

//Fonctions de traitement
    void chiffrage (string, unsigned int);
    void dechiffrage (string, unsigned int);
    void cryptanalyse (string);
};
#endif

