#include "Personne.h"
#include"Client.h"
#include<iostream>
void Client::saisie()
{
	cout << "donner le nom et prenom du client: ";
	cin >> nom >> prenom;
	cout << endl;
	cout << "CIN : ";
	cin >> CIN;
	cout << endl;
	cout << "donner la date de naissance : ";
	cin >> dateNaissance;
	cout << endl;
}
void Client::afficherInfo()
{
	cout << "======CLIENT======" << endl;
	Personne::afficherInfo();
	for (int i = 0; i < listFacture.size(); i++)
		cout<< *listFacture[i];
}
ostream& operator<<(ostream& out, Client& C) {

    out << static_cast<Personne&>(C);
    out << "=== LISTE DES FACTURES ===" << std::endl;
    for (size_t i = 0; i < C.listFacture.size(); ++i) {
        if (C.listFacture[i]) {
            out << "Facture #" << i + 1 << " :" << std::endl;
            out << *(C.listFacture[i]);
            out << std::endl;
        }
    }

    return out;
}
istream& operator>>(istream& in, Client& C) {

    in >> static_cast<Personne&>(C);

    int nbFactures;
    std::cout << "Combien de factures ? ";
    in >> nbFactures;
    for (int i = 0; i < nbFactures; ++i) {
        Facture* f = new Facture();
        f->saisir();
        C.listFacture.push_back(f);
    }
    return in;
}
Client::Client(const Client& c)
{
	for (int i = 0; i < c.listFacture.size(); i++)
		listFacture.push_back(new Facture(*(c.listFacture[i])));
}
void Client::ajouterFacture(Facture r)
{
	cout << "=======AJOUT FACTURE=========";
	cout << endl;
	listFacture.push_back(&r);
}
void Client::supprimerFacture(int j)
{
	cout << "======suppression facture=======";
	cout << endl;
	listFacture.erase(listFacture.begin() + j);
}
Client& Client::operator=(const Client&c)
{
	cout << "======recopie=======";
	nom = c.nom;
	listFacture = c.listFacture;
	return *this;
}
Client& Client:: operator+(Facture& f) {
    Facture* ptr = new Facture(f); // Copie dynamique
    listFacture.push_back(ptr);
    return *this;
}
