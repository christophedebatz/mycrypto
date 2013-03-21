/**
* Le code de César.
*
* Le code de César est la méthode de cryptographie la plus ancienne communément admise par l'histoire. Il consiste
* en une substitution mono-alphabétique, où la substitution est définie par un décalage de lettres.
*
*/



#ifndef CODECESAR
#define CODECESAR
#include <iostream>
#include <string>
#include "FonctionsTraitement.h"
using namespace std;



class CodeCesar : FonctionsTraitement
{
private:
    string codeNonChiffre;
    string codeChiffre;
    int decalage;


private:
//Setters
    void setCodeNonChiffre (string);
    void setCodeChiffre (string);
    void setDecalage (int);
public:
//Getters
    string getCodeNonChiffre ();
    string getCodeChiffre ();
    int getDecalage ();
//Constructeur
    CodeCesar ();
//Destructeur
    ~CodeCesar ();
//Fonctions de traitement
    void chiffrage (string, int);
    void dechiffrage (string, int);
    void cryptanalyse (string);


};
#endif
