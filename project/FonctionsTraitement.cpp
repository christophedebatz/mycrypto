#include "FonctionsTraitement.h"

#include <iostream>
#include <stdlib.h>


/**
*  Fonction qui vérifie si le caractère est une lettre de l'alphabet
*
*   @param  char    : le charactère a traiter
*   @return  bool   : renvoie true si c'est une lettre de l'alphabet ou un espace, false sinon
*
*/
bool FonctionsTraitement::estCharactereAutorise (char c){
    return ( (c>=65 && c<=90) || (c>=97 && c<=122) || (c == ' ') || (c == '\'') || (c == ',') || (c == '.'))?true:false;
}


int FonctionsTraitement::getIndiceTableau (char c){
    return c-65;
}

/**
*  Fonction qui supprime les espaces dans une chaine de caractere
*
*   @param  char    : le charactère a traiter
*   @return  bool   : renvoie true si c'est une lettre de l'alphabet ou un espace, false sinon
*
*/
void FonctionsTraitement::removeAllWhite (std::string &str)
{
    string temp="";
    for (unsigned int i = 0; i < str.length(); i++){
        if (str[i] == ' ' || str[i] == '\'' || str[i] == ',' || str[i] == '.'){}
        else{
             temp.push_back(str[i]);
        }
    }
    str = temp;
}


/**
* PGCD
*/
unsigned int FonctionsTraitement::pgcd(unsigned int a,unsigned int b)
{
    return b ?  pgcd(b,a%b) : a;
}


