#include "Generavimasv21.h"
#include "Studentasv21.h"
#include "Skaiciavimasv21.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <iomanip>
#include <filesystem>
#include <chrono>
#include <io.h>
#include <sstream>
#include <numeric>
#include <algorithm>
#include <string>
#include <utility>

#include <regex>
#include <string>
using namespace std;

double a = 0.00000;
double b = 0.00000;
double c = 0.00000;
double d = 0.00000;
double g = 0.00000;
double u = 0.00000;

void VisoLaikas() {
    cout << a + b + c + g + d << " sekundes" << endl;
}

list<Studentas> skaitytiStudentus(int n) {
    auto starts = chrono::high_resolution_clock::now();
    string filename = "studentai" + to_string(n) + ".txt";
    ifstream in(filename, ios::in | ios::binary);
    if (!in) {
        cerr << "Klaida atidarant failà: " << filename << std::endl;
        return {};
    }

    list<Studentas> studentai;
    string eilute, vardas, pavarde;
    getline(in, eilute);

    while (in >> vardas >> pavarde) {
        vector<int> pazymiaiV(9);
        for (int& pazymys : pazymiaiV) {
            in >> pazymys;
        }
        double egzaminas;
        in >> egzaminas;

        Studentas studentas(vardas, pavarde, pazymiaiV, egzaminas);
        studentas.calculateVidurkis();
        ;
        studentai.push_back(move(studentas));
    }

    auto finishs = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finishs - starts;
    a += elapsed.count();
    cout << "Duomenu nuskaitymas " << n << " studentu: " << elapsed.count() << " sekundes" << std::endl;
    in.close();
    return studentai;
}


bool Vardo_lyginimas(const string& nameA, const string& nameB) {
    std::regex rgx("([a-zA-Z]+)([0-9]*)");
    std::smatch matchA, matchB;

    regex_search(nameA, matchA, rgx);
    regex_search(nameB, matchB, rgx);

    if (matchA[1].str() != matchB[1].str()) {
        return matchA[1].str() < matchB[1].str();
    }
    int numA = matchA[2].str().empty() ? 0 : stoi(matchA[2].str());
    int numB = matchB[2].str().empty() ? 0 : stoi(matchB[2].str());

    return numA < numB;
}

bool Pavardes_lyginimas(const string& nameA, const string& nameB) {
    std::regex rgx("([a-zA-Z]+)([0-9]*)");
    std::smatch matchA, matchB;

    regex_search(nameA, matchA, rgx);
    regex_search(nameB, matchB, rgx);

    if (matchA[1].str() != matchB[1].str()) {
        return matchA[1].str() < matchB[1].str();
    }
    int numA = matchA[2].str().empty() ? 0 : stoi(matchA[2].str());
    int numB = matchB[2].str().empty() ? 0 : stoi(matchB[2].str());

    return numA < numB;
}




void saveToFile(const list<Studentas>& studentasList, const string& filename, const string& choice1) {
    list<Studentas> sortedStudents = studentasList;
    auto start = chrono::high_resolution_clock::now();
    auto startSort = chrono::high_resolution_clock::now();

    if (choice1 == "vardus") {
        sortedStudents.sort([](const Studentas& a, const Studentas& b) {
            return Vardo_lyginimas(a.getVardas(), b.getVardas());
            });
    }
    else if (choice1 == "pavardes") {
        sortedStudents.sort([](const Studentas& a, const Studentas& b) {
            return Pavardes_lyginimas(a.getVardas(), b.getVardas());
            });
    }
    else if (choice1 == "vidurkius") {
        sortedStudents.sort([](const Studentas& a, const Studentas& b) {
            return a.getVidurkis() < b.getVidurkis(); // Changed to use getter
            });
    }

    auto finishSort = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsedSort = finishSort - startSort;
    g += elapsedSort.count();
    cout << "Sortinimas: " << elapsedSort.count() << " sekundes" << endl;

    ios::sync_with_stdio(false); // Padidinti  greitá 
    cin.tie(NULL);

    ofstream out(filename); // Failas atidaromas rasymui 
    if (!out) { // Tikrinimas del atidarymo 
        cerr << "Klaida atidarant failà raðymui: " << filename << endl;
        return;
    }

    out << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(15) << "Galutinis(Vid.)" << endl; // Isdestymas 
    for (const auto& studentas : sortedStudents) { // Spausdina visus studentus 
        out << setw(20) << studentas.getVardas() << setw(20) << studentas.getPavarde() << setw(15) << fixed << setprecision(2) << studentas.getVidurkis() << endl;
    }
    out.close();

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    b += elapsed.count();
    cout << "Isvesta " << studentasList.size() << " irasu i " << filename << ". Vykdymo laikas: " << elapsed.count() << " sekundziu." << endl;
}

void Generavimas(int n) {
    string filename = "studentai" + to_string(n) + ".txt";
    if (_access(filename.c_str(), 0) == 0) {//egzistavima trikina
        cout << "Failas " << filename << " jau egzistuoja." << endl;
        return;
    }

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
    c += elapsed.count();
    std::cout << "Generavimas studentu " << n << " " << elapsed.count() << " sekundes" << std::endl;
}



void Rusiuoti(std::list<Studentas>& studentai, std::list<Studentas>& vargsiukai, std::list<Studentas>& kietiakiai, char choice2) {
    using namespace std::chrono;
    auto startSorting = high_resolution_clock::now();

    if (choice2 == 's') {
        for (const auto& studentas : studentai) {
            if (studentas.getVidurkis() < 5.0) {
                vargsiukai.push_back(studentas);
            }
            else {
                kietiakiai.push_back(studentas);
            }
        }
    }
    else if (choice2 == 'd') {
        auto it = studentai.begin();
        while (it != studentai.end()) {
            if (it->getVidurkis() < 5.0) {
                vargsiukai.push_back(std::move(*it));
                it = studentai.erase(it);
            }
            else {
                ++it;
            }
        }
        kietiakiai.splice(kietiakiai.end(), studentai);
    }
    else if (choice2 == 'dt') {
        auto partitionPoint = std::stable_partition(studentai.begin(), studentai.end(),
            [](const Studentas& s) { return s.getVidurkis() >= 5.0; });

        vargsiukai.splice(vargsiukai.end(), studentai, studentai.begin(), partitionPoint);
        kietiakiai.splice(kietiakiai.end(), studentai);
    }
    else {
        std::cerr << "Neteisingas vartotojo pasirinkimas. Galimi variantai: 's', 'd' arba 'dt'." << std::endl;
        return;
    }

    auto finishSorting = high_resolution_clock::now();
    std::chrono::duration<double> elapsedSorting = finishSorting - startSorting;
    d += elapsedSorting.count();
    cout << "Rusiavimas: " << elapsedSorting.count() << " sekundes" << endl;
}


void RusiuotiV(std::vector<Studentas>& studentai, std::vector<Studentas>& vargsiukai, std::vector<Studentas>& kietiakiai, char choice2) {
    auto startSorting = std::chrono::high_resolution_clock::now();

    if (choice2 == 's') {
        for (const auto& studentas : studentai) {
            if (studentas.getVidurkis() < 5.0) {
                vargsiukai.push_back(studentas);
            }
            else {
                kietiakiai.push_back(studentas);
            }
        }
    }
    else if (choice2 == 'd') {
        auto it = std::stable_partition(studentai.begin(), studentai.end(),
            [](const Studentas& s) { return s.getVidurkis() >= 5.0; });
        vargsiukai.assign(std::make_move_iterator(it), std::make_move_iterator(studentai.end()));
        studentai.erase(it, studentai.end());
        kietiakiai.assign(std::make_move_iterator(studentai.begin()), std::make_move_iterator(studentai.end()));
    }
    else if (choice2 == 'dt') {
        auto it = std::partition(studentai.begin(), studentai.end(),
            [](const Studentas& s) { return s.getVidurkis() >= 5.0; });
        vargsiukai.assign(std::make_move_iterator(it), std::make_move_iterator(studentai.end()));
        kietiakiai.assign(std::make_move_iterator(studentai.begin()), std::make_move_iterator(it));
    }
    else {
        std::cerr << "Neteisingas vartotojo pasirinkimas. Galimi variantai: 's', 'd' arba 'dt'." << std::endl;
        return;
    }

    auto finishSorting = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedSorting = finishSorting - startSorting;
    d += elapsedSorting.count();
    std::cout << "Rusiavimas uþtruko: " << elapsedSorting.count() << " sekundes" << std::endl;
}


void saveToFileV(const std::vector<Studentas>& studentasList, const std::string& filename, const std::string& choice1) {
    std::vector<Studentas> sortedStudents = studentasList;
    auto startSort = std::chrono::high_resolution_clock::now();

    if (choice1 == "vardus") {
        sort(sortedStudents.begin(), sortedStudents.end(), [](const Studentas& a, const Studentas& b) {
            return a.getVardas() < b.getVardas();
            });
    }
    else if (choice1 == "pavardes") {
        sort(sortedStudents.begin(), sortedStudents.end(), [](const Studentas& a, const Studentas& b) {
            return a.getPavarde() < b.getPavarde(); 
            });
    }
    else if (choice1 == "vidurkius") {
        sort(sortedStudents.begin(), sortedStudents.end(), [](const Studentas& a, const Studentas& b) {
            return a.getVidurkis() < b.getVidurkis();
            });
    }

    auto finishSort = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedSort = finishSort - startSort;
    g += elapsedSort.count();
    std::cout << "Sortinimas: " << elapsedSort.count() << " sekundes" << std::endl;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ofstream out(filename);
    if (!out) {
        cerr << "Klaida atidarant failà raðymui: " << filename << endl;
        return;
    }

    out << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(15) << "Galutinis(Vid.)" << endl;
    for (const auto& studentas : studentasList) {
        out << setw(20) << studentas.getVardas() << setw(20) << studentas.getPavarde()
            << setw(15) << fixed << setprecision(2) << studentas.getVidurkis() << endl;
    }
    out.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - startSort; // Note: startSort used here for consistency
    b += elapsed.count();
    std::cout << "Isvesta " << studentasList.size() << " irasu i " << filename << ". Vykdymo laikas: " << elapsed.count() << " sekundziu." << std::endl;
}

vector<Studentas> skaitytiStudentusV(int n) {
    auto starts = chrono::high_resolution_clock::now();
    string filename = "studentai" + to_string(n) + ".txt";
    ifstream in(filename, ios::in | ios::binary);
    if (!in) {
        cerr << "Klaida atidarant failà: " << filename << std::endl;
        return {};
    }

    vector<Studentas> studentai;
    studentai.reserve(n);

    string eilute;
    getline(in, eilute);

    string vardas, pavarde;
    double egzaminas;
    vector<int> pazymiaiV(9);

    while (in >> vardas >> pavarde) {
        vector<int> pazymiaiV(9);
        for (int& pazymys : pazymiaiV) {
            in >> pazymys;
        }
        double egzaminas;
        in >> egzaminas;

        Studentas studentas(vardas, pavarde, pazymiaiV, egzaminas);
        studentas.calculateVidurkis();
        studentas.calculateMediana();

        studentai.emplace_back(studentas);        // studentai.emplace_back(move(studentas));
    }

    auto finishs = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finishs - starts;
    a += elapsed.count();
    cout << "Duomenu nuskaitymas " << n << " studentu: " << elapsed.count() << " sekundes" << std::endl;
    in.close();
    return studentai;
}