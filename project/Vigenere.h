/**
* Le chiffre de Vigenere
*
* Description :
*
* Le chiffre de Vigenère est une amélioration décisive du chiffre de César.
* Sa force réside dans l'utilisation non pas d'un, mais de 26 alphabets décalés pour chiffrer un message.
* On peut résumer ces décalages avec un carré de Vigenère.
* Ce chiffre utilise une clef qui définit le décalage pour chaque lettre du message (A: décalage de 0 cran, B: 1 cran, C: 2 crans, ..., Z: 25 crans).
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
