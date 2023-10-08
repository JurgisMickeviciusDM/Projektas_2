#pragma once
#include "Studentasv02.h"
#include <vector>

void Ifaila();
void sortAndSave(const std::vector<Studentas>& students, const std::string& baseFilename);
void saveToFile(const std::vector<Studentas>& students, const std::string& filename);


// Funkcija skirta generuoti studentø áraðus á failà
void generateStudents(int n, const std::string& filename);

// Funkcija skirta skaityti studentø áraðus ið failo ir sudëti juos á vektoriø
void readStudentsFromFile(const std::string& filename, std::vector<Studentas>& studentai);

// Funkcija skirta sugrupuoti studentus á vargsiukus ir kietiakius, ir iðsaugoti á atskirus failus
void groupAndSaveStudents(const std::vector<Studentas>& studentai, const std::string& baseFilename);

// Funkcija skirta iðsaugoti studentø duomenis á failà
//void saveToFile(const std::vector<Studentas>& studentai, const std::string& filename);

