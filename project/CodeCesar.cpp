#include "CodeCesar.h"

#include <iostream>

using namespace std;


/**
*  Constructeur
*
*   @param  void
*   @return void
*
*/
CodeCesar::CodeCesar ()
{}

/**
*  Destructeur
*
*   @param  void
*   @return void
*
*/
CodeCesar::~CodeCesar ()
{}

/**
*  Setter de la variable codeNonChiffre
*
*   @param  string  : variable qui contient la chaîne de caractère en claire
*   @return void
*
*/

void CodeCesar::setCodeNonChiffre (string _codeNonChiffre)
{
    codeNonChiffre = _codeNonChiffre;
}

/**
*  Setter de la variable codeChiffre
*
*   @param  string  : variable qui contient la chaîne de caractère chiffrée
*   @return void
*
*/
void CodeCesar::setCodeChiffre (string _codeChiffre)
{
    codeChiffre = _codeChiffre;
}

/**
*  Setter de la variable decalage
*
*   @param  string  : variable qui contient le décalage de lettre
*   @return void
*
*/
void CodeCesar::setDecalage (int _decalage)
{
    decalage = _decalage;
}

/**
*  Getter de la variable codeNonChiffre
*
*   @param  void
*   @return string : on renvoie la valeur de la variable codeNonChiffre
*
*/
string CodeCesar::getCodeNonChiffre ()
{
    return codeNonChiffre;
}

/**
*  Getter de la variable codeChiffre
*
*   @param  void
*   @return string : on renvoie la valeur de la variable codeChiffre
*
*/
string CodeCesar::getCodeChiffre ()
{
    return codeChiffre;
}

/**
*  Getter de la variable decalage
*
*   @param  void
*   @return string : on renvoie la valeur de la variable decalage
*
*/
int CodeCesar::getDecalage ()
{
    return decalage;
}

/**
*  Fonction de chiffrage sur les caractères de l'alphabet
*
*   @param  string  : le texte à chiffrer
*   @param  int     : le décalage a appliquer au texte à chiffrer
*   @return void
*
*/
void CodeCesar::chiffrage (string texteAChiffrer, int decalage)
{
    char tmpChar;
    setCodeNonChiffre(texteAChiffrer);
    setDecalage(decalage%26);
    string tmp= getCodeNonChiffre();

    //Ici on vérifie que le texte a chiffrer est bien compris entre A et Z. Le texte est ensuite mis en majuscule.
    for (unsigned int i=0; i < getCodeNonChiffre().length(); i++)
    {
        if (!estCharactereAutorise(getCodeNonChiffre()[i]))
        {
            setCodeChiffre("CHARACTERE NON AUTORISE");
            return ;
        }
        else
        {
            if ( (getCodeNonChiffre()[i] >= 97) && (getCodeNonChiffre()[i] <= 122) )
            {
                tmpChar = tmp[i]-32;
                tmp[i]= tmpChar;
            }
        }
    }
    //On applique le décalage
    for (unsigned int i=0; i < getCodeNonChiffre().length(); i++)
    {
        if (tmp[i] == ' ' || tmp[i] == '\'' || tmp[i] == ',' || tmp[i] == '.') {}
        else if ( (getDecalage()+tmp[i]) > 90 )
        {
            tmpChar = getDecalage() + tmp[i] - 26 ;
            tmp[i]= tmpChar;
        }
        else
        {
            tmpChar = tmp[i]+getDecalage();
            tmp[i]= tmpChar;
        }


    }
    setCodeChiffre(tmp);
}

/**
*  Fonction de déchiffrage sur les caractères de l'alphabet
*
*   @param  string  : le texte à déchiffrer
*   @param  int     : le décalage a appliquer au texte à déchiffrer
*   @return void
*
*/
void CodeCesar::dechiffrage (string texteADechiffrer, int decalage)
{
    char tmpChar;
    setCodeChiffre(texteADechiffrer);
    setDecalage(decalage%26);
    string tmp= getCodeChiffre();

    //Ici on vérifie que le texte a chiffrer est bien compris entre A et Z. Le texte est ensuite mis en majuscule.
    for (unsigned int i=0; i < getCodeChiffre().length(); i++)
    {
        if (!estCharactereAutorise(getCodeChiffre()[i]))
        {
            setCodeChiffre("CHARACTERE NON AUTORISE");
            return ;
        }
        else
        {
            if ( (getCodeChiffre()[i] >= 97) && (getCodeChiffre()[i] <= 122) )
            {
                tmpChar = tmp[i]-32;
                tmp[i]= tmpChar;
            }
        }
    }
    //On applique le décalage
    for (unsigned int i=0; i < getCodeChiffre().length(); i++)
    {
        if (tmp[i] == ' ' || tmp[i] == ' ' || tmp[i] == '\'' || tmp[i] == ',' || tmp[i] == '.') {}
        else if ( (tmp[i]) - getDecalage() <65 )
        {
            tmpChar =  26 - getDecalage() + tmp[i];

            tmp[i]= tmpChar;
        }
        else
        {
            tmpChar = tmp[i]-getDecalage();
            tmp[i]= tmpChar;
        }

    }
    setCodeNonChiffre(tmp);



}


/**
*    Fonction de cryptanalyse de cesar. On applique une analyse frequentielle. La lettre E servira de référence (lettre la plus utilisée dans la langue francaise)
*
*   @param  string  : le texte à casser
*   @return void
*
*   Note:
*   Efficace sur des textes d'une certaine longueur.
*
*
*/

void CodeCesar::cryptanalyse (string code)
{
    int frequence[26]={0}, max=0, maxIndice=0;
    setCodeChiffre(code);
    char tmpChar;
    string tmp= getCodeChiffre();
    for (unsigned int i=0; i < 26;i++){
        frequence[i]=0;
    }

    //Ici on vérifie que le texte a chiffrer est bien compris entre A et Z. Le texte est ensuite mis en majuscule.
    for (unsigned int i=0; i < getCodeChiffre().length(); i++)
    {
        if (!estCharactereAutorise(getCodeChiffre()[i]))
        {
            setCodeChiffre("CHARACTERE NON AUTORISE");
            return ;
        }
        else
        {
            if ( (getCodeChiffre()[i] >= 97) && (getCodeChiffre()[i] <= 122) )
            {
                tmpChar = tmp[i]-32;
                tmp[i]= tmpChar;
            }
        }
    }
//On remplis le tebleau de frequence d'apparition des lettres
    for (unsigned int i=0; i < code.length();i++){
        if (code[i]>=65 && code[i]<=90)
            frequence[getIndiceTableau(code[i])]+=1;
    }
//Pour afficher frequence[]
//    for (unsigned int i=0; i < 26;i++){
//            cout << frequence[i]<<endl;
//    }

//On détermine la lettre qui a le plus d'apparition
    for (unsigned int i=0; i < 26;i++){
        if (frequence[i] > max){
            max = frequence[i];
            maxIndice=i;
        }
    }
    //Code debug: cout << "max    " << max <<"  maxIndice   " << maxIndice << "    Indice Tableau    " << getIndiceTableau('H') << endl;
    if (maxIndice >= 4)
        setDecalage(maxIndice-4);
    else
        setDecalage(4-maxIndice);
    //Code debug: cout << "Decalage    " << getDecalage() <<endl;
    dechiffrage(code,getDecalage());
}
