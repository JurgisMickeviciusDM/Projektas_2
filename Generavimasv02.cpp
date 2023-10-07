#include "Generavimasv02.h"
#include "Studentasv02.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>
#include <filesystem>
#include <chrono>

using namespace std;

void Failas(int n, const string& filename) {
    auto start = std::chrono::high_resolution_clock::now();

    if (std::filesystem::exists(filename)) {
        cout << "Failas " << filename << " jau egzistuoja." << endl;
        return;
    }

    ofstream out(filename);
    if (!out) {
        cerr << "Klaida atidarant fail� ra�ymui: " << filename << endl;
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

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "Generavimas su  " << n << " �ra��: " << elapsed.count() << " sekund�i�." << endl;
}

void Failai() {
    auto start = std::chrono::high_resolution_clock::now();

    srand(static_cast<unsigned int>(time(0)));
    vector<int> sizes = { 1000, 10000, 100000 };

    for (int size : sizes) {
        Failas(size, "studentai" + to_string(size) + ".txt");
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "Generavimo funkcijos vykdymo laikas: " << elapsed.count() << " sekundziu." << endl;
}

void sortAndSave(const vector<Studentas>& students, const string& baseFilename) {
    auto start = std::chrono::high_resolution_clock::now();

    vector<Studentas> vargsiukai;
    vector<Studentas> kietiakiai;

    for (const auto& student : students) {
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
    cout << "Rusiavimo funkcijos vykdymo laikas: " << elapsed.count() << " sekund�i�." << endl;
}

void saveToFile(const vector<Studentas>& studentas, const string& filename) {
    auto start = std::chrono::high_resolution_clock::now();

    ofstream out(filename);
    if (!out) {
        cerr << "Klaida atidarant fail� ra�ymui: " << filename << endl;
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
    cout << "Isvedimo i faila funkcijos vykdymo laikas: " << elapsed.count() << " sekund�i�." << endl;
}
