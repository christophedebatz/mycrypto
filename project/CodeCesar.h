/**
* Le code de C�sar.
*
* Le code de C�sar est la m�thode de cryptographie la plus ancienne commun�ment admise par l'histoire. Il consiste
* en une substitution mono-alphab�tique, o� la substitution est d�finie par un d�calage de lettres.
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
