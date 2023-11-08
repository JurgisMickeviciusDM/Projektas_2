#ifndef STUDENTASV1_H
#define STUDENTASV1_H

#include <vector>
#include <string>
#include <list>

struct Studentas {//studento struktura 
    std::string vardas;
    std::string pavarde;
    std::vector <int> pazymiaiV;//pazymiai saugomi vektorius
    std::list <int>pazymiai;
    double vidurkis = 0.00;
    double mediana = 0.00;
    double galutinis = 0.00;
    double egzaminas = 0.00;
};




#endif