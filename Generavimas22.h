#ifndef GENERAVIMAS22_H
#define GENERAVIMAS22_H

#include "Studentas22.h"
#include <vector>
#include <list>
#include <string>



void saveToFile(const std::list<Studentas>& studentasList, const std::string& filename, const std::string& choice1);
void Generavimas(int n);
void Rusiuoti(std::list<Studentas>& studentai, std::list<Studentas>& vargsiukai, std::list<Studentas>& kietiakiai, char choice2);
void nuskaitymas(const std::string& filename, std::list<Studentas>& studentai, int n);

#endif // GENERAVIMAS_H