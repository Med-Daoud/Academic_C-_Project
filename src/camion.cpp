#include "camion.h"

void camion::afficher_information()
{
	cout << "=====CAMION=====" << endl;
	cout << "marque:" << marque << " " << "modele:" << model << "\n";
	cout << "matricule: " << matricule << "\n";
	cout << "kilometrage: " << kilometrage << "\n";
	cout << "annee de fabrication : " << annee_fab << "\n";
	cout << "la capacite de charge pour ce camion est : " << capacite_charge << endl;
	cout << "le nombre de boite vitesse pour ce camion est : " << nb_boitevitesse << endl;
}

ostream& operator<<(ostream& out, camion& c)
{
	automobile* a = &c;
	out << a;
	out << c.capacite_charge;
	out << c.nb_boitevitesse;
	return out;
}

istream& operator>>(istream& in, camion& c)
{
	automobile* a=&c;
	in >> *a;
	cout << "\ndonner la capacite :";
	in >> c.capacite_charge;
	cout << "\ndonner le nb de voite vitesse :";
	in >> c.nb_boitevitesse;
	return in;
}
