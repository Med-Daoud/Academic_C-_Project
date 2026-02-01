#include "Facture.h"
#include<iostream>
using namespace std;
#include "Facture.h"
Facture::Facture()
{
    prix = 0;
    TVApourcentage = 0;
    RemisePourcentage = 0;
}
Facture::~Facture()
{

}
void Facture::saisir()
{    cout<<"le prix est ="<<endl;
    cin >> prix ;
    cout<<"le TVA est ="<<endl;
    cin>> TVApourcentage ;
    cout<<"le remise est ="<<endl;
    cin>> RemisePourcentage;
}
float Facture::calcule()
{
    return (prix + prix * (TVApourcentage / 100.0)) * (1 - RemisePourcentage / 100.0);
}
void Facture::affiche()
{
    float f = calcule();
    cout << f;
}
ostream& operator <<(ostream& out, Facture& F)
{
    cout<<"le prix est ="<<endl;
    out << F.prix;
    cout<<"le remise est ="<<endl;
    out << F.RemisePourcentage;
    cout<<"le TVA est ="<<endl;
    out << F.TVApourcentage;
    return out;
}
istream& operator>>(istream& in, Facture& F)
{
     cout << "Entrer les parametres de la facture :" << endl;

    cout << "Le prix est = ";
    in >> F.prix;
    while (F.prix < 0) {
        cout << "Erreur: prix negatif !" << endl;
        cout << "Le prix est = ";
        in >> F.prix;
    }

    cout << "La remise (%) = ";
    in >> F.RemisePourcentage;


    cout << "La TVA (%) = ";
    in >> F.TVApourcentage;

    return in;;
}
