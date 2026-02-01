#include <cctype>
#include "personne.h"
#include<iostream>
#include"automobile.h"
#include "Personne.h"
#include"Date.h"
#include<string>
#include"voiture.h"
#include"moto.h"
#include"camion.h"
using namespace std;


Personne::Personne(const Personne& w)
{

    CIN = w.CIN;
    nom = w.nom;
    prenom = w.prenom;
    dateNaissance = w.dateNaissance;
    for (int i = 0; i < w.listVehecule.size(); i++)
    {
        if (typeid(w.listVehecule[i]) == typeid(voiture)) {
            voiture* v = dynamic_cast<voiture*>(w.listVehecule[i]);
            listVehecule.push_back(v);
        }
        else {
            if (typeid(listVehecule[i]) == typeid(moto)) {
                moto* m = dynamic_cast<moto*>(w.listVehecule[i]);
                listVehecule.push_back(m);
            }
            else {

                if (typeid(listVehecule[i]) == typeid(camion)) {
                    camion* c = dynamic_cast<camion*>(w.listVehecule[i]);
                    listVehecule.push_back(c);

                }
            }


        }
    }

}
void Personne::afficherInfo()
{
    cout << "CIN: " << CIN << "\n" << "Nom: " << nom << "\n" << "Prénom: " << prenom << "\n" << "Date de naissance: " << dateNaissance << endl;
    for (int i = 0; i < listVehecule.size(); i++) {

        cout << listVehecule[i];
    }


}

void Personne::ajouterVehicule(automobile* r)
{
    listVehecule.push_back(r);
}

void Personne::supprimerVehicule(int j)
{
    listVehecule.erase(listVehecule.begin() + j);
}


ostream& operator<<(ostream& out, Personne& A)
{
    out << "la carte d'identite est:" << A.CIN;
    out << "\n";
    out << "le nom est :" << A.nom;
    out << "\n";
    out << "le prenom est :" << A.prenom;
    out << "\n";
    out << "la date de naissance est :" << A.dateNaissance;
    out << "\n";
    for (int i = 0; i < A.listVehecule.size(); i++) {
        out << "la vehicule numero " << i + 1 << "est :" << *(A.listVehecule[i]);
        out << "\n";
    }
    return out;
}
 bool estAlphabetique(const string& s) {
    for (char c : s) {
        if (!isalpha(c)) return false;
    }
    return true;
}

istream& operator>>(istream& in, Personne& A)
{
    cout << "le CIN est = ";
    in >> A.CIN;
    if (A.CIN < 0) {
        throw std::invalid_argument("Erreur : le CIN ne peut pas être négatif.");
    }

    cout << "le nom est = ";
    in >> A.nom;
    if (!estAlphabetique(A.nom)) {
        throw std::invalid_argument("Erreur : le nom doit contenir uniquement des lettres.");
    }

    cout << "le prénom est = ";
    in >> A.prenom;
    if (!estAlphabetique(A.prenom)) {
        throw std::invalid_argument("Erreur : le prénom doit contenir uniquement des lettres.");
    }

    cout<<"le date de naissance est ="<<endl;
    in >> A.dateNaissance;


    string r;
    do {
        voiture *b=new voiture();
        cout << "donner la voiture:";
        b->remplir();

        A.listVehecule.push_back(b);
        cout << "voulez vous ajouter une voiture?";
        cin >> r;
    } while (r == "o" || r == "O");
    return in;
}
void Personne::saisie()
{
    cout << "donne le CIN;";
    cin >> CIN;
    cout << endl;
    cout << "donner le nom:";
    cin >> nom;
    cout << endl;
    cout << "donner le prenom:";
    cin >> prenom;
    cout << endl;
    cout << "donne la date de naissance:";
    cin >> dateNaissance;
    cout << endl;
    string r;
    do {
        voiture* b = new voiture();
        cout << "donner la voiture:";
        b->remplir();

        listVehecule.push_back(b);
        cout << "voulez vous ajouter une voiture?";
        cin >> r;
    } while (r == "o" || r == "O");
}
