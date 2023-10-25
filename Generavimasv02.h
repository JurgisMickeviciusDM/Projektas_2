#ifndef Generavimas_h
#define Generavimas_h
#include "Studentasv02.h"
#include <list>


void saveToFile(const std::list<Studentas>& studentasList, const std::string& filename, const std::string& choice1);


void Generavimas(int n);

void Rusiuoti(const std::list<Studentas>& studentai, std::list<Studentas>& vargsiukai, std::list<Studentas>& kietiakiai);

void nuskaitymas(const std::string& filename, std::list<Studentas>& studentai, int n);


#endif // NAUDOTOJASV02_H
#pragma once
