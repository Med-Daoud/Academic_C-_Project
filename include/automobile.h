#pragma once
#include<iostream>
#include<string>
#include"reparation.h"
using namespace std;
#include<vector>

class automobile
{
protected:
	string marque;
	string model;
	string matricule;
	float kilometrage;
	string annee_fab;
	vector<reparation*> historique_reparation;
public:


	automobile(const string& marque=" ", const string& model=" ", const string& matricule=" ", float kilometrage=0.0, const string& annee_fab=" ")
		: marque(marque), model(model), matricule(matricule), kilometrage(kilometrage), annee_fab(annee_fab)
	{
	}
	automobile(const automobile&);
	void remplir();
	virtual void afficher_information() =0;
	virtual float cout_entretien_annuel()= 0;
	void afficher_liste_reparation();
	void ajouter_reparation(reparation);
	void supprimer_reparation(int);
	void ajour_kilometrage(float);
	~automobile() {
		for (int i = 0; i < historique_reparation.size(); i++)
			delete historique_reparation[i];
		historique_reparation.clear();
	}
	string getMarque()
	{
		return marque;
	};
	string getModele() {
		return model;

	};
	string getMatricule() {
		return matricule;
	};
	float getKilometrage() {
		return kilometrage;

	};
	string getAnnee() {
		return annee_fab;

	};
	friend ostream& operator << (ostream&, automobile&);
	friend istream& operator >> (istream&, automobile&);


};
