/**
*
* Fonctions de traitement
*
* Cette classe rassemblera les fonctions de traitement sur chaines de caractères utilisées par les différents algorithmes (chiffrage,
* déchiffrege, et cryptanalyse).
*
*
*/

#ifndef FONCTIONTRAITEMENT
#define FONCTIONTRAITEMENT
#include <iostream>
#include <string>


using namespace std;

class FonctionsTraitement
{
    //Les fonctions de traitmenents
public:
    bool estCharactereAutorise (char c);
    int getIndiceTableau (char c);
    void removeAllWhite (std::string &str);
    unsigned int pgcd(unsigned int a,unsigned int b);

};



#endif
