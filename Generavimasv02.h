#ifndef NAUDOTOJASV02_H
#define NAUDOTOJASV02_H
#include "Studentasv02.h"
#include <vector>

void saveToFile(const std::vector<Studentas>& studentasList, const std::string& filename, const std::string& choice1);


void Generavimas(int n);

void Rusiuoti(const std::vector<Studentas>& studentai, std::vector<Studentas>& vargsiukai, std::vector<Studentas>& kietiakiai);


#endif // NAUDOTOJASV02_H
