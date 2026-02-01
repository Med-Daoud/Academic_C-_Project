#pragma once
#include "automobile.h"
class moto :
    public automobile
{
    int cylindre;
    string type_moto;

public:

    moto(const string& marque = " ", const string& model = " ", const string& matricule = " ", float kilometrage = 0.0, const string& annee_fab = " ",int cylindre=0, const string& type_moto=" ")
        : automobile(marque, model, matricule, kilometrage, annee_fab), cylindre(cylindre), type_moto(type_moto)
    {
    }
     friend ostream& operator << (ostream&, moto&);
 friend istream& operator >> (istream&, moto&);
    float cout_entretien_annuel()  override {
        return 200.0f + 0.03f * kilometrage;
    }
    void afficher_information() override;
    void setCylindree(int cyl) {
        cylindre = cyl;
    }
    int getCylindree() const {
        return cylindre;
    }
    void setTypeMoto(std::string type) {
        type_moto = type;
    }
    string getTypeMoto() const {
        return type_moto;
    }
    int getCylindre() {
        return cylindre;
    };
};
