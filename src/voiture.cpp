#include<iostream>
#include<string>
#include "voiture.h"
#include"personne.h"
using namespace std;


void voiture::afficher_information()
{
	cout << "====voiture====\n";
	cout << "marque:" << marque << " " << "modele:" << model << "\n";
	cout << "matricule: " << matricule << "\n";
	cout << "kilometrage: " << kilometrage << "\n";
	cout << "annee de fabrication : " << annee_fab << "\n";
	cout << "le nombre de porte " << nbporte << endl;
	cout << "le nombre de vitesse pour cette voiture est : " << nb_vitesse << endl;
	cout << "nombre de cylindre : " << nbcylindre << endl;

}

void voiture::ajouter_proprietaire(Client b)
{
	liste_proprietaire.push_back(&b);
}

void voiture::afficher_proprietaires()
{
	for (int i = 0; i < liste_proprietaire.size(); i++) {
		cout << liste_proprietaire[i];
		cout << endl;
	}
}

void voiture::afficher_liste_reparation()
{
	for (int i = 0; i < historique_reparation.size(); i++) {
		cout << historique_reparation[i];
		cout << endl;
	}

}

void voiture::get_nbporte()
{
	cout << nbporte;
}

void voiture::set_nbporte(int j)
{
	nbporte += j;
}

void voiture::saisir()
{
	cout << "donner le nombre de porte";
	cin >> nbporte;
	cout << endl;
	cout << "donner le nombre de cylindre:";
	cin >> nbcylindre;
	cout << endl;
	int a;
	cout << "donner le nombre de proprietaire de cette voiture:";
	cin >> a;
	cout << endl;
	for (int i = 0; i < a; i++) {
		Client* s=new Client;
		s->saisie();
		liste_proprietaire.push_back(s);
	}

}




ostream& operator<<(ostream& out, voiture& v)
{
	out << static_cast<automobile*>(&v);
	out << "le nombre de porte est : " << v.nbporte << endl;
	out << "le nombre de cylindre est : " << v.nbcylindre << endl;
	out << "le nombre de vitesse est : " << v.nb_vitesse << endl;
	for (int i = 0; i < v.liste_proprietaire.size(); i++)
		out <<  v.liste_proprietaire[i];
	return out;
}


istream& operator>>(istream& in, voiture& v)
{

	automobile* a = &v;
	in >> *a;
	cout << "\n le nb de porte :";
	in >> v.nbporte;
	cout << "\ndonner le nb de cylindre :";
	in >> v.nbcylindre;
	cout << "donner le nombre de vitesse :";
	in >> v.nb_vitesse;
	string r;
	do {


		Client* c=new Client;
		in >> *c;

		v.liste_proprietaire.push_back(c);
		cout << "VOULEZ VOUS AJOUTER UN CLIENT?";
		cin >> r;
	} while (r == "o" || r == "O");


	return in;
}
voiture& voiture::operator=(const voiture& V)
{
	marque = V.marque;
	model = V.model;
	matricule = V.matricule;
	kilometrage = V.kilometrage;
	annee_fab = V.annee_fab;
	nbporte = V.nbporte;
	nbcylindre = V.nbcylindre;
	nb_vitesse = V.nb_vitesse;
	liste_proprietaire = V.liste_proprietaire;
	return *this;

}
