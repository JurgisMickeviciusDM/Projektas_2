﻿#include "studentasv02.h"
#include "Skaiciavimasv02.h"
#include <fstream>
#include <chrono>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <numeric>
#include "Naudotojasv02.h"
#include "Generavimasv02.h"
#include <io.h>




using namespace std;

void saveToFile(const std::vector<Studentas>& studentasList, const std::string& filename, const std::string& choice1);
void Generavimas(int n);
void Rusiuoti(const std::vector<Studentas>& studentai, std::vector<Studentas>& vargsiukai, std::vector<Studentas>& kietiakiai);
void naudotojas(string& inputMethod, string& choice, string& header1, string& header2, string& choice1);

int main() {
    srand(static_cast<unsigned int>(time(0)));
    string header1, header2, choice, inputMethod, choice1;  //kintamieji
    naudotojas(inputMethod, choice, header1, header2, choice1);//naudotojo funkcija
    vector<Studentas> studentai; //vektorius

    int skaicius = 0;
    auto startvisogalutinis = chrono::high_resolution_clock::now();
    if (inputMethod == "auto") {
        cout << "Vidurkiai 5 paleidimu programos:";
        cout << "Bendras laikas 1000 studentu: 0,0954 sek " << endl;
        cout << "Bendras laikas 10000 studentu: 0,64574 sek " << endl;
        cout << "Bendras laikas 100000 studentu: 9,8954 sek " << endl;
        cout << "Bendras laikas 1000000 studentu: 66,1087 sek " << endl;
        cout << "Bendras laikas 10000000 studentu: 772,3214 sek " << endl;
        
        vector<int> studentuSkaiciai = {1000, 10000, 100000, 1000000, 10000000};
            for (int n : studentuSkaiciai) {
                Generavimas(n);
        }
            for (int n : studentuSkaiciai) {
                auto startviso = chrono::high_resolution_clock::now();
                auto start = chrono::high_resolution_clock::now();

                string filename = "studentai" + std::to_string(n) + ".txt";
                ifstream in(filename, std::ios::in | std::ios::binary); 
                if (!in) {
                    std::cerr << "Klaida atidarant failą: " << filename << std::endl;
                    continue;
                }

                vector<Studentas> studentai;
                studentai.reserve(n);

                string eilute;
                getline(in, eilute); 

                string vardas, pavarde;
                int pazymys, egzaminas;

                while (in >> vardas >> pavarde) {
                    Studentas studentas;
                    studentas.vardas = std::move(vardas);
                    studentas.pavarde = std::move(pavarde);
                    studentas.pazymiai.resize(9);

                    for (int i = 0; i < 9; i++) {
                        in >> pazymys;
                        studentas.pazymiai[i] = pazymys;
                    }

                    in >> egzaminas;
                    studentas.egzaminas = egzaminas;

                    studentas.vidurkis = calculateVidurkis(studentas.pazymiai);
                    studentai.emplace_back(std::move(studentas));
                }

                auto finish = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed = finish - start;
                std::cout << "Duomenu nuskaitymas " << n << " studentu: " << elapsed.count() << " sekundes" << std::endl;

                in.close();


            vector<Studentas> vargsiukai;
            vector<Studentas> kietiakiai;
            vargsiukai.reserve(n); 
            kietiakiai.reserve(n);
            
            Rusiuoti(studentai, vargsiukai, kietiakiai);
            string vargsiukaiFilename = "vargsiukai_" + choice + to_string(n) + ".txt";
            string kietiakiaiFilename = "kietiakiai_" + choice + to_string(n) + ".txt";

            saveToFile(vargsiukai, vargsiukaiFilename, choice1);
            saveToFile(kietiakiai, kietiakiaiFilename, choice1);

        auto finishviso =chrono::high_resolution_clock::now(); 
        chrono::duration<double> elapsedviso = finishviso - startviso;
        cout << "________________________________________________________ " << endl;
        cout << "Bendras laikas " << n << "studnetu: " << elapsedviso.count() << " sekundes" << endl;
        cout << "________________________________________________________" << endl;
        }
    }

    else if (inputMethod == "duomenys") {

        ifstream file;// Sukuriamas įvesties srautas failo skaitymui.
        string filename = "studentai100000.txt";  // failo vardas SKAITOMO

        do {
            file.open(filename);
            if (!file) {
                cerr << "Nepavyko atidaryti failo '" << filename << "'. Prasome ivesti nauja failo pavadinima: ";
                cin >> filename;  // naujas pavadinimas
            }
        } while (!file);  //kol atidarys, tai yra nebus fialo

        // readina headeri i eilute
        string headerLine;
        getline(file, headerLine); // // Nuskaitome pirmą failo eilutę - antraštinę eilutę.
        istringstream headerStream(headerLine);   // Sukuriamas srautas, PADES skaityti antraštinės eilutės duomenis.
        string word;//kintamasisi laikomas zodis atskirai
        vector<string> headers;//verktor string tipo ir pavadinimas 
        while (headerStream >> word) {  // Skaidome antraštinę eilutę į atskirus žodžius ir dedame juos į 'headers' vektorių.
            headers.push_back(word); //zodis pridedamas prie header naudojant psuh back metoda, kai konteineris +1 i pabaiga 
        }

        int ndCount = static_cast<int>(headers.size()) - 3;// Minus Vardas, Pavarde, ir Egzaminas skaiciuoja nd kieki 

        //duomenu skaitymas 
        Studentas s;//student clas ir s objektas saugoti duomenis
        while (file >> s.vardas >> s.pavarde) {// sakito varda ir pavarde 
            string gradeStr;
            for (int i = 0; i < ndCount; i++) { // vykdys tiek kiek nd
                file >> gradeStr; // Nuskaitomas  pažymys.
                try {
                    int grade = stoi(gradeStr);// su stoi i sveik konvertuoojam, jei netai invalid  
                    s.pazymiai.push_back(grade);/// ok prides prie stud paz sar
                }
                catch (const std::invalid_argument& e) {
                    //jei konvertavimas nepavyksta tai su catch pagauname ir tesiame su kitais pazymiais darba
                    // Ignoruojame netinkamą pažymį, bet skaitymą tęsiame toliau
                    continue;
                }

            }
            int egzaminas;
            file >> egzaminas; //egzo pazymis is failo skaitomas

            if (choice == "vidurkis" || choice == "abu") {
                double vidurkis = calculateVidurkis(s.pazymiai);

                s.vidurkis = 0.40 * vidurkis + 0.60 * egzaminas;
            }
            if (choice == "mediana" || choice == "abu") {

                double mediana = calculateMedian(s.pazymiai);
                s.mediana = 0.40 * mediana + 0.60 * egzaminas;
            }

            studentai.push_back(s); //data pridedame prie studentai vektoriuas
            s.pazymiai.clear(); //studento namų darbų pažymiai yra išvalomI
        }

        file.close();
    }
    else if (inputMethod == "ranka") {
        cout << "Pasirinkite norima skaiciu studentu. Iveskite ju skaiciu(naudoti tik skaicius): ";
        while (!(cin >> skaicius) || skaicius <= 0) {//jei - 1 ar kita reiskme tai reiks per nauaj vesti
            cout << "Neteisingai ivedete skaiciu, pakartokite norima skaiciu ivesdami skaitmenis ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');//pasaliname kituselementus 
        }
    }

    for (int j = 0; j < skaicius; j++) { ////pagal ivesta skaiciu bus tiek kartojama 
        Studentas s;
        vector<int> pazymiai;
        int suma = 0;

        do {
            cout << "Iveskite " << j + 1 << "-ojo studento/studentes varda (tik raides): ";
            cin >> s.vardas;
        } while (!all_of(s.vardas.begin(), s.vardas.end(), ::isalpha)); // neabėcėlinis simbolis per nauja vesti

        do {
            cout << "Iveskite " << j + 1 << "-ojo studento/studentes pavarde (tik raides): ";
            cin >> s.pavarde;
        } while (!all_of(s.pavarde.begin(), s.pavarde.end(), ::isalpha));

        bool validChoice = false;

        string autoGenChoice;

        while (!validChoice) {//KOL TEISINGA 
            cout << "Ar norite, kad " << j + 1 << "-ojo studento pazymiai butu generuojami atsitiktinai? (taip/ne): ";
            cin >> autoGenChoice; //taip ne kintamaisis saugomas

            if (autoGenChoice == "taip") {
                int pazymiuKiekis = rand() % 10 + 1; //atsitikitnai generuojamas kiekis pazymiu 1-10
                for (int k = 0; k < pazymiuKiekis; k++) {
                    int pazymys = rand() % 10 + 1; //atsitiktinai nuo 1-10, pradeda 0 tad +1
                    pazymiai.push_back(pazymys);//prideda prie pazymiu saraso
                    suma += pazymys;//sumuoja pazymius
                }
                validChoice = true;//jei teisnga nutrauks 
            }
            else if (autoGenChoice == "ne") {
                validChoice = true;
            }
            else {
                cout << "Neteisinga pasirinkimas! Bandykite dar karta." << endl;
            }
        }
        bool klaida; // 1 arba 0
        do { // tol kol nera klaidu 
            klaida = false;

            if (autoGenChoice == "ne") {
                cout << "Iveskite " << j + 1 << "-ojo studento pazymius (desimtbale sistema) ir spauskite ENTER 2x, kad baigtumete ivedima:" << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');// ignoruos kol maks pasieks 
                string input;
                while (getline(cin, input) && !input.empty()) {//isvestis skaitoma, kol netsucia 2x enter
                    try {
                        int pazymys = stoi(input);//konvertuioja i sveika sk, jei ne tai invalid 
                        if (pazymys >= 1 && pazymys <= 10) { //tikrinns ar tarp 1-10 ir prides saraso ir sumos 
                            pazymiai.push_back(pazymys);
                            suma += pazymys;
                        }
                    }
                    catch (const invalid_argument&) { //isimtis ties stoi imetama, tyai catch pahauna
                        cout << "Neteisinga ivesta. Prasome ivesti pazymi nuo 1 iki 10: ";
                        klaida = true;
                        break;
                    }
                }
            }

        } while (klaida); // vyks kol bus klaidu 

        int egzaminas;
        if (autoGenChoice == "taip") {
            egzaminas = rand() % 10 + 1;  //generuos
        }
        else {
            bool validEgzaminas = false;
            while (!validEgzaminas) {
                cout << "iveskite " << j + 1 << "-ojo studento egzamino rezultata nuo 1 iki 10:" << endl;
                if (cin >> egzaminas) {
                    if (egzaminas >= 1 && egzaminas <= 10) {
                        validEgzaminas = true;
                    }
                }
                else {
                    cout << "Neteisinga ivesta. Prasome ivesti egzamino pazymi nuo 1 iki 10." << endl;
                    cin.clear();// atlaisvinamas ivedimas
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');// ignor kad nebuut nesusipratimu tolimesni element 
                }
            }
        }

        if (choice == "vidurkis" || choice == "abu") {

            double vidurkis = calculateVidurkis(pazymiai);
            s.vidurkis = 0.40 * vidurkis + 0.60 * egzaminas;
        }

        if (choice == "mediana" || choice == "abu") {

            double mediana = calculateMedian(pazymiai);// funkciaj is pazymiu saraso
            s.mediana = 0.40 * mediana + 0.60 * egzaminas;
        }

        studentai.push_back(s);//prideda prie studentu saraso 
    }

    auto compareFromFile = [](const Studentas& a, const Studentas& b) {
        int numA = stoi(a.pavarde.substr(7));
        int numB = stoi(b.pavarde.substr(7));
        return numA < numB;
        };

    //auto simpleCompare = [](const Studentas& a, const Studentas& b) {
   //     return a.pavarde < b.pavarde;
    //    };

    if (inputMethod == "duomenys") {

        sort(studentai.begin(), studentai.end(), compareFromFile);
    }
    else {
        sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
            return a.pavarde < b.pavarde;
            });
    }

    cout << fixed << setprecision(2);// 2 sk po kablelio 
    if (inputMethod == "duomenys" && inputMethod=="ranka") {
    cout << setw(20) << left << "pavarde"
        << setw(20) << left << "vardas";

    if (choice == "vidurkis" || choice == "abu") {
        cout << setw(20) << left << "Galutinis(vid.)"; // 20 zenklu suteikaima 
    }
    if (choice == "mediana" || choice == "abu") {
        cout << setw(20) << left << "Galutinis(med.)";
    }

    cout << endl;

    cout << "________________________________________________________________________________________" << endl;
    }
    std::ostringstream output;
    output << std::fixed << std::setprecision(2);  // kad butu 0,00

    for (const Studentas& s : studentai) { // per sarasa eina ir spasdina 
        output << setw(20) << left << s.pavarde
            << setw(20) << left << s.vardas;
        if (choice == "vidurkis" || choice == "abu") {
            output << setw(20) << left << s.vidurkis;
        }
        if (choice == "mediana" || choice == "abu") {
            output << setw(20) << left << s.mediana;
        }

        output << endl;
    }

    cout << output.str();//prideda nauja line prie outputo 
    auto finishvisogalutinis = chrono::high_resolution_clock::now(); // End overall timer here
    chrono::duration<double> elapsedviso = finishvisogalutinis - startvisogalutinis;
    cout << "Bendras laikas programos"<< " " << elapsedviso.count() << " sekundes" << endl;
    return 0;
}