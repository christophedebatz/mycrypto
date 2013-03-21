#ifndef MYCRYPTO
#define MYCRYPTO

#include "CodeCesar.h"
#include "Scytale.h"
#include "Vigenere.h"
#include "Enigma.h"

#include <QPushButton>
#include <QGridLayout>
#include <QApplication>
#include <QtGui>


class MyCrypto : public QWidget
{
    Q_OBJECT

    public:
        MyCrypto();
        ~MyCrypto();
    private slots:
        void generationInterface();
        void AppelCryptage();
        void AppelDecryptage();
        void AppelCryptanalyse();
    protected:
    int isEnigmaPara;
    QTextEdit   *textToTreatCryptage;
    QTextEdit   *textToTreatDecryptage;
    QLabel   *textToTreatDescription;
    QLineEdit   *textToTreatParametreVigenere;
    QSpinBox    *textToTreatParametre1; //Pour vigenere
    QSpinBox    *textToTreatParametre2;
    QSpinBox    *textToTreatParametre3;
    QPushButton *encryptButton;
    QPushButton *decryptButton;
    QPushButton *cryptaButton;
    QGridLayout *layout;
    QComboBox   *comboBoxAlgo;
    QLabel      *posLogo;
    QLabel      *algoLabel;
    QGroupBox   *titleTextCryptage;
    QGroupBox   *titleTextDecryptage;
    QGroupBox   *titleTextDescription;
    QGroupBox   *titleTextParametre;

};

#endif
