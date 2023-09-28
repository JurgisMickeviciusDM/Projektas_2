#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <vector>
#include <string>

struct Studentas {
    std::string vardas;
    std::string pavarde;
    std::vector<int> pazymiai;
    double vidurkis = 0.00;
    double mediana = 0.00;
    double galutinis = 0.00;
};

bool comparePavardes(const Studentas& a, const Studentas& b);
double calculateMedian(const std::vector<int>& grades);

#endif
