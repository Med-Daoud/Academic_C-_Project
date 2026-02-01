#include <iostream>
#include"Personne.h"
#include"voiture.h"
#include"garage.h"
#include"mecanicien.h"
#include<string>
using namespace std;

void afficherMenu() {
    cout << "\n===== MENU GARAGE =====\n";
    cout << "1. Ajouter un vehicule\n";
    cout << "2. Supprimer un vehicule\n";
    cout << "3. Afficher un vehicule\n";
    cout << "4. Ajouter un employe\n";
    cout << "6. Supprimer un employe\n";
    cout << "7. Afficher un employe\n";
    cout << "8. Afficher le garage\n";
    cout << "9. Enregistrer les donnees\n";
    cout << "10. Recuperer les donnees\n";
    cout << "0. Quitter\n";
    cout << "Choix : ";
}

int main() {
    garage g1,g2;
    moto m;
    cin>>m;
    g1.ajouter_automobile(&m);
    g1.enregistrer();
    g2.recuperer();
    g2.afficher();

}
    /*
    garage g("Garage Central");
    int choix;
    do {
        afficherMenu();
        cin >> choix;
        switch (choix) {
            case 1: {
                // Exemple : création manuelle ou via une fonction
                cout << "1. Ajouter une voiture\n";
                cout << "2.Ajouter un camion\n";
                cout << "3. Ajouter un moto\n";
                cin >> choix;
                switch (choix) {
                    case 1: {
                        voiture v;
                        cin >> v;
                        g.ajouter_automobile(&v);
                        break;
                    }
                    case 2: {
                        camion v;
                        cin >> v;
                        g.ajouter_automobile(&v);
                        break;
                    }
                    case 3: {
                        moto v;
                        cin >> v;
                        g.ajouter_automobile(&v);
                        break;
                    }
                }
                break;
            }
            case 2: {
                int index;
                cout << "Indice du vehicule a supprimer : ";
                cin >> index;
                g.supprimer_vehicule(index);
                break;
            }
            case 3: {
                int index;
                cout << "Indice du vehicule a afficher : ";
                cin >> index;
                g.afficher_vehicule(index);
                break;
            }
            case 4: {
                Client c;
                cin >> c;
                g.ajouter_employee(&c);
                break;
            }
            case 6: {
                int index;
                cout << "Indice de l'employe a supprimer : ";
                cin >> index;
                g.supprimer_employee(index);
                break;
            }
            case 7: {
                int index;
                cout << "Indice de l'employe a afficher : ";
                cin >> index;
                g.afficher_emloyee(index);
                break;
            }
            case 8: {
                g.afficher();
                break;
            }
            case 9: {
                g.enregistrer();
                break;
            }
            case 10: {
                g.recuperer();
                break;
            }
            case 0: {
                cout << "Fermeture du programme.\n";
                break;
            }
            default: {
                cout << "Choix invalide.\n";
                break;
            }
        }
    } while (choix != 0);
    return 0;
}
*/
