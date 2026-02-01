#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Date.h"
#include"Facture.h"
#include"automobile.h"
using namespace std;
#include "Personne.h"
class Client :
    virtual public Personne
{
protected:
    vector<Facture*>listFacture;
public:
    Client(const int& CIN = 123456, const string& nom = " ", const string& prenom = " ", const string& dateNaissance=" ")
        : Personne(CIN,nom,prenom,dateNaissance) {}
        Client(const Client&);
    void saisie();
    void afficherInfo() override;
    void ajouterFacture(Facture);
    void supprimerFacture(int);
    friend ostream& operator << (ostream&,Client&);
    friend istream& operator >> (istream&, Client&);
    Client& operator =(const Client&);
    Client& operator+(Facture& );
};
