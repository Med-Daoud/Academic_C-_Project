#pragma once
#include"Client.h"
#include"mecanicien.h"
template<typename T>
class clientmecanicien : public Client, public mecanicien<T>
{
    double reductionprix;

public:
    clientmecanicien(const int CIN, const string& nom = " ", const string& prenom = " ",
                     const string& dateNaissance = " ", int experience = 0, T tarif_horaire = T(),
                     double reductionprix = 0.1)
        : mecanicien<T>(CIN, nom, prenom, dateNaissance, experience, tarif_horaire),
          Client(CIN, nom, prenom, dateNaissance),
          reductionprix(reductionprix)
    {
    }

    void afficherInfo()
    {
	mecanicien::afficherInfo();
	cout << "la reduction du prix totale est : " << reductionprix;

};


};
