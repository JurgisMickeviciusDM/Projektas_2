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

void Generavimas(int n) {
    auto start = std::chrono::high_resolution_clock::now(); // Added start timepoint here

    string filename = "studentai" + to_string(n) + ".txt";
    if (_access(filename.c_str(), 0) == 0) {
        cout << "Failas " << filename << " jau egzistuoja." << endl;
        return; // Exiting the function early instead of 'continue'
    }

    ofstream out(filename);
    if (!out) {
        cerr << "Klaida atidarant failà rasymui: " << filename << endl;
        return; // Exiting the function early instead of 'return 1'
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

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Generavimas studentu " << n << " " << elapsed.count() << " sekundes" << std::endl;
}
