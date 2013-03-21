/**
* Scytale
*
* Chez les Spartiates, la scytale �tait un b�ton de bois utilis� pour lire ou �crire une d�p�che chiffr�e. Consid�r�e
* comme le plus ancien dispositif de cryptographie militaire connue, elle permettait l'inscription d'un message chiffr�
* sur une fine lani�re de cuir ou de parchemin que le messager pouvait porter � sa ceinture.
* Apr�s avoir enroul� la ceinture sur la scytale, le message �tait �crit en pla�ant une lettre sur chaque circonvolution. Pour
* le d�chiffrer, le destinataire devait poss�der un b�ton d'un diam�tre identique � celui utilis� pour l'encodage. Il lui suffit
* d'enrouler la scytale autour de ce b�ton pour obtenir le message en clair.
*
*
* Le diam�tre du scytale sera la cl� de cryptage. Le diam�tre repr�sentera le nombre de lettre que l'on peut mettre en faisant un tour du scytale.
* Pour un diam�tre de 1, on peut positionner 1 lettre par tour complet.
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

