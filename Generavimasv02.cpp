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
    string output;
    output.reserve(studentas.size() * 200);

    out << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
    for (int i = 1; i <= 9; i++) {
        out << setw(7) << "ND" + to_string(i);
    }
    out << setw(11) << "Egz." << " Galutinis(Vid.)" << endl;

    for (const auto& studentas : studentas) {
        out << setw(20) << studentas.vardas << setw(20) << studentas.pavarde;
        for (int grade : studentas.pazymiai) {
            out << setw(7) << grade;
        }
        out << setw(11) << studentas.egzaminas << " " << studentas.vidurkis << endl;
    }

    out.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "Isvesta " << studentas.size() << " irasu i " << filename << ". Vykdymo laikas: " << elapsed.count() << " sekundziu." << endl;
}

void Generavimas(int n) {
    auto start = std::chrono::high_resolution_clock::now();

    string filename = "studentai" + to_string(n) + ".txt";
    if (_access(filename.c_str(), 0) == 0) {
        cout << "Failas " << filename << " jau egzistuoja." << endl;
        return;
    }

    ofstream out(filename);
    if (!out) {
        cerr << "Klaida atidarant failà rasymui: " << filename << endl;
        return;
    }

    out << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
    for (int i = 1; i <= 9; i++) {
        out << setw(7) << "ND" + to_string(i);
    }
    out << setw(11) << "Egz." << endl;

    for (int i = 1; i <= n; i++) {
        out << setw(20) << "Vardas" + to_string(i) << setw(20) << "Pavarde" + to_string(i);
        for (int j = 0; j < 9; j++) {
            out << setw(7) << rand() % 10 + 1;
        }
        out << setw(11) << rand() % 10 + 1 << endl;
    }

    out.close();

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Generavimas studentu " << n << " " << elapsed.count() << " sekundes" << std::endl;
}