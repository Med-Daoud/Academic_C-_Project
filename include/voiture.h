#pragma once
#include "automobile.h"
#include<iostream>
#include<string>
#include<vector>
#include"personne.h"
#include"client.h"
using namespace std;
class voiture :
    public automobile
{
protected:
    string nbporte;
    string nb_vitesse;
    string nbcylindre;
    vector<Client*>liste_proprietaire;
public:
    voiture(const string& marque = " ", const string& model = " ", const string& matricule = " ", float kilometrage = 0.0, const string& annee_fab = " ", const string& nbporte = " ", const string& nb_vitesse = " ", const string& nbcylindre = " ")
        : automobile(marque, model, matricule, kilometrage, annee_fab), nbporte(nbporte), nb_vitesse(nb_vitesse), nbcylindre(nbcylindre), liste_proprietaire(liste_proprietaire)
    {
    }

    string getNbPorte() { return nbporte; }
    string getNb_vitesse() { return nb_vitesse; }
    string getNbcylindre() { return nbcylindre; }
    float cout_entretien_annuel() override {
        return 300.0f + 0.05f * kilometrage;
    };
    voiture(const voiture& v) :automobile(v)
    {
        nbcylindre = v.nbcylindre;
        nb_vitesse = v.nb_vitesse;
        nbporte = v.nbporte;
        for (int i = 0; i < liste_proprietaire.size(); i++)
            liste_proprietaire.push_back(new Client(*(v.liste_proprietaire[i])));
    }
    void afficher_information() override;
    void ajouter_proprietaire(Client);
    void afficher_proprietaires();
    void afficher_liste_reparation();
    void get_nbporte();
    void set_nbporte(int);
    ~voiture() {
        for (int i = 0; i < liste_proprietaire.size(); i++)
            delete liste_proprietaire[i];
        liste_proprietaire.clear();
    }
    void saisir();
    friend ostream& operator << (ostream&, voiture&);
    friend istream& operator >> (istream&, voiture&);
    voiture& operator=(const voiture&);


};
