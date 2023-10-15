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
#include <sstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <string>




using namespace std;

namespace fs = std::filesystem;


void saveToFile(const std::vector<Studentas>& studentasList, const std::string& filename, const std::string& choice1) {
    std::vector<Studentas> sortedStudents = studentasList;

    if (choice1 == "vardus") {
        std::sort(sortedStudents.begin(), sortedStudents.end(), 
                  [](const Studentas& a, const Studentas& b) {
                      return a.vardas < b.vardas;
                  });
    } else if (choice1 == "pavardes") {
        std::sort(sortedStudents.begin(), sortedStudents.end(),
            [](const Studentas& a, const Studentas& b) {
                // Iðtraukiame skaièius ið pavardës
                int numA = std::stoi(a.pavarde.substr(7)); // 7 nes praleidþiame "Pavarde"
                int numB = std::stoi(b.pavarde.substr(7));
                return numA < numB;
            });
    } else if (choice1 == "vardus") {
        std::sort(sortedStudents.begin(), sortedStudents.end(),
            [](const Studentas& a, const Studentas& b) {
                // Iðtraukiame skaièius ið vardo
                int numA = std::stoi(a.vardas.substr(6)); // 6 nes praleidþiame "Vardas"
                int numB = std::stoi(b.vardas.substr(6));
                return numA < numB;
            });
    }
    std::ios::sync_with_stdio(false); // Iðjungti sinchronizacijà
    cin.tie(NULL); // Iðjungti ryðá tarp cin ir cout

    auto start = std::chrono::high_resolution_clock::now();

    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Klaida atidarant failà raðymui: " << filename << std::endl;
        return;
    }

    out << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde";
    for (int i = 1; i <= 9; i++) {
        out << std::setw(7) << "ND" + std::to_string(i);
    }
    out << std::setw(11) << "Egz." << " Galutinis(Vid.)" << std::endl;

    for (const auto& studentas : sortedStudents) {
        out << std::setw(20) << studentas.vardas << std::setw(20) << studentas.pavarde;
        for (int grade : studentas.pazymiai) {
            out << std::setw(7) << grade;
        }
        out << std::setw(11) << studentas.egzaminas << " " << studentas.vidurkis << std::endl;
    }

    out.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Isvesta " << studentasList.size() << " irasu i " << filename << ". Vykdymo laikas: " << elapsed.count() << " sekundziu." << std::endl;
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



double calculateVidurkis(const std::vector<int>& nums) {
    return static_cast<double>(std::accumulate(nums.begin(), nums.end(), 0)) / nums.size();
}

double calculateMedian(const vector<int>& grades) {
    vector<int> sortedGrades = grades;
    sort(sortedGrades.begin(), sortedGrades.end());

    size_t size = sortedGrades.size();
    if (size % 2 == 0) {
        return (static_cast<double>(sortedGrades[size / 2 - 1]) + sortedGrades[size / 2]) / 2.00;
    }
    else {
        return sortedGrades[size / 2];
    }
}


void Rusiuoti(const std::vector<Studentas>& studentai,
    std::vector<Studentas>& vargsiukai,
    std::vector<Studentas>& kietiakiai) {

    auto startSorting = std::chrono::high_resolution_clock::now();

    for (auto& studentas : studentai) {
        if (studentas.vidurkis < 5.0) {
            vargsiukai.push_back(std::move(studentas));
        }
        else {
            kietiakiai.push_back(std::move(studentas));
        }
    }

    auto finishSorting = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedSorting = finishSorting - startSorting;
    cout << "Duomenu rusiavimas: " << elapsedSorting.count() << " sekundes" << std::endl;
}

