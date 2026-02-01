#pragma once
#include<iostream>
using namespace std;
class Facture
{
protected:
    float prix;
    int TVApourcentage;
    int RemisePourcentage;
public:
    Facture();
    ~Facture();
    void saisir();
    float calcule();
    void affiche();
    friend ostream& operator << (ostream&, Facture&);
    friend istream& operator >> (istream&, Facture&);

};
