#include "Generavimasv02.h"
#include "Studentasv02.h"
#include "Skaiciavimasv02.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>
#include <filesystem>
#include <chrono>
#include <io.h>
#include <windows.h> 



using namespace std;

namespace fs = std::filesystem;

void generateStudents(int n, const string& filename) {
    if (std::filesystem::exists(filename)) {
        cout << "Failas " << filename << " jau egzistuoja." << endl;
        return;
    }

    auto start = std::chrono::high_resolution_clock::now();

    ofstream out(filename);
    if (!out) {
        cerr << "Klaida atidarant failà raðymui: " << filename << endl;
        return;
    }

    out << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
    for (int i = 1; i <= 13; i++) {
        out << setw(7) << "ND" << i;
    }
    out << setw(7) << "Egz." << endl;

    for (int i = 1; i <= n; i++) {
        out << setw(20) << "Vardas" + to_string(i) << setw(20) << "Pavarde" + to_string(i);
        for (int j = 0; j < 15; j++) {
            out << setw(10) << rand() % 10 + 1;
        }
        out << setw(10) << rand() % 10 + 1 << endl;
    }

    out.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "Generavimas su " << n << " irasu: " << elapsed.count() << " sekundziu." << endl;
}

void readStudentsFromFile(const string& filename, vector<Studentas>& studentai) {
    auto start = std::chrono::high_resolution_clock::now();

    ifstream in(filename);
    if (!in) {
        cerr << "Klaida atidarant failà skaitymui: " << filename << endl;
        return;
    }

    string header;
    getline(in, header); // Nuskaitome pirmà failo eilutæ - antraðtinæ eilutæ.

    while (!in.eof()) {
        Studentas studentas;
        in >> studentas.vardas >> studentas.pavarde;
        studentas.pazymiai.resize(15);

        for (int i = 0; i < 15; i++) {
            in >> studentas.pazymiai[i];
        }

        in >> studentas.egzaminas >> studentas.vidurkis;
        studentai.push_back(studentas);
    }

    in.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "Skaitymo ið failo funkcijos vykdymo laikas: " << elapsed.count() << " sekundþiø." << endl;
}

void groupAndSaveStudents(const vector<Studentas>& studentai, const string& baseFilename) {
    auto start = std::chrono::high_resolution_clock::now();

    vector<Studentas> vargsiukai;
    vector<Studentas> kietiakiai;

    for (const auto& student : studentai) {
        if (student.vidurkis < 5.0) {
            vargsiukai.push_back(student);
        }
        else {
            kietiakiai.push_back(student);
        }
    }

    saveToFile(vargsiukai, baseFilename + "_vargsiukai.txt");
    saveToFile(kietiakiai, baseFilename + "_kietiakiai.txt");

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "Rusiavimo funkcijos vykdymo laikas: " << elapsed.count() << " sekundþiø." << endl;
}


void saveToFile(const vector<Studentas>& studentas, const string& filename) {
    auto start = std::chrono::high_resolution_clock::now();

    ofstream out(filename);
    if (!out) {
        cerr << "Klaida atidarant failà raðymui: " << filename << endl;
        return;
    }

    out << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
    for (int i = 1; i <= 15; i++) {
        out << setw(4) << "ND" + to_string(i);
    }
    out << setw(5) << "Egz." << " Galutinis(Vid.)" << endl;

    for (const auto& studentas : studentas) {
        out << setw(20) << studentas.vardas << setw(20) << studentas.pavarde;
        for (int grade : studentas.pazymiai) {
            out << setw(4) << grade;
        }
        out << setw(5) << studentas.egzaminas << " " << studentas.vidurkis << endl;
    }

    out.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "Isvesta " << studentas.size() << " irasu i " << filename << ". Vykdymo laikas: " << elapsed.count() << " sekundziu." << endl;
}
