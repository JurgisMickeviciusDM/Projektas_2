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

double a = 0.00000;
double b = 0.00000;
double c = 0.00000;
double d = 0.00000;


void VisoLaikas() {
    cout <<  a+b+c+d << " sekundes" << endl;//laiko funkcija visos programos
}



vector<Studentas> skaitytiStudentus(int n) {
    auto starts = chrono::high_resolution_clock::now();//pradinis laikas fiksas 
    string filename = "studentai" + to_string(n) + ".txt";//failo pavadinimas
    ifstream in(filename, ios::in | ios::binary);
    if (!in) {
        cerr << "Klaida atidarant failà: " << filename << std::endl;
        return {};  
    }

    vector<Studentas> studentai;
    studentai.reserve(n);//rezervuoja, kiek yra n studentu vietos 

    string eilute;
    getline(in, eilute);

    Studentas studentas;
    while (in >> studentas.vardas >> studentas.pavarde) { //Skaito studento vardà ir pavardæ
        studentas.pazymiai.resize(9);//9 vietos vektorius 
        for (int i = 0; i < 9; i++) {//skaito 9 pazymius
            in >> studentas.pazymiai[i];
        }

        in >> studentas.egzaminas;//skaito egzo pazymi 
        studentas.vidurkis = calculateVidurkis(studentas.pazymiai);
        studentas.vidurkis = 0.40 * studentas.vidurkis + 0.60 * studentas.egzaminas;
        studentai.emplace_back(move(studentas));//studento data ideda i vektoriu 

    }
    auto finishs = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finishs - starts;
    a += elapsed.count();//laikui skaiciuoti 
    cout << "Duomenu nuskaitymas " << n << " studentu: " << elapsed.count() << " sekundes" << std::endl;
    in.close();
    return studentai;
}



void saveToFile(const std::vector<Studentas>& studentasList, const std::string& filename, const std::string& choice1) {
    std::vector<Studentas> sortedStudents = studentasList;
    auto start = std::chrono::high_resolution_clock::now();
    auto startSort = std::chrono::high_resolution_clock::now(); // Start the sort timer
    if (choice1 == "vardus") {
        sort(sortedStudents.begin(), sortedStudents.end(),
            [](const Studentas& a, const Studentas& b) {
                 return a.vardas < b.vardas;


            });
    }
    else if (choice1 == "pavardes") {
        sort(sortedStudents.begin(), sortedStudents.end(),
            [](const Studentas& a, const Studentas& b) {
                int numA = std::stoi(a.pavarde.substr(7));//nuo septinto, tai yra 8 elemento 
                int numB = std::stoi(b.pavarde.substr(7));
                return numA < numB;
            });
    }
    else if (choice1 == "vidurkius") {
        sort(sortedStudents.begin(), sortedStudents.end(),
            [](const Studentas& a, const Studentas& b) {
                return a.vidurkis < b.vidurkis;
            });
    
    }
    auto finishSort = std::chrono::high_resolution_clock::now(); 
    std::chrono::duration<double> elapsedSort = finishSort - startSort;
    std::cout << "Sortinimas: " << elapsedSort.count() << " sekundes" << std::endl; 

    ios::sync_with_stdio(false); //// Padidinti  greitá 
    cin.tie(NULL);

    ofstream out(filename);//faials atidaromas rasymui 
    if (!out) {//tikrinimas del atidarymo 
        cerr << "Klaida atidarant failà raðymui: " << filename << endl;
        return;
    }
    

    out << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(15) << "Galutinis(Vid.)" << endl;// isdestymas 
    for (const auto& studentas : sortedStudents) {//spasudina visus studentus 
        out << setw(20) << studentas.vardas << setw(20) << studentas.pavarde << setw(15) << fixed << setprecision(2) << studentas.vidurkis << endl;
    }
    out.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    b += elapsed.count();
    std::cout << "Isvesta " << studentasList.size() << " irasu i " << filename << ". Vykdymo laikas: " << elapsed.count() << " sekundziu." << std::endl;
}



void Generavimas(int n) {
    

    string filename = "studentai" + to_string(n) + ".txt";
    if (_access(filename.c_str(), 0) == 0) {//egzistavima trikina
        cout << "Failas " << filename << " jau egzistuoja." << endl;
        return;  }

    ofstream out(filename);
    if (!out) {//ar atsidaro gerai 
        cerr << "Klaida atidarant failà rasymui: " << filename << endl;
        return;
    }
    auto start = chrono::high_resolution_clock::now();

    out << left << setw(20) << "Vardas" << setw(20) << "Pavarde";// antarste 
    for (int i = 1; i <= 9; i++) {
        out << setw(7) << "ND" + to_string(i);
    }
    out << setw(11) << "Egz." << endl;

    for (int i = 1; i <= n; i++) {
        out << setw(20) << "Vardas" + to_string(i) << setw(20) << "Pavarde" + to_string(i);
        for (int j = 0; j < 9; j++) {
            out << setw(7) << rand() % 10 + 1;
        }
        out << setw(11) << rand() % 10 + 1 << endl;//random pakeisti 
    }

    out.close();

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    c+= elapsed.count();
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
    d += elapsedSorting.count();
    cout << "Duomenu rusiavimas: " << elapsedSorting.count() << " sekundes" << std::endl;
}
