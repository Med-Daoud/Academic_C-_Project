#pragma once
#include <iostream>  // Fixed the extra '>'
using namespace std;  // Added to avoid needing std:: prefix

class Date
{
  public:
    int jour;
    int mois;
    int annee;

    // Constructor to initialize Date object
    Date() {jour=0;
    mois=0;
    annee=0;}

    // Destructor (optional here, but added for completeness)
    ~Date() {}
};
