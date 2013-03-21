/**
* La machine Enigma
*
* Description :
*
*/



#ifndef ENIGMA
#define ENIGMA
#include <iostream>
#include <string>
#include "FonctionsTraitement.h"
using namespace std;



class Enigma : FonctionsTraitement
{
    private:
//Attributs
        //Pour le chiffrement
        char* rotor0;
        char* rotor1;
        char* rotor2;
        int* rotorDecalage0;
        int* rotorDecalage1;
        int* rotorDecalage2;
        //Pour le déchiffrement
        char* rotorInverse0;
        char* rotorInverse1;
        char* rotorInverse2;
        int* rotorInverseDecalage0;
        int* rotorInverseDecalage1;
        int* rotorInverseDecalage2;

        int decalage0;
        int decalage1;
        int decalage2;
        string codeNonChiffre;
        string codeChiffre;

    private:
//Setters
        void setCodeNonChiffre (string);
        void setCodeChiffre (string);
        void setDecalage0 (int);
        void setDecalage1 (int);
        void setDecalage2 (int);

    public:
//Getters
        string getCodeNonChiffre ();
        string getCodeChiffre ();
        int getDecalage0();
        int getDecalage1();
        int getDecalage2();
//Constructeur
        Enigma ();
//Destructeur
        ~Enigma ();
//Fonctions de traitement
        void chiffrage (string, int, int, int);
        void dechiffrage (string, int, int, int);
        void cryptanalyse (string);


};
#endif

