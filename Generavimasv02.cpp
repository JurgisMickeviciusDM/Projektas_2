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
#include <sstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <string>




using namespace std;

namespace fs = std::filesystem;

/*void saveToFile(const vector<Studentas>& studentas, const string& filename) {

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
} */

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

void saveToFile(const vector<Studentas>& studentai, const string& filename) {
    auto start = std::chrono::high_resolution_clock::now();

    //stringstream ss;
    //ss.reserve(studentai.size() * 200);  


    std::string preallocated;
    preallocated.reserve(studentai.size() * 140);
    stringstream ss(preallocated);

    ss << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
    for (int i = 1; i <= 9; i++) {
        ss << setw(7) << "ND" + to_string(i);
    }
    ss << setw(11) << "Egz." << " Galutinis(Vid.)\n";

    for (const auto& studentas : studentai) {
        ss << setw(20) << studentas.vardas << setw(20) << studentas.pavarde;
        for (int grade : studentas.pazymiai) {
            ss << setw(7) << grade;
        }
        ss << setw(11) << studentas.egzaminas << " " << studentas.vidurkis << "\n";
    }

    
    ofstream out(filename);
    if (!out) {
        cerr << "Klaida atidarant failà raðymui: " << filename << endl;
        return;
    }

 
    const size_t bufSize = 1 << 16;  
    char buf[bufSize];
    out.rdbuf()->pubsetbuf(buf, bufSize);

    out << ss.str();

    out.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "Isvesta " << studentai.size() << " irasu i " << filename << ". Vykdymo laikas: " << elapsed.count() << " sekundziu." << endl;
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