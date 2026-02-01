/*#include "voiture_hybride.h"

void voiture_hybride::afficher_information()
{
	cout << "======voiture hybride======" << endl;
	voiture_hybride::afficher_information();
	cout << endl;
	cout << "Autonomie Batterie: " << Autonomie_batterie << " km\n"
		<< "Temps de recharge: " << Temps_recharge << " h\n"
		<< "Capacité du réservoir: " << capaciteReservoir << " L\n"
		<< "Consommation: " << consommation << " L/100km" <<endl;
}

ostream& operator<<(ostream& out, voiture_hybride& VH)
{
	voiture_electrique * V = &VH;
	out << *V;
	out << "capacite du reservoire est : " << VH.capaciteReservoir;
	cout << "\n consommation : " << VH.consommation;

	return out;
}

istream& operator>>(istream& in, voiture_hybride& VH)
{
	voiture_electrique* V = &VH;
	in >> *V;
	cout << "donner la capacite du reservoir : ";
	in >> VH.capaciteReservoir;
	cout << "\n donner la consommation par km : ";
	in >> VH.consommation;
	return in;
}

*/
