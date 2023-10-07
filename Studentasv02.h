#ifndef STUDENTASV02_H
#define STUDENTASV02_H

#include <vector>
#include <string>

struct Studentas {//studento struktura 
    std::string vardas;
    std::string pavarde;
    std::vector<int> pazymiai;//pazymiai saugomi vektorius
    double vidurkis = 0.00;
    double mediana = 0.00;
    double galutinis = 0.00;
    double egzaminas = 0.00;
};




#endif