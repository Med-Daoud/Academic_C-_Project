#pragma once
#include<iostream>
#include<string>
using namespace std;
#include<vector>
#include"automobile.h"
#include<fstream>
#include"voiture.h"
#include"moto.h"
#include"camion.h"
#include"personne.h"
class garage
{protected:
	string nom;
	vector<automobile*>vehicule;
	vector<Personne*>employee;

public:
	garage(const string& nom = " ") :
		nom(nom) {
	}
	void insersionfichier(automobile*);
	void supprimer_fichier(int);
	void ajouter_automobile(automobile*);
	void ajouter_employee(Personne*);
	void ajout_employee_manu();
	void supprimer_employee(int);
	void afficher_emloyee(int);
	void supprimer_vehicule(int);
	void afficher_vehicule(int);
	void afficher();
	friend ostream& operator << (ostream&, garage*);
	friend istream& operator >> (istream&, garage*);
	void insersionfichier(fstream&,automobile*, int);
	void enregistrer();
	void recuperer();
	garage(const garage&);
	~garage() {
		for (int i = 0; i < vehicule.size(); i++)
			delete vehicule[i];
		vehicule.clear();
		for (int i = 0; i < employee.size(); i++)
			delete employee[i];
		employee.clear();
	}
};
