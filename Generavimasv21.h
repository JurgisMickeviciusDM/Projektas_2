#ifndef GENERAVIMAS_H
#define GENERAVIMAS_H

#include "Studentasv21.h"
#include <vector>
#include <list>
#include <string>

void RusiuotiV(std::vector<Studentas>& studentai, std::vector<Studentas>& vargsiukai, std::vector<Studentas>& kietiakiai, char choice2);
void nuskaitymasV(const std::string& filename, std::vector<Studentas>& studentai, int n);
void saveToFileV(const std::vector<Studentas>& studentasList, const std::string& filename, const std::string& choice1);



void saveToFile(const std::list<Studentas>& studentasList, const std::string& filename, const std::string& choice1);
void Generavimas(int n);
void Rusiuoti(std::list<Studentas>& studentai, std::list<Studentas>& vargsiukai, std::list<Studentas>& kietiakiai, char choice2);
void nuskaitymas(const std::string& filename, std::list<Studentas>& studentai, int n);

#endif // GENERAVIMAS_H