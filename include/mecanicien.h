#pragma once
#include<iostream>
#include<string>
#include"personne.h"
using namespace std;

template<typename T>
class mecanicien : public Personne
{
protected:
    int experience;
    T tarif_horaire;

public:
    mecanicien(const int CIN, const string& nom = " ", const string& prenom = " ",
               const string& dateNaissance = " ", int experience = 0, T tarif_horaire = T())
        : Personne(CIN, nom, prenom, dateNaissance), experience(experience), tarif_horaire(tarif_horaire)
    {
    }
	void siaisir(){
	cout << "donner le cin : ";
	cin >> CIN;
	cout << endl;
	cout << "donner le nom du mecanicien : ";
	cin >> nom;
	cout << endl;
	cout << "donner la date de naiss : ";
	cin >> dateNaissance;
	cout << "donner le nombre d'anne d'experience : ";
	cin >> experience;
	cout << endl;
	cout << "donner le tarif horaire : ";
	cin >> tarif_horaire;
	cout << endl;


};
	double claculrevenue(int p){double s = 0;
	s += p * tarif_horaire;
	return s;};
	void afficher()
	{
	cout << "le nom et prenom et numero cin : " << CIN << nom << prenom;
	cout << "\nla date de naissance est : " << dateNaissance;
	cout << "\nl'expertice est : " << experience;
	cout << "\n le tarif par heur est : " << tarif_horaire;
};
};

