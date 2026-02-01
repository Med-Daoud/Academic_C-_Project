#pragma once
#include "automobile.h"
class camion :
    public automobile
{
    float capacite_charge;
    int nb_boitevitesse;
public:



    camion(const string& marque = " ", const string& model = " ", const string& matricule = " ", float kilometrage = 0.0, const string& annee_fab = " ",float capacite_charge=0.0, int nb_boitevitesse=0)
        : automobile(marque, model, matricule, kilometrage, annee_fab),capacite_charge(capacite_charge), nb_boitevitesse(nb_boitevitesse)
    {
    }
    void afficher_information() override;
    void setCapaciteCharge(float charge) {
        capacite_charge = charge;
    }
    float getCapaciteCharge() const {
        return capacite_charge;
    }
    void set_nbboitevitesse(int a) {
        nb_boitevitesse = a;
    }
    int get_nbboitevitesse() {
        return nb_boitevitesse;
    }
    friend ostream& operator << (ostream&, camion&);
    friend istream& operator >> (istream&, camion&);
    float cout_entretien_annuel()  override {
        return (500.0f + 0.1f * kilometrage);
    }
};
