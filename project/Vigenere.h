/**
* Le chiffre de Vigenere
*
* Description :
*
* Le chiffre de Vigen�re est une am�lioration d�cisive du chiffre de C�sar.
* Sa force r�side dans l'utilisation non pas d'un, mais de 26 alphabets d�cal�s pour chiffrer un message.
* On peut r�sumer ces d�calages avec un carr� de Vigen�re.
* Ce chiffre utilise une clef qui d�finit le d�calage pour chaque lettre du message (A: d�calage de 0 cran, B: 1 cran, C: 2 crans, ..., Z: 25 crans).
*
*/


#ifndef VIGENERE
#define VIGENERE
#include <iostream>
#include <string>
#include <vector>
#include "FonctionsTraitement.h"
using namespace std;



class Vigenere : FonctionsTraitement
{
    private:
        string codeNonChiffre;
        string codeChiffre;
        string cle;


    private:
//Setters
        void setCodeNonChiffre (string);
        void setCodeChiffre (string);
        void setCle (string);

    public:
//Getters
        string getCodeNonChiffre ();
        string getCodeChiffre ();
        string getCle ();
//Constructeur
        Vigenere ();
//Destructeur
        ~Vigenere ();
//Fonctions de traitement
        void chiffrage (string, string);
        void dechiffrage (string, string);
        void cryptanalyse (string);


};
#endif
