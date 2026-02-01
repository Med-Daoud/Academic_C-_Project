#pragma once
#include"voiture.h"
#include "voiture_electrique.h"
#include"voiture_essence.h"
template <typename T>
class voiture_hybride : public voiture_electrique<T>, public voiture_essence<T> {
private:

public:
    voiture_hybride(const string& marque = " ", const string& model = " ", const string& matricule = " ", float kilometrage = 0.0,
        const string& annee_fab = " ", int nbporte = 0, int nbcylindre = 0,
        T capaciteReservoir = 0, float consommation = 0.0, T Autonomie_batterie = 0, float Temps_recharge = 0.0)
        : voiture(marque, model, matricule, kilometrage, annee_fab, nbporte, nbcylindre),
        voiture_electrique<T>(marque, model, matricule, kilometrage, annee_fab, nbporte, nbcylindre, Autonomie_batterie, Temps_recharge),
        voiture_essence<T>(marque, model, matricule, kilometrage, annee_fab, nbporte, nbcylindre, capaciteReservoir, consommation)
         {}


    template <typename U>
    friend ostream& operator<<(ostream& out, voiture_hybride<U>& vh);

    template <typename U>
    friend istream& operator>>(istream& in, voiture_hybride<U>& vh);
};

template <typename T>
ostream& operator<<(ostream& out, voiture_hybride<T>& vh) {
    vh.voiture::afficher_information();
    out << "Autonomie batterie : " << vh.Autonomie_batterie << "\n";
    out << "Temps de recharge : " << vh.Temps_recharge << "\n";
    out << "Capacité réservoir : " << vh.capaciteReservoir << "\n";
    out << "Consommation : " << vh.consommation << "\n";
    return out;
}

template <typename T>
istream& operator>>(istream& in, voiture_hybride<T>& vh) {
    cout << "Capacité du réservoir : ";
    in >> vh.capaciteReservoir;
    cout << "Consommation : ";
    in >> vh.consommation;
    cout << "Autonomie batterie : ";
    in >> vh.Autonomie_batterie;
    cout << "Temps recharge : ";
    in >> vh.Temps_recharge;
    return in;
}
