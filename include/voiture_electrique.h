#pragma once
#include "voiture.h"
template<typename T>
class voiture_electrique :
    public voiture
{
protected:
    T Autonomie_batterie;
    float Temps_recharge;
public:
    voiture_electrique(const string& marque = " ", const string& model = " ", const string& matricule = " ", float kilometrage = 0.0,
        const string& annee_fab = " ",const string& nbporte =" ", const string& nb_vitesse = " ", const string& nbcylindre =" ", T Autonomie_batterie = 0.0, float Temps_recharge = 0.0)
        :voiture(marque, model, matricule, kilometrage, annee_fab, nbporte,nb_vitesse, nbcylindre), Autonomie_batterie(Autonomie_batterie), Temps_recharge(Temps_recharge)
    {

    }
    void afficher_information() override
    {
        cout << "=======voiture electrique======" << endl;
        voiture::afficher_information();
        cout << endl;
        cout << "l'autonomie de la batterie est : " << Autonomie_batterie << endl;
        cout << "le temps de recharge de la batterie est : " << Temps_recharge << endl;

    };

    float get_autonomie() {
        return Autonomie_batterie;
    };
    float get_tempsrech() {
        return Temps_recharge;

    };
    float cout_entretien_annuel()  override {
        return 250.0f + 0.02f * kilometrage;
    };
    template<typename T>
    friend ostream& operator << (ostream& out, voiture_electrique& VE)
    {
        voiture* V = &VE;
        out << *V;
        out << "Autonomie_batterie : " << VE.Autonomie_batterie << endl;
        out << "Temps_recharge : " << VE.Temps_recharge << endl;
        return out;
    };
    template<typename T>
    friend istream& operator >> (istream& in, voiture_electrique& VE)
    {
        voiture* V = &VE;
        in >> *V;
        cout << "donner l'autonomie de la batterie : ";
        in >> VE.Autonomie_batterie;
        cout << "\n donner le temps de recharge : ";
        in >> VE.Temps_recharge;
        return in;
    };

};
