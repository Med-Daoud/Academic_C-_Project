#include "moto.h"

void moto::afficher_information()
{
	cout << "=====MOTO=====" << endl;
	cout << "marque:" << marque << " " << "modele:" << model << "\n";
	cout << "matricule: " << matricule << "\n";
	cout << "kilometrage: " << kilometrage << "\n";
	cout << "annee de fabrication : " << annee_fab << "\n";
	cout << "le nombre de cylindre est : " << cylindre << endl;
	cout << "le type de mto est : " << type_moto << endl;
}
ostream& operator<<(ostream& out, moto& m)
{
	automobile* a = &m;
	out << *a;
	out << "\n nbcylindre :" << m.cylindre;
	out << "\nle type :" << m.type_moto;
	return out;
}

istream& operator>>(istream& in, moto& m)
{
	automobile* a = &m;
	in >> *a;
	cout << "\ndonner le nb de cylindre : ";
	in >> m.cylindre;
	cout << "\donner le type du moto :";
	in >> m.type_moto;
	return in;

}
