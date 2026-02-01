/*#include "voiture_essence.h"

void voiture_essence::afficher_information()
{
	cout << "======voiture a essence======" << endl;
	voiture::afficher_information();
	cout << "la capacite du reservoir est :" << capaciteReservoir << endl;
	cout << "la consommation par kilometre est : " << consommation << endl;

}

ostream& operator<<(ostream& out, voiture_essence& VS)
{
	voiture* V = &VS;
	out << *V;
	out << "capaciteReservoir : " << VS.capaciteReservoir << endl;
	out << "consommation : " << VS.consommation << endl;
	return out;

}

istream& operator>>(istream& in, voiture_essence& VS)
{
	voiture* V = &VS;
	in >> *V;
	cout << "donner la capacite du reservoir : ";
	in >> VS.capaciteReservoir;
	cout << "\n donner la consommation par km : ";
	in >> VS.consommation;
	return in;
}*/
