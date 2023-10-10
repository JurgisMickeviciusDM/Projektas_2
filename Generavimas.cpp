#include "Generavimas.h"
#include "Studentas.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>
#include <filesystem>

using namespace std;

void Ifaila(int n, const string& filename) {
    if (std::filesystem::exists(filename)) {
        cout << "Failas " << filename << " jau egzistuoja." << endl;
        return;
    }

    ofstream out(filename);
    if (!out) {
        cerr << "Klaida atidarant failà raðymui: " << filename << endl;
        return;
    }

    out << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
    for (int i = 1; i <= 15; i++) {
        out << setw(10) << "ND" + to_string(i);
    }
    out << "Egz." << endl;

    for (int i = 1; i <= n; i++) {
        out << setw(20) << "Vardas" + to_string(i) << setw(20) << "Pavarde" + to_string(i);
        for (int j = 0; j < 15; j++) {
            out << setw(10) << rand() % 10 + 1;
        }
        out << rand() % 10 + 1 << endl;
    }

    out.close();
}

void Ifaila() {
    srand(static_cast<unsigned int>(time(0)));
    vector<int> sizes = { 1000, 10000, 100000 };

    for (int size : sizes) {
        Ifaila(size, "studentai" + to_string(size) + ".txt");
    }
}

void sortAndSave(const vector<Studentas>& students, const string& baseFilename) {
    vector<Studentas> vargsiukai;
    vector<Studentas> kietiakiai;

    for (const auto& student : students) {
        if (student.vidurkis < 5.0) {
            vargsiukai.push_back(student);
        } else {
            kietiakiai.push_back(student);
        }
    }

    saveToFile(vargsiukai, baseFilename + "_vargsiukai.txt");
    saveToFile(kietiakiai, baseFilename + "_kietiakiai.txt");
}

void saveToFile(const vector<Studentas>& studentas, const string& filename) {
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
}