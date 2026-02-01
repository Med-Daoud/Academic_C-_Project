#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Date.h"
#include"automobile.h"
using namespace std;
#include<iostream>

class Personne
{
protected:
    int CIN;
    string nom;
    string prenom;
    string dateNaissance;
    vector<automobile*> listVehecule;
public:
    Personne(int C = 0, const string& nom = " ", const string& prenom = " "
             , const string dateNaissance=" ") :
        CIN(C), nom(nom), prenom(prenom),dateNaissance(dateNaissance) {
    }
    Personne(const Personne&);
    ~Personne() {
        for (int i = 0; i < listVehecule.size(); i++)
            delete listVehecule[i];
        listVehecule.clear();
    }
    void saisie();

    virtual void afficherInfo() = 0;
    void ajouterVehicule(automobile*);
    void supprimerVehicule(int);
    friend ostream& operator << (ostream&, Personne&);
    friend istream& operator >> (istream&, Personne&);
     Personne& operator+(automobile* vehicule) {
        this->ajouterVehicule(vehicule);
        return *this;}
};
