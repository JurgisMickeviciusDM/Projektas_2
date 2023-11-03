#ifndef STUDENTASV1_H
#define STUDENTASV1_H

#include <list>
#include <string>

struct Studentas {//studento struktura 
    std::string vardas;
    std::string pavarde;
    std::list<int> pazymiai;//pazymiai saugomi vektorius
    double vidurkis = 0.00;
    double mediana = 0.00;
    double galutinis = 0.00;
    double egzaminas = 0.00;
};




#endif