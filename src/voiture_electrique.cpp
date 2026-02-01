/*
#include "voiture_electrique.h"

void voiture_electrique::afficher_information()
{
	cout << "=======voiture electrique======" << endl;
	voiture::afficher_information();
	cout << endl;
	cout << "l'autonomie de la batterie est : " << Autonomie_batterie << endl;
	cout << "le temps de recharge de la batterie est : " << Temps_recharge << endl;

}

ostream& operator<<(ostream& out, voiture_electrique& VE)
{
	voiture* V = &VE;
	out << *V;
	out << "Autonomie_batterie : " << VE.Autonomie_batterie << endl;
	out << "Temps_recharge : " << VE.Temps_recharge << endl;
	return out;
}

istream& operator>>(istream& in, voiture_electrique& VE)
{
	voiture* V = &VE;
	in >> *V;
	cout << "donner l'autonomie de la batterie : ";
	in >> VE.Autonomie_batterie;
	cout << "\n donner le temps de recharge : ";
	in >> VE.Temps_recharge;
	return in;
}
*/
