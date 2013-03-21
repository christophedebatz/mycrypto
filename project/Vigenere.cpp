#include "Vigenere.h"

#include <iostream>

using namespace std;


/**
*  Constructeur
*
*   @param  void
*   @return void
*
*/
Vigenere::Vigenere ()
{}

/**
*  Destructeur
*
*   @param  void
*   @return void
*
*/
Vigenere::~Vigenere ()
{}

/**
*  Setter de la variable codeNonChiffre
*
*   @param  string  : variable qui contient la chaîne de caractère en claire
*   @return void
*
*/

void Vigenere::setCodeNonChiffre (string _codeNonChiffre){
    codeNonChiffre = _codeNonChiffre;
}

/**
*  Setter de la variable codeChiffre
*
*   @param  string  : variable qui contient la chaîne de caractère chiffrée
*   @return void
*
*/
void Vigenere::setCodeChiffre (string _codeChiffre){
    codeChiffre = _codeChiffre;
}

/**
*  Setter de la variable cle
*
*   @param  string  : variable qui contient la cle
*   @return void
*
*/
void Vigenere::setCle (string _cle){
    cle = _cle;
}

/**
*  Getter de la variable codeNonChiffre
*
*   @param  void
*   @return string : on renvoie la valeur de la variable codeNonChiffre
*
*/
string Vigenere::getCodeNonChiffre (){
    return codeNonChiffre;
}

/**
*  Getter de la variable codeChiffre
*
*   @param  void
*   @return string : on renvoie la valeur de la variable codeChiffre
*
*/
string Vigenere::getCodeChiffre (){
    return codeChiffre;
}

/**
*  Getter de la variable decalage
*
*   @param  void
*   @return string : on renvoie la valeur de la variable decalage
*
*/
string Vigenere::getCle (){
    return cle;
}

/**
*  Fonction de chiffrage sur les caractères de l'alphabet
*
*   @param  string  : le texte à chiffrer
*   @param  cle     : la cle permettant de chiffrer le texte
*   @return void
*
*/
void Vigenere::chiffrage (string texteAChiffrer, string cleAUtiliser){
    char tmpChar;
    setCodeNonChiffre(texteAChiffrer);
    setCle(cleAUtiliser);
    string tmp= getCodeNonChiffre();
    string tmpKey= getCle();
    unsigned int j=0;

    //Ici on vérifie que le texte a chiffrer est bien compris entre A et Z. Le texte est ensuite mis en majuscule.
    for (unsigned int i=0; i < getCodeNonChiffre().length(); i++){
        if (!estCharactereAutorise(getCodeNonChiffre()[i])){
            //cout << "test " << i << getCodeNonChiffre()[i] << endl;
            setCodeChiffre("CHARACTERE NON AUTORISE");
            cout << "La chaine non chiffre : " << getCodeNonChiffre() << endl;
            cout << "La chaine chiffre : " << getCodeChiffre() << endl;
            return ;
        }
        else{
            if ( (getCodeNonChiffre()[i] >= 97) && (getCodeNonChiffre()[i] <= 122) ){
                tmpChar = tmp[i]-32;
                tmp[i]= tmpChar;
            }
        }
    }

    //pareil pour la clé
    for (unsigned int i=0; i < getCle().length(); i++){
        if (!estCharactereAutorise(getCle()[i])){
            setCodeChiffre("CHARACTERE NON AUTORISE");
            cout << "La chaine non chiffre : " << getCodeNonChiffre() << endl;
            cout << "La chaine chiffre : " << getCodeChiffre() << endl;
            return ;
        }
        else{
            if ( (getCle()[i] >= 97) && (getCle()[i] <= 122) ){
                tmpChar = tmpKey[i]-32;
                tmpKey[i]= tmpChar;
            }
        }
    }

    //On applique le chiffrement
    for (unsigned int i=0; i < getCodeNonChiffre().length(); i++)
    {

        if(tmpKey.length() == j){
            j=0;
        }
        if (tmp[i] == ' ' || tmp[i] == ' ' || tmp[i] == '\'' || tmp[i] == ',' || tmp[i] == '.') {}
        else if ((tmpKey[j]+tmp[i]-65) > 90 ){
            tmpChar = tmpKey[j] + tmp[i] - 26 - 65 ;
            tmp[i]=tmpChar;
        }
        else{
            tmpChar = tmp[i]+tmpKey[j]-65;
            tmp[i]= tmpChar;
        }
        j++;
    }
    setCodeChiffre(tmp);

    cout << "La chaine non chiffre : " << getCodeNonChiffre() << endl;
    cout << "La chaine chiffre : " << getCodeChiffre() << endl;
}

/**
*  Fonction de déchiffrage sur les caractères de l'alphabet
*
*   @param  string  : le texte à déchiffrer
*   @param  string     : la cle a appliquer au texte à déchiffrer
*   @return void
*
*/
void Vigenere::dechiffrage (string texteADechiffrer, string cleAUtiliser){
    char tmpChar;
    setCodeChiffre(texteADechiffrer);
    setCle(cleAUtiliser);
    string tmp= getCodeChiffre();
    string tmpKey= getCle();
    unsigned int j=0;

    //Ici on vérifie que le texte a chiffrer est bien compris entre A et Z. Le texte est ensuite mis en majuscule.
    for (unsigned int i=0; i < getCodeChiffre().length(); i++){
        if (tmp[i] == ' ' || tmp[i] == ' ' || tmp[i] == '\'' || tmp[i] == ',' || tmp[i] == '.') {}
        else if (!estCharactereAutorise(getCodeChiffre()[i])){
            setCodeChiffre("CHARACTERE NON AUTORISE");
            cout << "La chaine non chiffre : " << getCodeNonChiffre() << endl;
            cout << "La chaine chiffre : " << getCodeChiffre() << endl;
            return ;
        }
        else{
            if ( (getCodeChiffre()[i] >= 97) && (getCodeChiffre()[i] <= 122) ){
                tmpChar = tmp[i]-32;
                tmp[i]= tmpChar;
            }
        }
    }

    //pareil pour la clé
    for (unsigned int i=0; i < getCle().length(); i++){
        if (tmp[i] == ' ' || tmp[i] == ' ' || tmp[i] == '\'' || tmp[i] == ',' || tmp[i] == '.') {}
        else if (!estCharactereAutorise(getCle()[i])){
            setCodeChiffre("CHARACTERE NON AUTORISE");
            cout << "La chaine non chiffre : " << getCodeNonChiffre() << endl;
            cout << "La chaine chiffre : " << getCodeChiffre() << endl;
            return ;
        }
        else{
            if ( (getCle()[i] >= 97) && (getCle()[i] <= 122) ){
                tmpChar = tmpKey[i]-32;
                tmpKey[i]= tmpChar;
            }
        }

    }

    //On applique le dechiffrement
    for (unsigned int i=0; i < getCodeChiffre().length(); i++)
    {
        if(tmpKey.length() == j){
            j=0;
        }
        if (tmp[i] == ' ' || tmp[i] == ' ' || tmp[i] == '\'' || tmp[i] == ',' || tmp[i] == '.') {}
        else if ((tmp[i]-tmpKey[j]+65) < 65 ){
            tmpChar =  tmp[i] - tmpKey[j] + 26 + 65;
            tmp[i]=tmpChar;
        }
        else{
            tmpChar = tmp[i] - tmpKey[j] + 65;
            tmp[i]= tmpChar;
        }
        j++;
    }

    setCodeNonChiffre(tmp);
    cout << "La chaine non chiffre : " << getCodeNonChiffre() << endl;
    cout << "La chaine chiffre : " << getCodeChiffre() << endl;



}

/**
*  Fonction de cryptanalyse sur les caractères de l'alphabet
*
*   @param  string  : le texte à décrypter
*   @return void
*
*/

void Vigenere::cryptanalyse (string texteADecrypter){
    setCodeChiffre(texteADecrypter);
    unsigned int i,j,longueurCle=1,maxPgcdFreq=0,indiceSousTexte=0,max=0,maxIndice;
    string trigramme1,trigramme2,cleRetrouve="", tmp= getCodeChiffre();
    vector<int> distance,pgcdresult;
    vector<vector< int > > pgcdfreq;
    bool PGCDexist=false;
    int frequence[26]={0};

    ///Ici on vérifie que le texte a chiffrer est bien compris entre A et Z. Le texte est ensuite mis en majuscule.

    for (unsigned int i=0; i < getCodeChiffre().length(); i++){
        if (tmp[i] == ' ' || tmp[i] == ' ' || tmp[i] == '\'' || tmp[i] == ',' || tmp[i] == '.'){}
        else if (!estCharactereAutorise(getCodeChiffre()[i])){
            setCodeChiffre("CHARACTERE NON AUTORISE");
            cout << "La chaine non chiffre : " << getCodeNonChiffre() << endl;
            cout << "La chaine chiffre : " << getCodeChiffre() << endl;
            return ;
        }
        else{
            if ( (getCodeChiffre()[i] >= 97) && (getCodeChiffre()[i] <= 122) ){
                tmp[i]= toupper(tmp[i]);
            }
        }
    }
    removeAllWhite(tmp);
    setCodeChiffre(tmp);

    ///trouver longueur de la clé - test de babbage/kasiski
    //comparaison de chaque 3 trigamme 2 à 2
    cout << getCodeChiffre() << endl;
    for(i=0; i<getCodeChiffre().size(); i++){
        trigramme1 = getCodeChiffre() .substr(i,3);
        for(j=2; i+j<getCodeChiffre() .size(); j++){
            trigramme2 = getCodeChiffre() .substr(i+j,3);
            if(trigramme1.compare(trigramme2) == 0){
               //stockage de la distance si 2 trigammes sont identique
                distance.push_back(j);
            }
        }
    }

    // PGCD des distances 2 à 2 et stockage des résultats dans pgcsresult
    for(i=0;i<distance.size();i++){
        for(j=i+1;j<distance.size();j++){
            pgcdresult.push_back(pgcd(distance.at(i),distance.at(j)));
        }
    }
    distance.clear();

    //recherche des fréquences des PGCD en parcourant pgcdresult
    for(i=0;i<pgcdresult.size();i++){
        PGCDexist=false;
        for(j=0;j<pgcdfreq.size();j++){
            if(pgcdresult.at(i) == pgcdfreq[j][0]){
                pgcdfreq[j][1]++;
                PGCDexist=true;
            }
        }

        if(PGCDexist==false){
            //ajout du nouvel element
            pgcdfreq.resize(j+1);
            for (unsigned int k = 0; k < j+1; ++k)
                pgcdfreq[k].resize(2);

            pgcdfreq[j][0]=pgcdresult.at(i);
            pgcdfreq[j][1]=1;
        }
    }
    pgcdresult.clear();


    // Récupération de la valeur maximale de frequence de PGCD pour avoir la longueur de la clé
  for(i=0;i<pgcdfreq.size();++i){
    if(pgcdfreq[i][1] > maxPgcdFreq){
        maxPgcdFreq=pgcdfreq[i][1];
        longueurCle=pgcdfreq[i][0];
    }
    /*    for(j=0;j<pgcdfreq[i].size();++j){
            cout << pgcdfreq[i][j] << " , ";
        }
        cout << endl;*/
  }
  pgcdfreq.clear();

   cout << "La longueur de la cle est "<< longueurCle << endl;


    ///recherche de la clé (analyse de frequence sur les sous textes decoupé avec décalage selon la longueur de la clé)
    string sousTexte[longueurCle];

    for (i=0; i < 26;i++){
        frequence[i]=0;
    }

    //partage du texte en sous textes
    for(i=0;i<getCodeChiffre().size();i++){
        if(indiceSousTexte==longueurCle){
            indiceSousTexte=0;
        }
        sousTexte[indiceSousTexte].push_back(getCodeChiffre()[i]);
        indiceSousTexte++;
    }

    //faire cryptanalyse comme dans le chiffre de césar dans chacun des sous textes
    for(i=0;i<longueurCle;i++){
        //On remplis le tableau de frequence d'apparition des lettres
        for (j=0; j < sousTexte[i].length();j++){
            if (sousTexte[i][j]>=65 && sousTexte[i][j]<=90)
                frequence[getIndiceTableau(sousTexte[i][j])]+=1;
        }
        //Pour afficher frequence[]
        //     for (unsigned int i=0; i < 26;i++){
        //         cout << frequence[i]<<endl;
        //     }

        //On détermine la lettre qui a le plus d'apparition
        for (j=0; j < 26;j++){
            if (frequence[j] > max){
                max = frequence[j];
                maxIndice=j;
            }
        }
        //  Code debug:
        // cout << "max    " << max <<"  maxIndice   " << maxIndice << "    Indice Tableau    " << getIndiceTableau('H') << endl;

        //ajout de la lettre dans la clé
        if (maxIndice >= 4)
            cleRetrouve.push_back(maxIndice-4+65);
        else
            cleRetrouve.push_back(4-maxIndice+65);

    }
    cout << cleRetrouve << endl;

    ///dechiffrement
    dechiffrage(getCodeChiffre(),cleRetrouve);

}
