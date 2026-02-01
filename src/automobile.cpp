#include "automobile.h"
using namespace std;
#include"reparation.h"

ostream& operator<<(ostream& out, automobile& A)
{
    out << "la marque est:" << A.marque;
    out << "\n";
    out << "le modele est :" << A.model;
    out << "\n";
    out << "la matricule est :" << A.matricule;
    out << "\n";
    out << "le kilometrage est :" << A.kilometrage;
    out << "\n";
    out << "l'annee de fabrication est :" << A.annee_fab;
    out << "\n";
    for (int i = 0; i < A.historique_reparation.size(); i++) {
        out << "la reparation numero " << i + 1 << "est :" << A.historique_reparation[i];
        out << "\n";
    }
    return out;
}

istream& operator>>(istream& in, automobile& A)
{
    cout << "donner la marque";
    in >> A.marque;
    cout << "\ndonner le model :";
    in >> A.model;
    cout << "\ndonner la matricule :";
    in >> A.matricule;
    cout << "\ndonner le kilometrage :";
    in >> A.kilometrage;
    cout << "\ndonner l'anne de fab :";
    in >> A.annee_fab;
    string r;
    do {

        cout << "donner la reparation pour cette voiture:";
        reparation* b=new reparation;
        b->remplissage();
        cout << endl;
        A.historique_reparation.push_back(b);
        cout << "voulez vous ajouter une reparation?";
        cin >> r;
    } while (r == "o" || r == "O");
    return in;
}

automobile::automobile(const automobile& w)
{

    marque = w.marque;
    model = w.model;
    matricule = w.matricule;
    kilometrage = w.kilometrage;
    annee_fab = w.annee_fab;
    for (int i = 0; i < w.historique_reparation.size(); i++)
        historique_reparation.push_back(new reparation(*( w.historique_reparation[i])));


}

void automobile::remplir()
{
    cout << "donne la marque de l'automobile;";
    cin >> marque;
    cout << endl;
    cout << "donner le modele:";
    cin >> model;
    cout << endl;
    cout << "donner la matricule:";
    cin >> matricule;
    cout << endl;
    cout << "donne le kilometrage:";
    cin >> kilometrage;
    cout << endl;
    cout << "donner l'anne de fabrication:";
    cin >> annee_fab;
    cout << endl;
    string r;
    do {

        cout << "donner la reparation pour cette voiture:";
        reparation *b=new reparation;
        b->remplissage();
        cout << endl;
        historique_reparation.push_back(b);
        cout << "voulez vous ajouter une reparation?";
        cin >> r;
    } while (r == "o" || r == "O");
}

void automobile::afficher_liste_reparation()
{
    for (int i =0; i < historique_reparation.size(); i++) {
        cout << "la reparation numero" << i + 1 << historique_reparation[i];
        cout << endl;
    }
}

void automobile::ajouter_reparation(reparation r)
{
    historique_reparation.push_back(&r);
}

void automobile::supprimer_reparation(int j)
{
    historique_reparation.erase(historique_reparation.begin() + j);
}

void automobile::ajour_kilometrage(float k)
{
    kilometrage += k;
}
