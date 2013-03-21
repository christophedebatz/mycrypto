#include "MyCrypto.h"


MyCrypto::MyCrypto()
{
    isEnigmaPara=0;

    // Titre de la fenetre
    setWindowTitle("My Crypto v1.0");
    setFixedSize(500, 550);
    setWindowIcon(QIcon(QCoreApplication::applicationDirPath()+"/resources/logo.png"));
        /*
        Components
        */
        posLogo = new QLabel(this);
        algoLabel = new QLabel("Algorithme :");
        comboBoxAlgo = new QComboBox();
         // Gestion combobox des algorithmes
        //comboBoxAlgo->addItem("", NULL);
        comboBoxAlgo->addItem("C�sar", NULL);
        comboBoxAlgo->addItem("Scytale", NULL);
        comboBoxAlgo->addItem("Vigen�re", NULL);
        comboBoxAlgo->addItem("Enigma", NULL);
         // Chargement du logo
        posLogo->setPixmap(QPixmap("resources/logo.png"));
        posLogo->setAlignment(Qt::AlignHCenter);

        layout = new QGridLayout;
        layout->addWidget(posLogo, 0, 0, 1, 3);
        layout->addWidget(algoLabel, 1, 0);
        layout->addWidget(comboBoxAlgo, 1, 1);

        //QLabel *keyLabel = new QLabel("");
        textToTreatCryptage = new QTextEdit();
        textToTreatDecryptage = new QTextEdit();
        textToTreatDescription = new QLabel("Le code de C�sar est la m�thode de cryptographie la plus ancienne commun�ment admise par\nl'histoire. Il consiste en une substitution mono-alphab�tique, o� la substitution est d�finie\npar un d�calage de lettres.");
        textToTreatParametre1 = new QSpinBox ();
        encryptButton = new QPushButton("Chiffrer");
        decryptButton = new QPushButton("D�chiffrer");
        cryptaButton = new QPushButton("Cryptanalyse");

        titleTextCryptage = new QGroupBox("Texte � chiffrer :", this);
        titleTextDecryptage = new QGroupBox("Texte � d�chiffrer :", this);
        titleTextDescription = new QGroupBox("Description :", this);
        titleTextParametre = new QGroupBox("Cl� :", this);

        QVBoxLayout *vboxDescription = new QVBoxLayout;
        vboxDescription->addWidget(textToTreatDescription);
        titleTextDescription->setLayout(vboxDescription);

        QVBoxLayout *vboxParametre = new QVBoxLayout;
        vboxParametre->addWidget(textToTreatParametre1);
        titleTextParametre->setLayout(vboxParametre);

        QVBoxLayout *vboxCryptage = new QVBoxLayout;
        vboxCryptage->addWidget(textToTreatCryptage);
        titleTextCryptage->setLayout(vboxCryptage);

        QVBoxLayout *vboxDecryptage = new QVBoxLayout;
        vboxDecryptage->addWidget(textToTreatDecryptage);
        titleTextDecryptage->setLayout(vboxDecryptage);

        layout->addWidget(titleTextDescription, 2, 0, 1, 3);
        layout->addWidget(titleTextParametre, 3, 0, 1, 0);
        layout->addWidget(titleTextCryptage, 4, 0, 1, 3);
        layout->addWidget(titleTextDecryptage, 5, 0, 1, 3);
        layout->addWidget(encryptButton, 6, 0);
        layout->addWidget(decryptButton, 6, 1);
        layout->addWidget(cryptaButton, 6, 2);
        setLayout(layout);
    connect(comboBoxAlgo, SIGNAL(activated(QString)), this, SLOT(generationInterface()));
    connect(encryptButton, SIGNAL(clicked()), this, SLOT(AppelCryptage()));
    connect(decryptButton, SIGNAL(clicked()), this, SLOT(AppelDecryptage()));
    connect(cryptaButton, SIGNAL(clicked()), this, SLOT(AppelCryptanalyse()));
    //textToTreatCryptage->toPlainText;

}

MyCrypto::~MyCrypto(){}

 void MyCrypto::generationInterface(){
    if (comboBoxAlgo->currentText() == "Enigma"){
        delete titleTextParametre;
        delete textToTreatDescription;
        delete titleTextDescription;

        textToTreatParametre1 = new QSpinBox ();
        textToTreatParametre2 = new QSpinBox ();
        textToTreatParametre3 = new QSpinBox ();
        titleTextParametre = new QGroupBox("Cl� :", this);
        titleTextDescription = new QGroupBox("Description :", this);
        textToTreatDescription = new QLabel("Enigma est la machine � chiffrer et d�chiffrer qu'utilis�rent les arm�es allemandes du d�but des\nann�es trente jusqu'� la fin de Seconde Guerre Mondiale. Elle automatise le chiffrement\npar substitution.");

        QVBoxLayout *vboxParametre = new QVBoxLayout;
        vboxParametre->addWidget(textToTreatParametre1);
        vboxParametre->addWidget(textToTreatParametre2);
        vboxParametre->addWidget(textToTreatParametre3);
        titleTextParametre->setLayout(vboxParametre);

        QVBoxLayout *vboxDescription = new QVBoxLayout;
        vboxDescription->addWidget(textToTreatDescription);
        titleTextDescription->setLayout(vboxDescription);

        layout->addWidget(titleTextDescription, 2, 0, 1, 3);
        layout->addWidget(titleTextParametre, 3, 0, 1, 0);

        setLayout(layout);
        isEnigmaPara=1;
    }
    else if (comboBoxAlgo->currentText() == "C�sar" || comboBoxAlgo->currentText() == "Scytale"){
        if (isEnigmaPara){
        delete textToTreatParametre2;
        delete textToTreatParametre3;
        isEnigmaPara=0;
        }
        delete titleTextParametre;
        delete textToTreatDescription;
        delete titleTextDescription;

        if (comboBoxAlgo->currentText() == "C�sar"){
            textToTreatDescription = new QLabel("Le code de C�sar est la m�thode de cryptographie la plus ancienne commun�ment admise par\nl'histoire. Il consiste en une substitution mono-alphab�tique, o� la substitution est d�finie\npar un d�calage de lettres.");
        }
        else{
            textToTreatDescription = new QLabel("Chez les Spartiates, la scytale �tait un b�ton de bois utilis� pour lire ou �crire une d�p�che\nchiffr�e.Consid�r�e comme le plus ancien dispositif de cryptographie militaire connue, elle\npermettait l'inscription d'un message chiffr� sur une fine lani�re de cuir ou de parchemin que\nle messager pouvait porter � sa ceinture.");
        }

        textToTreatParametre1 = new QSpinBox (); //Pour vigenere
        titleTextParametre = new QGroupBox("Cl� :", this);
        titleTextDescription = new QGroupBox("Description :", this);

        QVBoxLayout *vboxParametre = new QVBoxLayout;
        vboxParametre->addWidget(textToTreatParametre1);
        titleTextParametre->setLayout(vboxParametre);

        QVBoxLayout *vboxDescription = new QVBoxLayout;
        vboxDescription->addWidget(textToTreatDescription);
        titleTextDescription->setLayout(vboxDescription);

        layout->addWidget(titleTextParametre, 3, 0, 1, 0);
        layout->addWidget(titleTextDescription, 2, 0, 1, 3);

        setLayout(layout);

    }
    else if (comboBoxAlgo->currentText() == "Vigen�re"){
        if (isEnigmaPara){
        delete textToTreatParametre2;
        delete textToTreatParametre3;
        isEnigmaPara=0;
        }
        delete titleTextParametre;
        delete textToTreatDescription;
        delete titleTextDescription;
        textToTreatParametreVigenere = new QLineEdit(); //Pour vigenere
        titleTextParametre = new QGroupBox("Cl� :", this);
        titleTextDescription = new QGroupBox("Description :", this);
        textToTreatDescription = new QLabel("Le chiffre de Vigen�re est une am�lioration d�cisive du chiffre de C�sar. Sa force r�side dans\nl'utilisation non pas d'un, mais de 26 alphabets d�cal�s pour chiffrer un message. On peut\nr�sumer ces d�calages avec un carr� de Vigen�re.");

        QVBoxLayout *vboxParametre = new QVBoxLayout;
        vboxParametre->addWidget(textToTreatParametreVigenere);
        titleTextParametre->setLayout(vboxParametre);

        QVBoxLayout *vboxDescription = new QVBoxLayout;
        vboxDescription->addWidget(textToTreatDescription);
        titleTextDescription->setLayout(vboxDescription);

        layout->addWidget(titleTextParametre, 3, 0, 1, 0);
        layout->addWidget(titleTextDescription, 2, 0, 1, 3);
        setLayout(layout);
    }
 }

void MyCrypto::AppelCryptage(){
    if (comboBoxAlgo->currentText() == "C�sar"){
        CodeCesar cesar;
        cesar.chiffrage(textToTreatCryptage->toPlainText().toStdString().c_str(), textToTreatParametre1->value());
        textToTreatDecryptage->setText(QString::fromStdString(cesar.getCodeChiffre()) );
    }
    else if (comboBoxAlgo->currentText() == "Scytale"){
        Scytale sc;
        sc.chiffrage(textToTreatCryptage->toPlainText().toStdString().c_str(), textToTreatParametre1->value());
        textToTreatDecryptage->setText(QString::fromStdString(sc.getCodeChiffre()) );
    }
    else if (comboBoxAlgo->currentText() == "Vigen�re"){
        Vigenere vg;
        vg.chiffrage(textToTreatCryptage->toPlainText().toStdString().c_str(), textToTreatParametreVigenere->displayText().toStdString().c_str());
        textToTreatDecryptage->setText(QString::fromStdString(vg.getCodeChiffre()) );
    }
    else if (comboBoxAlgo->currentText() == "Enigma"){
        Enigma enigma;
        enigma.chiffrage(textToTreatCryptage->toPlainText().toStdString().c_str(), textToTreatParametre1->value(),textToTreatParametre2->value(),textToTreatParametre3->value());
        textToTreatDecryptage->setText(QString::fromStdString(enigma.getCodeChiffre()) );
    }

}
void MyCrypto::AppelDecryptage(){
     if (comboBoxAlgo->currentText() == "C�sar"){
        CodeCesar cesar;
        cesar.dechiffrage(textToTreatDecryptage->toPlainText().toStdString().c_str(), textToTreatParametre1->value());
        textToTreatCryptage->setText(QString::fromStdString(cesar.getCodeNonChiffre()) );
    }
    else if (comboBoxAlgo->currentText() == "Scytale"){
        Scytale sc;
        sc.dechiffrage(textToTreatDecryptage->toPlainText().toStdString().c_str(), textToTreatParametre1->value());
        textToTreatCryptage->setText(QString::fromStdString(sc.getCodeNonChiffre()) );
    }
    else if (comboBoxAlgo->currentText() == "Vigen�re"){
        Vigenere vg;
        vg.dechiffrage(textToTreatDecryptage->toPlainText().toStdString().c_str(), textToTreatParametreVigenere->displayText().toStdString().c_str());
        textToTreatCryptage->setText(QString::fromStdString(vg.getCodeNonChiffre()) );
    }
    else if (comboBoxAlgo->currentText() == "Enigma"){
        Enigma enigma;
        enigma.dechiffrage(textToTreatDecryptage->toPlainText().toStdString().c_str(), textToTreatParametre1->value(),textToTreatParametre2->value(),textToTreatParametre3->value());
        textToTreatCryptage->setText(QString::fromStdString(enigma.getCodeNonChiffre()) );
    }
}
void MyCrypto::AppelCryptanalyse(){
    if (comboBoxAlgo->currentText() == "C�sar"){
        CodeCesar cesar;
        cesar.cryptanalyse(textToTreatDecryptage->toPlainText().toStdString().c_str());
        textToTreatCryptage->setText(QString::fromStdString(cesar.getCodeNonChiffre()) );
    }
    else if (comboBoxAlgo->currentText() == "Scytale"){
        Scytale sc;
        sc.cryptanalyse(textToTreatDecryptage->toPlainText().toStdString().c_str());
        textToTreatCryptage->setText(QString::fromStdString(sc.getCodeNonChiffre()) );
    }
    else if (comboBoxAlgo->currentText() == "Vigen�re"){
        Vigenere vg;
        vg.cryptanalyse(textToTreatDecryptage->toPlainText().toStdString().c_str());
        textToTreatCryptage->setText(QString::fromStdString(vg.getCodeNonChiffre()) );
    }
    else if (comboBoxAlgo->currentText() == "Enigma"){
//        Enigma enigma;
//        enigma.cryptanalyse(textToTreatDecryptage->toPlainText().toStdString().c_str());
//        textToTreatCryptage->setText(QString::fromStdString(enigma.getCodeNonChiffre()) );
    }
}
