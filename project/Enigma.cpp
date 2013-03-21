#include "Enigma.h"
#include <iostream>

using namespace std;

/**
*  Constructeur
*
*   @param  void
*   @return void
*
*/
Enigma::Enigma ()
{
    rotor0=new char[26];
    rotor1=new char[26];
    rotor2=new char[26];

    rotorDecalage0=new int[26];
    rotorDecalage1=new int[26];
    rotorDecalage2=new int[26];

    rotorInverse0=new char[26];
    rotorInverse1=new char[26];
    rotorInverse2=new char[26];

    rotorInverseDecalage0=new int[26];
    rotorInverseDecalage1=new int[26];
    rotorInverseDecalage2=new int[26];
    /**
    *
    *   //http://en.wikipedia.org/wiki/Enigma_rotor_details
    *
    *   Rotor #     ABCDEFGHIJKLMNOPQRSTUVWXYZ 	        Date            Introduced  	Model Name & Number
    *   IC 	        DMTWS ILRUY QNKFE JCAZB PGXOH V 	1924 	        Commercial      Enigma A, B
    *   IIC 	    HQZGP JTMOB LNCIF DYAWV EUSRK X 	1924 	        Commercial      Enigma A, B
    *   IIIC 	    UQNTL SZFMR EHDPX KIBVY GJCWO A 	1924 	        Commercial      Enigma A, B
    *
    *
    */
//Premier Rotor IC
    rotor0[0]='D';
    rotor0[1]='M';
    rotor0[2]='T';
    rotor0[3]='W';
    rotor0[4]='S';
    rotor0[5]='I';
    rotor0[6]='L';
    rotor0[7]='R';
    rotor0[8]='U';
    rotor0[9]='Y';

    rotor0[10]='Q';
    rotor0[11]='N';
    rotor0[12]='K';
    rotor0[13]='F';
    rotor0[14]='E';
    rotor0[15]='J';
    rotor0[16]='C';
    rotor0[17]='A';
    rotor0[18]='Z';
    rotor0[19]='B';

    rotor0[20]='P';
    rotor0[21]='G';
    rotor0[22]='X';
    rotor0[23]='O';
    rotor0[24]='H';
    rotor0[25]='V';

//Deuxième Rotor IIC
    rotor1[0]='H';
    rotor1[1]='Q';
    rotor1[2]='Z';
    rotor1[3]='G';
    rotor1[4]='P';
    rotor1[5]='J';
    rotor1[6]='T';
    rotor1[7]='M';
    rotor1[8]='O';
    rotor1[9]='B';

    rotor1[10]='L';
    rotor1[11]='N';
    rotor1[12]='C';
    rotor1[13]='I';
    rotor1[14]='F';
    rotor1[15]='D';
    rotor1[16]='Y';
    rotor1[17]='A';
    rotor1[18]='W';
    rotor1[19]='V';

    rotor1[20]='E';
    rotor1[21]='U';
    rotor1[22]='S';
    rotor1[23]='R';
    rotor1[24]='K';
    rotor1[25]='X';


//Troisième Rotor IIIC  UQNTL SZFMR EHDPX KIBVY GJCWO A
    rotor2[0]='U';
    rotor2[1]='Q';
    rotor2[2]='N';
    rotor2[3]='T';
    rotor2[4]='L';
    rotor2[5]='S';
    rotor2[6]='Z';
    rotor2[7]='F';
    rotor2[8]='M';
    rotor2[9]='R';

    rotor2[10]='E';
    rotor2[11]='H';
    rotor2[12]='D';
    rotor2[13]='P';
    rotor2[14]='X';
    rotor2[15]='K';
    rotor2[16]='I';
    rotor2[17]='B';
    rotor2[18]='V';
    rotor2[19]='Y';

    rotor2[20]='G';
    rotor2[21]='J';
    rotor2[22]='C';
    rotor2[23]='W';
    rotor2[24]='O';
    rotor2[25]='A';
//Initialisation des rotors inversés
    for (int i =0; i < 26; i++)
        rotorInverse0[getIndiceTableau(rotor0[i])]=i+65;
    for (int i =0; i < 26; i++)
        rotorInverse1[getIndiceTableau(rotor1[i])]=i+65;
    for (int i =0; i < 26; i++)
        rotorInverse2[getIndiceTableau(rotor2[i])]=i+65;

    for (int i =0; i < 26; i++)
        rotorDecalage0[i] = getIndiceTableau(rotor0[i]) - i;
    for (int i =0; i < 26; i++)
        rotorDecalage1[i] = getIndiceTableau(rotor1[i]) - i;
    for (int i =0; i < 26; i++)
        rotorDecalage2[i] = getIndiceTableau(rotor2[i]) - i;

    for (int i =0; i < 26; i++)
        rotorInverseDecalage0[i] = getIndiceTableau(rotorInverse0[i]) - i;
    for (int i =0; i < 26; i++)
        rotorInverseDecalage1[i] = getIndiceTableau(rotorInverse1[i]) - i;
    for (int i =0; i < 26; i++)
        rotorInverseDecalage2[i] = getIndiceTableau(rotorInverse2[i]) - i;



//Affichage
//    for (int i =0;i < 26;i++)
//        cout << i<< "  " << rotorDecalage0[i] << endl;
//    for (int i =0;i < 26;i++)
//        cout << rotorInverse0[i] << endl;
//    for (int i =0;i < 26;i++)
//        cout << rotorInverse2[i] << endl;
}
/**
*  Destructeur
*
*   @param  void
*   @return void
*
*/
Enigma::~Enigma ()
{
    delete[] rotor0;
    delete[] rotor1;
    delete[] rotor2;
    delete[] rotorInverse0;
    delete[] rotorInverse1;
    delete[] rotorInverse2;
    delete[] rotorDecalage0;
    delete[] rotorDecalage1;
    delete[] rotorDecalage2;
    delete[] rotorInverseDecalage0;
    delete[] rotorInverseDecalage1;
    delete[] rotorInverseDecalage2;

}

/**
*  Setter de la variable codeNonChiffre
*
*   @param  string  : variable qui contient la chaîne de caractère en claire
*   @return void
*
*/

void Enigma::setCodeNonChiffre (string _codeNonChiffre)
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
void Enigma::setCodeChiffre (string _codeChiffre)
{
    codeChiffre = _codeChiffre;
}

/**
*  Setter de la variable decalage0
*
*   @param  int  : variable qui contient le décalage du premier rotor
*   @return void
*
*/
void Enigma::setDecalage0 (int _decalage)
{
    decalage0 = _decalage;
}

/**
*  Setter de la variable decalage1
*
*   @param  int  : variable qui contient le décalage du deuxième rotor
*   @return void
*
*/
void Enigma::setDecalage1 (int _decalage)
{
    decalage1 = _decalage;
}

/**
*  Setter de la variable decalage2
*
*   @param  int  : variable qui contient le décalage du troisième rotor
*   @return void
*
*/
void Enigma::setDecalage2 (int _decalage)
{
    decalage2 = _decalage;
}

/**
*  Getter de la variable codeNonChiffre
*
*   @param  void
*   @return string : on renvoie la valeur de la variable codeNonChiffre
*
*/
string Enigma::getCodeNonChiffre ()
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
string Enigma::getCodeChiffre ()
{
    return codeChiffre;
}

/**
*  Getter de la variable decalage0
*
*   @param  void
*   @return int : on renvoie la valeur de la variable decalage0
*
*/
int Enigma::getDecalage0()
{
    return decalage0;
}

/**
*  Getter de la variable decalage1
*
*   @param  void
*   @return int : on renvoie la valeur de la variable decalage1
*
*/
int Enigma::getDecalage1()
{
    return decalage1;
}

/**
*  Getter de la variable decalage2
*
*   @param  void
*   @return int : on renvoie la valeur de la variable decalage2
*
*/
int Enigma::getDecalage2()
{
    return decalage2;
}

/**
*  Fonction de chiffrage enigma.
*
*   @param  string  : le texte à chiffrer
*   @param  int     : réglage du premier rotor
*   @param  int     : réglage du deuxième rotor
*   @param  int     : réglage du troisième rotor
*   @return void
*
*/
void Enigma::chiffrage (string texteAChiffrer, int _decalage0, int _decalage1, int _decalage2)
{
    char tmpChar;
    setCodeNonChiffre(texteAChiffrer);
    setDecalage0(_decalage0%26);
    setDecalage1(_decalage1%26);
    setDecalage2(_decalage2%26);
    string tmp= getCodeNonChiffre();

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
    setCodeNonChiffre(tmp);
    int dec;
    for (unsigned int i=0; i<getCodeNonChiffre().length(); i++)
    {
        if (tmp[i] != ' ')
        {
            //Gestion du decalage du premier rotor
            dec=rotorDecalage0[(getIndiceTableau(tmp[i])+getDecalage0())%26];
            if (tmp[i]+dec < 65)
                tmp[i] = 90-(64-(dec+tmp[i]));
            else if (tmp[i]+dec > 90)
                tmp[i] = 64+(dec+tmp[i]-90);
            else
                tmp[i] = dec+tmp[i];

            //Gestion du decalage du deuxième rotor
            dec=rotorDecalage1[(getIndiceTableau(tmp[i])+getDecalage1())%26];
            if (tmp[i]+dec < 65)
                tmp[i] = 90-(64-(dec+tmp[i]));
            else if (tmp[i]+dec > 90)
                tmp[i] = 64+(dec+tmp[i]-90);
            else
                tmp[i] = dec+tmp[i];

            //Gestion du decalage du troisième rotor
            dec=rotorDecalage2[(getIndiceTableau(tmp[i])+getDecalage2())%26];
            if (tmp[i]+dec < 65)
                tmp[i] = 90-(64-(dec+tmp[i]));
            else if (tmp[i]+dec > 90)
                tmp[i] = 64+(dec+tmp[i]-90);
            else
                tmp[i] = dec+tmp[i];

            setDecalage0(getDecalage0()+1);
            if( getDecalage0() > 25)
            {
                setDecalage1(getDecalage1()+1);
                setDecalage0(0);
            }
            if( getDecalage1() > 25)
            {
                setDecalage2(getDecalage2()+1);
                setDecalage1(0);
            }
            if( getDecalage2() > 25)
            {
                setDecalage2(0);
            }

        }
        else
            tmp[i] = ' ';
    }
    setCodeChiffre(tmp);
}

/**
*  Fonction de déchiffrage enigma
*
*   @param  string  : le texte à déchiffrer
*   @param  int     : réglage du premier rotor
*   @param  int     : réglage du deuxième rotor
*   @param  int     : réglage du troisième rotor
*   @return void
*
*/
void Enigma::dechiffrage (string texteADechiffrer, int _decalage0, int _decalage1, int _decalage2)
{

    char tmpChar;
    setCodeChiffre(texteADechiffrer);
    setDecalage0(_decalage0%26);
    setDecalage1(_decalage1%26);
    setDecalage2(_decalage2%26);
    string tmp= getCodeChiffre();

    //Ici on vérifie que le texte a chiffrer est bien compris entre A et Z. Le texte est ensuite mis en majuscule.
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
    setCodeChiffre(tmp);
    int dec;
    for (unsigned int i=0; i<getCodeChiffre().length(); i++)
    {
        if (tmp[i] != ' ')
        {
            dec=rotorInverseDecalage2[(getIndiceTableau(tmp[i])+getDecalage2())%26];
            if (tmp[i]+dec < 65)
                tmp[i] = 90-(64-(dec+tmp[i]));
            else if (tmp[i]+dec > 90)
                tmp[i] = 64+(dec+tmp[i]-90);
            else
                tmp[i] = dec+tmp[i];

            dec=rotorInverseDecalage1[(getIndiceTableau(tmp[i])+getDecalage1())%26];
            if (tmp[i]+dec < 65)
                tmp[i] = 90-(64-(dec+tmp[i]));
            else if (tmp[i]+dec > 90)
                tmp[i] = 64+(dec+tmp[i]-90);
            else
                tmp[i] = dec+tmp[i];

            dec=rotorInverseDecalage0[(getIndiceTableau(tmp[i])+getDecalage0())%26];
            if (tmp[i]+dec < 65)
                tmp[i] = 90-(64-(dec+tmp[i]));
            else if (tmp[i]+dec > 90)
                tmp[i] = 64+(dec+tmp[i]-90);
            else
                tmp[i] = dec+tmp[i];

            setDecalage0(getDecalage0()+1);
            if( getDecalage0() > 25)
            {
                setDecalage1(getDecalage1()+1);
                setDecalage0(0);
            }
            if( getDecalage1() > 25)
            {
                setDecalage2(getDecalage2()+1);
                setDecalage1(0);
            }
            if( getDecalage2() > 25)
            {
                setDecalage2(0);
            }

        }
        else
            tmp[i] = ' ';
    }
    setCodeNonChiffre(tmp);
}

void Enigma::cryptanalyse (string)
{

}
