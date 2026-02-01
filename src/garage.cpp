#include<iostream>
#include "garage.h"
#include<vector>
#include"client.h"
#include"camion.h"
#include"mecanicien.h"
using namespace std;

void garage::ajouter_automobile(automobile*a)
{
    if (dynamic_cast<voiture*>(a))
        cout << "ajout d'une voiture" << endl;
    else if (dynamic_cast<moto*>(a))
        cout << "ajout d'un moto" << endl;
    else if (dynamic_cast<camion*>(a))
        cout << "ajout d'un camion" << endl;
    vehicule.push_back(a);
}

void garage::ajouter_employee(Personne* p)
{
    if (dynamic_cast<mecanicien<float>*>(p)) {
        cout << "ajout d'un mecanicien " << endl;
        employee.push_back(p);
    }
    else
        cout << "ce n'est pas un mecanicient";
}

void garage::ajout_employee_manu()
{
    string r;
    do {

        mecanicien<float> *m;
        m->siaisir();
        employee.push_back(m);
        cout << "voulez vous ajouter une reparation?";
        cin >> r;
    } while (r == "o" || r == "O");
}

void garage::supprimer_employee(int i)
{
    employee.erase(employee.begin() + i);
}

void garage::afficher_emloyee(int i)
{
    for (const auto& employee : employee) {
        employee->afficherInfo();
    }
}
void garage::supprimer_vehicule(int i)
{
    if (typeid(vehicule[i]) == typeid(voiture))
        cout << "suppression d'unne voiture" << endl;
    else {
        if (typeid(vehicule[i]) == typeid(moto))
            cout << "suppression d'un moto" << endl;
        else {
            if (typeid(vehicule[i]) == typeid(camion))
                cout << "suppression d'un camion" << endl;
        }
    }
    vehicule.erase(vehicule.begin() + i);
}

void garage::afficher_vehicule(int j)
{

    for (const auto& vehicule : vehicule) {
        vehicule->afficher_information();
    }
}

void garage::afficher()
{
    cout << " Garage: " << nom << " contient :\n";
    for (int i = 0;i<=vehicule.size();i++) {
        vehicule[i]->afficher_information();
    }
}





void garage::insersionfichier(fstream& f,automobile* A, int a)
{
    char nom[50];
    cout << "donner le nom du fichier:";
    cin >> nom;
    cout << endl;
    f.open(nom, ios::in | ios::out | ios::trunc);
    garage g;
    f.seekg(0);
    f << &g;
    g.vehicule.insert(vehicule.begin() + a, A);
    f << &g;
}
void garage::enregistrer()
{
    ofstream f("C:/pro/exemple.txt");
    if (!f.is_open()) {
        cerr << "Erreur d'ouverture du fichier !" << endl;
        return;
    }
    for (auto v : vehicule) {
        if (auto* voit = dynamic_cast<voiture*>(v)) {
            f << 1 << endl;
            f << voit->getMarque() << endl;
            f << voit->getModele() << endl;
            f << voit->getMatricule() << endl;
            f << voit->getKilometrage() << endl;
            f << voit->getAnnee() << endl;
            f << voit->getNbPorte() << endl;
            f << voit->getNb_vitesse() << endl;
            f << voit->getNbcylindre() << endl;
        }
        else if (auto* m = dynamic_cast<moto*>(v)) {
            f << 2 << endl;
            f << m->getMarque() << endl;
            f << m->getModele() << endl;
            f << m->getMatricule() << endl;
            f << m->getKilometrage() << endl;
            f << m->getAnnee() << endl;
            f << m->getCylindre() << endl;
            f << m->getTypeMoto() << endl;
        }
        else if (auto* c = dynamic_cast<camion*>(v)) {
            f << 3 << endl;
            f << c->getMarque() << endl;
            f << c->getModele() << endl;
            f << c->getMatricule() << endl;
            f << c->getKilometrage() << endl;
            f << c->getAnnee() << endl;
            f << c->getCapaciteCharge() << endl;
            f << c->get_nbboitevitesse() << endl;
        }
    }

    f.close();
    cout << "Données enregistrées avec succès." << endl;
}


void garage::recuperer()
{
    fstream f("C:/pro/exemple.txt", ios::in);
    if (!f.is_open()) {
        cerr << "Erreur d'ouverture du fichier !" << endl;
        return;
    }

    int choix;
    while (f >> choix)
    {
        f.ignore();

        if (choix == 1)
        {
            voiture* v = new voiture();
            f >> *v;
            vehicule.push_back(v);
        }
        else if (choix == 2)
        {
            moto* m = new moto();
            f >> *m;
            vehicule.push_back(m);
        }
        else if (choix == 3)
        {
            camion* c = new camion();
            f >> *c ;
            vehicule.push_back(c);
        }
        else
        {
            cerr << "Type de véhicule inconnu dans le fichier: " << choix << endl;
            break;
        }


        if (f.fail()) {
            cerr << "Erreur de lecture des données." << endl;
            break;
        }
    }

    cout << "Lecture effectuée avec succès." << endl;
    f.close();
}

garage::garage(const garage& w)
{
    for (int i = 0; i < w.vehicule.size(); i++)
    {
        if (typeid(w.vehicule[i]) == typeid(voiture)) {
            voiture* v = dynamic_cast<voiture*>(w.vehicule[i]);
            vehicule.push_back(v);
        }
        else {
            if (typeid(vehicule[i]) == typeid(moto)) {
                moto* m = dynamic_cast<moto*>(w.vehicule[i]);
                vehicule.push_back(m);
            }
            else {

                if (typeid(vehicule[i]) == typeid(camion)) {
                    camion* c = dynamic_cast<camion*>(w.vehicule[i]);
                    vehicule.push_back(c);

                }
            }


        }
    }

}
ostream& operator<<(ostream& out, garage* g)
{
    for (int i = 0; i < g->vehicule.size(); i++)
    {
        if (typeid(*g->vehicule[i]) == typeid(voiture))
            out << "1" << *g->vehicule[i] << endl;
        else if (typeid(*g->vehicule[i]) == typeid(moto))
            out << "2" << *g->vehicule[i] << endl;
        else
            out << "3" << *g->vehicule[i] << endl;
   }
    cout << "lecture effectuer avec succe";

    return out;
}
istream& operator>>(istream& in, garage* g)
{
    fstream f;
    f.open("C:\pro", ios::in | ios::out | ios::trunc);
    if (!f.is_open()) exit(-1);
    int choix;
    in.seekg(0);
    while (1)
    {
        cout << "donner le choix:";
        in >> choix;
        if (in.eof()) break;
        if (choix == 1)
        {
            voiture* v = new voiture;
            in >> *v;
            g->ajouter_automobile(v);
        }
        else if (choix == 2)
        {
            moto* m = new moto;
            in >> *m;
            g->vehicule.push_back(m);
        }
        else
        {
            camion* c = new camion;
            in >> *c;
            g->vehicule.push_back(c);
        }
        cout << "ecriture effectuer avec succee";
    }
    return in;
}
void garage::insersionfichier(automobile* v) {
   {
    ofstream f("C:/pro/exemple.txt", ios::app);  // ⚠️ mode append
    if (!f.is_open()) {
        cerr << "Erreur lors de l'ouverture du fichier pour insertion !" << endl;
        return;
    }

    if (auto* voit = dynamic_cast<voiture*>(v)) {
        f << 1 << endl;
        f << voit->getMarque() << endl;
        f << voit->getModele() << endl;
        f << voit->getMatricule() << endl;
        f << voit->getKilometrage() << endl;
        f << voit->getAnnee() << endl;
        f << voit->getNbPorte() << endl;
        f << voit->getNb_vitesse() << endl;
        f << voit->getNbcylindre() << endl;
    }
    else if (auto* m = dynamic_cast<moto*>(v)) {
        f << 2 << endl;
        f << m->getMarque() << endl;
        f << m->getModele() << endl;
        f << m->getMatricule() << endl;
        f << m->getKilometrage() << endl;
        f << m->getAnnee() << endl;
        f << m->getCylindre() << endl;
        f << m->getTypeMoto() << endl;
    }
    else if (auto* c = dynamic_cast<camion*>(v)) {
        f << 3 << endl;
        f << c->getMarque() << endl;
        f << c->getModele() << endl;
        f << c->getMatricule() << endl;
        f << c->getKilometrage() << endl;
        f << c->getAnnee() << endl;
        f << c->getCapaciteCharge() << endl;
        f << c->get_nbboitevitesse() << endl;
    }

    f.close();
    cout << "Véhicule inséré avec succès dans le fichier." << endl;
}}
void garage::supprimer_fichier(int indexASupprimer)
{
    ifstream fin("C:/pro/exemple.txt");
    if (!fin.is_open()) {
        cerr << "Erreur d'ouverture du fichier en lecture !" << endl;
        return;
    }

    vector<string> lignes;
    string ligne;

    // Lire tout le contenu
    while (getline(fin, ligne)) {
        lignes.push_back(ligne);
    }
    fin.close();

    // Parcourir et détecter les blocs de véhicules (chaque bloc commence par 1, 2 ou 3)
    vector<vector<string>> blocs;
    for (size_t i = 0; i < lignes.size(); ) {
        vector<string> bloc;
        int type = stoi(lignes[i]);
        int taille = 0;

        if (type == 1) taille = 9;
        else if (type == 2) taille = 7;
        else if (type == 3) taille = 8;
        else {
            cerr << "Format inconnu, abandon..." << endl;
            return;
        }

        if (i + taille <= lignes.size()) {
            for (int j = 0; j < taille; ++j)
                bloc.push_back(lignes[i + j]);
            blocs.push_back(bloc);
        }

        i += taille;
    }

    // Vérification d'indice
    if (indexASupprimer < 0 || indexASupprimer >= blocs.size()) {
        cerr << "Index invalide !" << endl;
        return;
    }

    // Supprimer le bloc voulu
    blocs.erase(blocs.begin() + indexASupprimer);

    // Réécrire le fichier sans ce bloc
    ofstream fout("C:/pro/exemple.txt", ios::trunc);
    if (!fout.is_open()) {
        cerr << "Erreur d'ouverture du fichier en écriture !" << endl;
        return;
    }

    for (const auto& bloc : blocs) {
        for (const auto& l : bloc)
            fout << l << endl;
    }

    fout.close();
    cout << "Véhicule supprimé avec succès du fichier." << endl;
}
