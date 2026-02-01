#pragma once
#include "voiture.h"
template<typename T>
class voiture_essence :
    virtual public voiture
{
protected:
    T capaciteReservoir;
    float consommation;
public:
    voiture_essence(const string& marque = " ", const string& model = " ", const string& matricule = " ", float kilometrage = 0.0,
        const string& annee_fab = " ", const string& nbporte =" ", const string& nb_vitesse =" ", const string& nbcylindre = " ", T capaciteReservoir = 0, float consommation = 0)
        :voiture(marque, model, matricule, kilometrage, annee_fab, nbporte,nb_vitesse, nbcylindre), capaciteReservoir(capaciteReservoir), consommation(consommation)
    {

    }
    void afficher_information() override
    {
        cout << "======voiture a essence======" << endl;
        voiture::afficher_information();
        cout << "la capacite du reservoir est :" << capaciteReservoir << endl;
        cout << "la consommation par kilometre est : " << consommation << endl;

    };
    float get_CapaciteReservoir() {
        return capaciteReservoir;
    }
    float get_Consommation() {
        return consommation;
    }
    template<typename T>
    friend ostream& operator << (ostream& out, voiture_essence<T>& VS)
    {
        voiture* V = &VS;
        out << *V;
        out << "capaciteReservoir : " << VS.capaciteReservoir << endl;
        out << "consommation : " << VS.consommation << endl;
        return out;
    };
    template<typename T>
    friend istream& operator >> (istream& in, voiture_essence<T>& VS)
    {
        voiture* V = &VS;
        in >> *V;
        cout << "donner la capacite du reservoir : ";
        in >> VS.capaciteReservoir;
        cout << "\n donner la consommation par km : ";
        in >> VS.consommation;
        return in;
    };


};
