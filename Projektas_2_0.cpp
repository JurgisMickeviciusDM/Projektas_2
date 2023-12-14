#include "studentas20.h"
#include <fstream>
#include <chrono>
#include <iostream>
#include <limits>
#include <string>
#include <list>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <numeric>

#include "Generavimas20.h"

using namespace std;
void Generavimas(int n);
void naudotojas(string& inputMethod, string& choice, string& header1, string& header2, string& choice1, string& choice2);
void VisoLaikas();
void saveToFileV(const vector<Studentas>& studentasList, const string& filename, const string& choice1);
void RusiuotiV(std::vector<Studentas>& studentai, std::vector<Studentas>& vargsiukai, std::vector<Studentas>& kietiakiai, char choice2);
vector<Studentas> skaitytiStudentusV(int n);

int main() {




    {
        Studentas* studentas0 = new Studentas("Jurgis", "Mickevicius", { 5, 7, 8 }, 9); //vardas, pavarde, pazymiai ir egzaminas 
        delete studentas0;
        std::cout << "Destruktorius  ivykdyta" << std::endl;

    }

    // Demonstravimas: COPY Konstruktorius
    Studentas studentas1("Jurgis", "Mickevicius", { 6, 8, 9 }, 10);
    Studentas studentasKopija = studentas1;
    std::cout << "Kopijos konstruktorius: " << studentasKopija << std::endl;

    // Demonstravimas: Priskyrimo operatorius
    Studentas studentas2("Jurgis", "Mickevicius", { 7, 8, 9 }, 8);
    Studentas studentasPriskyrimui;
    studentasPriskyrimui = studentas2;
    std::cout << "Priskyrimo operatorius: " << studentasPriskyrimui << std::endl;



    /*
     Zmogus laikinas;  //negalima sukurti abstrakti klase parodome, kad taip negalima, nes meta kalida uzkoemntavus jau viskas gerai veikia

      laikinas.setVardas("Jurgis");
      laikinas.setPavarde("Mickevicius");
      laikinas.informacija();
      cout << "-------------------" << endl;
      */

    Studentas laikinas1; //galima nes is isvestines 

    laikinas1.setVardas("Jurgis");
    laikinas1.setPavarde("Mickevicius");
    laikinas1.informacija();
    cout << "-------------------" << endl;


    srand(static_cast<unsigned int>(time(0)));


    string inputMethod, choice, choice1, choice2;

    naudotojas(inputMethod, choice, choice1, choice2);
    char sortChoice = choice2.empty() ? ' ' : choice2[0];
    int skaicius = 0;
    vector<Studentas> studentai;

    if (inputMethod == "auto") {


        std::vector<int> studentuSkaiciai = { 1000, 10000, 100000 };
        for (int n : studentuSkaiciai) {
            Generavimas(n);
        }

        for (int n : studentuSkaiciai) {
            studentai = skaitytiStudentusV(n);
            std::vector<Studentas> vargsiukai;
            std::vector<Studentas> kietiakiai;
            vargsiukai.reserve(n);
            kietiakiai.reserve(n);

            RusiuotiV(studentai, vargsiukai, kietiakiai, sortChoice);
            std::string vargsiukaiFilename = "vargsiukai_" + choice + std::to_string(n) + ".txt";
            std::string kietiakiaiFilename = "kietiakiai_" + choice + std::to_string(n) + ".txt";

            saveToFileV(vargsiukai, vargsiukaiFilename, choice1);
            saveToFileV(kietiakiai, kietiakiaiFilename, choice1);
            std::cout << "____________________" << std::endl;
            std::cout << n << " studentu laikas visos programos: " << std::endl;
            VisoLaikas();
            std::cout << "____________________" << std::endl;
        }
    }

    else if (inputMethod == "duomenys") {
        ifstream file;
        string filename = "studentai1000.txt";

        do {
            file.open(filename);
            if (!file) {
                cerr << "Nepavyko atidaryti failo '" << filename << "'. Prasome ivesti nauja failo pavadinima: ";
                cin >> filename;
            }
        } while (!file);

        string headerLine;
        getline(file, headerLine);
        istringstream headerStream(headerLine);
        string word;
        vector<string> headers;
        while (headerStream >> word) {
            headers.push_back(word);
        }

        int ndCount = static_cast<int>(headers.size()) - 3;
        vector<Studentas> studentai;

        string vardas, pavarde;
        while (file >> vardas >> pavarde) {
            Studentas s;
            s.setVardas(vardas);
            s.setPavarde(pavarde);

            vector<int> pazymiaiV;
            string gradeStr;
            for (int i = 0; i < ndCount; i++) {
                file >> gradeStr;
                if (isdigit(gradeStr[0])) {
                    pazymiaiV.push_back(stoi(gradeStr));
                }
            }
            s.setPazymiaiV(pazymiaiV);

            double egzaminas;
            file >> egzaminas;
            s.setEgzaminas(egzaminas);

            s.calculateVidurkis();


            studentai.push_back(s);
        }
        file.close();

        //  virsutine eilute
        cout << setw(20) << left << "Pavarde"
            << setw(20) << left << "Vardas"
            << setw(20) << left << "Galutinis(vid.)" << '\n';

        // outputas
        for (const auto& studentas : studentai) {
            std::cout << studentas << std::endl;
        }
    }


    else if (inputMethod == "ranka") {
        int skaicius;
        cout << "Pasirinkite norima skaiciu studentu. Iveskite ju skaiciu(naudoti tik skaicius): ";
        while (!(cin >> skaicius) || skaicius <= 0) {
            cout << "Neteisingai ivedete skaiciu, pakartokite norima skaiciu ivesdami skaitmenis: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        vector<Studentas> studentai;
        studentai.reserve(skaicius);

        for (int j = 0; j < skaicius; j++) {
            Studentas s;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Iveskite " << j + 1 << "-ojo studento/studentes duomenis." << endl;
            cin >> s;
            studentai.push_back(s);
        }

        // virsutine eilute 
        cout << setw(20) << left << "Pavarde"
            << setw(20) << left << "Vardas"
            << setw(20) << left << "Galutinis(vid.)" << '\n';


        // outputas
        for (const auto& studentas : studentai) {
            std::cout << studentas << std::endl;
        }
    }

    cout << "Atlikta" << endl;

    return 0;
}
