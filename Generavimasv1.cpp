#include "Generavimasv1.h"
#include "Studentasv1.h"
#include "Skaiciavimasv1.h"
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
#include <iostream>
#include <string>
#include <utility>
using namespace std;


double a = 0.00000;
double b = 0.00000;
double c = 0.00000;
double d = 0.00000;
double g = 0.00000;
double u = 0.00000;

void VisoLaikas() {
    cout << a + b + c + g+ d << " sekundes" << endl;
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

    string eilute;
    getline(in, eilute);

    Studentas studentas;
    while (in >> studentas.vardas >> studentas.pavarde) {
        for (int i = 0; i < 9; i++) {
            int temp;
            in >> temp;
            studentas.pazymiai.push_back(temp);
        }

        in >> studentas.egzaminas;
        studentas.vidurkis = calculateVidurkis(studentas.pazymiai);
        studentas.vidurkis = 0.40 * studentas.vidurkis + 0.60 * studentas.egzaminas;
        studentai.push_back(move(studentas));
        studentas.pazymiai.clear();
    }

    auto finishs = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finishs - starts;
    a += elapsed.count();
    cout << "Duomenu nuskaitymas " << n << " studentu: " << elapsed.count() << " sekundes" << std::endl;
    in.close();
    return studentai;
}

void saveToFile(const list<Studentas>& studentasList, const string& filename, const string& choice1) {
    list<Studentas> sortedStudents = studentasList;
    auto start = chrono::high_resolution_clock::now();
    auto startSort = chrono::high_resolution_clock::now();

    if (choice1 == "vardus") {
        sortedStudents.sort([](const Studentas& a, const Studentas& b) {
            int vardass = std::stoi(a.vardas.substr(6)); //nuo septinto, tai yra 8 elemento 
            int vardas = std::stoi(b.vardas.substr(6));
            return vardass < vardas;
            });
    }
    else if (choice1 == "pavardes") {
        sortedStudents.sort([](const Studentas& a, const Studentas& b) {
            int numA = std::stoi(a.pavarde.substr(7)); //nuo septinto, tai yra 8 elemento 
            int numB = std::stoi(b.pavarde.substr(7));
            return numA < numB;
            });
    }
    else if (choice1 == "vidurkius") {
        sortedStudents.sort([](const Studentas& a, const Studentas& b) {
            return a.vidurkis < b.vidurkis;
            });
    }

    auto finishSort = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedSort = finishSort - startSort;
    g += elapsedSort.count();
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


double calculateVidurkis(const list<int>& nums) {
    return static_cast<double>(std::accumulate(nums.begin(), nums.end(), 0)) / nums.size();
}

double calculateMedian(const list<int>& grades) {
    list<int> sortedGrades = grades;
    sortedGrades.sort();  

    auto it = sortedGrades.begin(); 
    advance(it, grades.size() / 2);

    if (grades.size() % 2 == 0) {
        return (static_cast<double>(*prev(it)) + *it) / 2.00;
    }
    else {
        return *it;
    }
}

void Rusiuoti(std::list<Studentas>& studentai, std::list<Studentas>& vargsiukai, std::list<Studentas>& kietiakiai, char choice2) {
    using namespace std::chrono;
    auto startSorting = high_resolution_clock::now();

    if (choice2 == 's') {
        for (const auto& studentas : studentai) {
            if (studentas.vidurkis < 5.0) {
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
            if (it->vidurkis < 5.0) {
                vargsiukai.push_back(std::move(*it));
                it = studentai.erase(it);
            }
            else {
                ++it;
            }
        }
        kietiakiai.splice(kietiakiai.end(), studentai);
    }
    else if  (choice2 == 'dt') {
        auto partitionPoint = std::stable_partition(studentai.begin(), studentai.end(),
            [](const Studentas& s) { return s.vidurkis >= 5.0; });

        vargsiukai.splice(vargsiukai.end(), studentai, studentai.begin(), partitionPoint);

        kietiakiai.splice(kietiakiai.end(), studentai);
    }
    else {
        std::cerr << "Neteisingas vartotojo pasirinkimas. Galimi variantai: 's' arba 'd'." << std::endl;
        return;
    }

    auto finishSorting = high_resolution_clock::now();
    std::chrono::duration<double> elapsedSorting = finishSorting - startSorting;
    d += elapsedSorting.count();
    std::cout << "Rusiavimas "<< ": " << elapsedSorting.count() << " sekundes" << std::endl;
}



void RusiuotiV(std::vector<Studentas>& studentai, std::vector<Studentas>& vargsiukai, std::vector<Studentas>& kietiakiai, char choice2) {
    auto startSorting = std::chrono::high_resolution_clock::now();

    if (choice2 == 's') {
        // Simple split based on average
        for (const auto& studentas : studentai) {
            if (studentas.vidurkis < 5.0) {
                vargsiukai.push_back(studentas);
            }
            else {
                kietiakiai.push_back(studentas);
            }
        }
    }
    else if (choice2 == 'd') {
        auto it = std::stable_partition(studentai.begin(), studentai.end(), [](const Studentas& s) {
            return s.vidurkis >= 5.0;
            });
        vargsiukai.assign(std::make_move_iterator(it), std::make_move_iterator(studentai.end()));
        studentai.erase(it, studentai.end()); 
        kietiakiai.assign(std::make_move_iterator(studentai.begin()), std::make_move_iterator(studentai.end()));
        studentai.clear(); 
    }
    else if (choice2 == 'dt') {
        
        auto it = std::partition(studentai.begin(), studentai.end(), [](const Studentas& s) {
            return s.vidurkis >= 5.0;
            });
        vargsiukai.assign(std::make_move_iterator(it), std::make_move_iterator(studentai.end()));
        kietiakiai.assign(std::make_move_iterator(studentai.begin()), std::make_move_iterator(it));
        studentai.clear();
    }
    else {
        
        std::cerr << "Neteisingas vartotojo pasirinkimas. Galimi variantai: 's', 'd' arba 'dt'." << std::endl;
        return;
    }

    auto finishSorting = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedSorting = finishSorting - startSorting;
    // Assuming 'd' is a variable previously defined to accumulate durations
    d += elapsedSorting.count();
    std::cout << "Rusiavimas uþtruko: " << elapsedSorting.count() << " sekundes" << std::endl;
}


double calculateVidurkisV(const std::vector<int>& nums) {
    return static_cast<double>(std::accumulate(nums.begin(), nums.end(), 0)) / nums.size();
}

double calculateMedianV(const vector<int>& grades) {
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
void saveToFileV(const std::vector<Studentas>& studentasList, const std::string& filename, const std::string& choice1) {
    std::vector<Studentas> sortedStudents = studentasList;
    auto start = std::chrono::high_resolution_clock::now();
    auto startSort = std::chrono::high_resolution_clock::now(); // Start the sort timer
    if (choice1 == "vardus") {
        sort(sortedStudents.begin(), sortedStudents.end(),
            [](const Studentas& a, const Studentas& b) {
                int vardass = std::stoi(a.vardas.substr(6)); //nuo septinto, tai yra 8 elemento 
                int vardas = std::stoi(b.vardas.substr(6));
                return vardass < vardas;
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
    g += elapsedSort.count();//laikui skaiciuoti 
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

vector<Studentas> skaitytiStudentusV(int n) {
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
        studentas.pazymiaiV.resize(9);//9 vietos vektorius 
        for (int i = 0; i < 9; i++) {//skaito 9 pazymius
            in >> studentas.pazymiaiV[i];
        }

        in >> studentas.egzaminas;//skaito egzo pazymi 
        studentas.vidurkis = calculateVidurkisV(studentas.pazymiaiV);
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