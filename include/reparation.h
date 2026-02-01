#pragma once
#include<iostream>
#include<string>
using namespace std;
#include<vector>

class reparation
{
	string nom_reparation;
	double prix;
public:


	reparation(const string& nom_reparation=" ", double prix=0.0)
		: nom_reparation(nom_reparation), prix(prix)
	{
	}
	void remplissage();

};
