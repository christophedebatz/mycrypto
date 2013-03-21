#include "Scytale.h"

#include <iostream>
#include <stdlib.h>

/**
*  Constructeur
*
*   @param  void
*   @return void
*
*/
Scytale::Scytale ()
{}

/**
*  Destructeur
*
*   @param  void
*   @return void
*
*/
Scytale::~Scytale ()
{}

/**
*  Setter de la variable codeNonChiffre
*
*   @param  string  : variable qui contient la chaîne de caractère en claire
*   @return void
*
*/

void Scytale::setCodeNonChiffre (string _codeNonChiffre)
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
void Scytale::setCodeChiffre (string _codeChiffre)
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
void Scytale::setDiametre (unsigned int _diametre)
{
    diametre = _diametre;
}

/**
*  Getter de la variable codeNonChiffre
*
*   @param  void
*   @return string : on renvoie la valeur de la variable codeNonChiffre
*
*/
string Scytale::getCodeNonChiffre ()
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
string Scytale::getCodeChiffre ()
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
unsigned int Scytale::getDiametre ()
{
    return diametre;
}



/**
*  Fonction de chiffrage sur les caractères de l'alphabet
*
*   @param  string  : le texte à chiffrer
*   @param  int     : le diamètre du scytale qui va servir à chiffrer le texte
*   @return void
*
*/
void Scytale::chiffrage (string texteAChiffrer, unsigned int diametre)
{
    char tmpChar;
    setCodeNonChiffre(texteAChiffrer);
    setDiametre(diametre);
    string tmp= getCodeNonChiffre();
    string tmpCodeChiffre;

    if (getDiametre() == 0)
        {
            setCodeChiffre("DIAMETRE DE 0");
            return ;
        }
    //Ici on vérifie que le texte a chiffrer est bien compris entre A et Z. Le texte est ensuite mis en majuscule.
    for (unsigned int i=0; i < getCodeNonChiffre().length(); i++)
    {
        if (!FonctionsTraitement::estCharactereAutorise(getCodeNonChiffre()[i]))
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
    setCodeNonChiffre(tmp);
    if ( getCodeNonChiffre().length() < getDiametre())
    {
        setCodeChiffre(getCodeNonChiffre());
    }

    else
    {

        unsigned int charParLigne = getCodeNonChiffre().length()/getDiametre(), cpt=0;
        //On vérifie s'il y a besoin d'ajouter une ligne ou pas par exemple, un mot de 7 lettres demandera 2 lignes de diametre 3 et le debut d'une 3ème ligne

        if (getCodeNonChiffre().length()%getDiametre() != 0)
            charParLigne+=1;

        char laniere[getDiametre()][charParLigne];
        for (unsigned int i = 0; i < getDiametre() ; i++)
        {
            for (unsigned int j = 0; j < charParLigne; j++)
            {
                if ((cpt+1) > getCodeNonChiffre().length() || getCodeNonChiffre()[cpt] == ' ')
                    laniere[i][j] = ' ';
                else
                    laniere[i][j] = getCodeNonChiffre()[cpt];
                cpt++;
            }
        }

        string tmpCodeChiffre (charParLigne*getDiametre(), ' ');//Initialisation d'un string
        cpt=0;
        for (unsigned int i = 0; i < charParLigne ; i++)
        {
            for (unsigned int j = 0; j < getDiametre(); j++)
            {
                tmpCodeChiffre[cpt] = laniere[j][i];
                cpt++;
            }
        }
        setCodeChiffre(tmpCodeChiffre);
    }
}


/**
*  Fonction de déchiffrage sur les caractères de l'alphabet
*
*   @param  string  : le texte à déchiffrer
*   @param  int     : le diamètre du scytale qui va servir à déchiffrer le texte
*   @return void
*
*/
void Scytale::dechiffrage (string texteADechiffrer, unsigned int diametre){
    char tmpChar;
    setCodeChiffre(texteADechiffrer);
    setDiametre(diametre);
    string tmp= getCodeChiffre();
    string tmpCodeChiffre;

    if (getDiametre() == 0)
    {
        setCodeNonChiffre("DIAMETRE DE 0");
        return ;
    }
    //Ici on vérifie que le texte a déchiffrer est bien compris entre A et Z. Le texte est ensuite mis en majuscule.
    for (unsigned int i=0; i < getCodeChiffre().length(); i++)
    {
        if (!FonctionsTraitement::estCharactereAutorise(getCodeChiffre()[i]))
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
    setCodeChiffre(tmp);
    if ( getCodeChiffre().length() < getDiametre())
    {
        setCodeNonChiffre(getCodeChiffre());
        cout << getCodeChiffre().length() << "  " << getDiametre();
    }

    else
    {

        unsigned int charParLigne = getCodeChiffre().length()/getDiametre(), cpt=1;

        //On vérifie s'il y a besoin d'ajouter une ligne ou pas par exemple, un mot de 7 lettres demandera 2 lignes de diametre 3 et le debut d'une 3ème ligne

        if (getCodeNonChiffre().length()%getDiametre() != 0)
            charParLigne+=1;

        char laniere[getDiametre()][charParLigne];
        for (unsigned int i = 0; i < charParLigne ; i++)
        {
            for (unsigned int j = 0; j < getDiametre() ; j++)
            {
                if (cpt > getCodeChiffre().length() || getCodeChiffre()[cpt-1] == ' ')
                    laniere[j][i] = ' ';
               // else if( getCodeChiffre()[cpt-1] == ',' || getCodeChiffre()[cpt-1] == '\'' || getCodeChiffre()[cpt-1] == '.' ){}
                else
                    laniere[j][i] = getCodeChiffre()[cpt-1];
                cpt++;
            }
        }

        string tmpCodeChiffre (charParLigne*getDiametre(), ' ');
        cpt=0;
        for (unsigned int i = 0; i < getDiametre() ; i++)
        {
            for (unsigned int j = 0; j < charParLigne ; j++)
            {
                tmpCodeChiffre[cpt] = laniere[i][j];
                cpt++;
            }
        }
        setCodeNonChiffre(tmpCodeChiffre);
    }
}

/**
*    Fonction de cryptanalyse du scytale. On applique une analyse frequentielle sur les bigrammes générées par des matrices différentes
*
*   @param  string  : le texte à casser
*   @return void
*
*   Note:
*   Efficace sur des textes d'une certaine longueur, pour que le pourcentage de probilite des bigrammes soient bons
*
*
*/

//Bigrammes 	Pourcentages
//    ES  	3,15%
//    LE  	2,46%
//    EN  	2,42%
//    DE  	2,15%
//    RE 	2,09%
//    NT 	1,97%
//    ON  	1,64%
//    TE  	1,63%
//    ER  	1,63%
//    SE  	1,55%


void Scytale::cryptanalyse (string code){
    setCodeChiffre(code);
    unsigned int cpt=2, compteurInterne, indiceMax=0, valeurMax=0;
    char tmpChar;
    string tmp= getCodeChiffre();

    //Ici on vérifie que le texte a chiffrer est bien compris entre A et Z. Le texte est ensuite mis en majuscule.
    for (unsigned int i=0; i < getCodeChiffre().length(); i++)
    {
        if (!estCharactereAutorise(getCodeChiffre()[i]))
        {
            setCodeChiffre("CHARACTERE NON AUTORISE");
            cout << "La chaine non chiffre : " << getCodeNonChiffre() << endl;
            cout << "La chaine chiffre : " << getCodeChiffre() << endl;
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

    setCodeChiffre(tmp);
    while ( (getCodeChiffre().length()/cpt) >= 2){
        cpt++;
    cout << "plop";
    }
    unsigned int bigramme[cpt-2];
    for (unsigned int i=0; i < (cpt-2);i++)
            bigramme[i]=0;


    cpt=2;
    while ( (getCodeChiffre().length()/cpt) >= 2){

        //Initialisation de la matrice temporaire
        char tmpCryptanalys[cpt][(getCodeChiffre().length() /cpt + getCodeChiffre().length() %2)];

        //On la remplis avec le message
        compteurInterne=1;
        for (unsigned i=0;i < cpt;i++)
            for (unsigned j=0;j < (getCodeChiffre().length() /cpt + getCodeChiffre().length() %2);j++){
                if ( compteurInterne > getCodeChiffre().length() || getCodeChiffre()[compteurInterne-1] == ' ')
                    tmpCryptanalys[i][j] = ' ';
                else
                    tmpCryptanalys[i][j] = getCodeChiffre()[compteurInterne-1];
                compteurInterne++;
            }

        //On génere une string à partir de la matrice générée précédemment



        string codeMatrice(compteurInterne,' ');
        compteurInterne=0;
        for (unsigned i=0;i < (getCodeChiffre().length() /cpt + getCodeChiffre().length() %2);i++)
            for (unsigned j=0;j < cpt;j++){
                codeMatrice[compteurInterne] = tmpCryptanalys[j][i];
                compteurInterne++;
            }
        //On fait une analyse des bigrammes
        for (unsigned i=0;i < compteurInterne;i++){
            if (codeMatrice.substr(i,2) == "ES")
                bigramme[cpt-2]+=1;
//            else if (codeMatrice.substr(i,2) == "LE")
//                bigramme[1]+=1;
//            else if (codeMatrice.substr(i,2) == "EN")
//                bigramme[2]+=1;
//            else if (codeMatrice.substr(i,2) == "DE")
//                bigramme[3]+=1;
        }
        cout << "bigramme1 :" << bigramme[0] << "   bigramme2   " << bigramme[1] <<  "bigramme3 :" << bigramme[2] << "   bigramme4   " << bigramme[3] << endl;
        cout << "CLE   " << cpt << "   " << getCodeChiffre().length()  /cpt  + getCodeChiffre().length() %2<< endl;
        cout << "CHAINE :  " << codeMatrice<< "|"<<endl;

        cpt++;
    }

    for (unsigned int i =0; i< (cpt-2);i++){
        if (bigramme[i] > valeurMax){
            valeurMax=bigramme[i];
            indiceMax=i+1;
        }
    }
    cout << "MAX " << indiceMax << endl;
    cout << "Valeur max" << valeurMax << endl;
       dechiffrage(code,indiceMax);


}



