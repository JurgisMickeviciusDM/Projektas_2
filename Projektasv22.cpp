#include "studentas22.h"
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
#include "Naudotojas22.h"
#include "Generavimas22.h"

using namespace std;
void saveToFile(const list<Studentas>& studentasList, const string& filename, const string& choice1);
void Generavimas(int n);
void Rusiuoti(std::list<Studentas>& studentai, std::list<Studentas>& vargsiukai, std::list<Studentas>& kietiakiai, char choice2);
void naudotojas(string& inputMethod, string& choice, string& header1, string& header2, string& choice1, string& choice2);
list<Studentas> skaitytiStudentus(int n);
void VisoLaikas();
void saveToFileV(const vector<Studentas>& studentasList, const string& filename, const string& choice1);
void RusiuotiV(std::vector<Studentas>& studentai, std::vector<Studentas>& vargsiukai, std::vector<Studentas>& kietiakiai, char choice2);
vector<Studentas> skaitytiStudentusV(int n);

int main() {
    srand(static_cast<unsigned int>(time(0)));


    string inputMethod, choice, header1, header2, choice1, choice2;

    naudotojas(inputMethod, choice, header1, header2, choice1, choice2);
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
            ifstream file; // Sukuriamas įvesties srautas failo skaitymui.
            string filename = "studentai1000.txt";

            do {
                file.open(filename);
                if (!file) {
                    cerr << "Nepavyko atidaryti failo '" << filename << "'. Prasome ivesti nauja failo pavadinima: ";
                    cin >> filename;// naujas pavadinimas
                }
            } while (!file);//kol atidarys, tai yra nebus fialo


            // readina headeri i eilute
            string headerLine;
            getline(file, headerLine); // // Nuskaitome pirmą failo eilutę - antraštinę eilutę.
            istringstream headerStream(headerLine);   // Sukuriamas srautas, PADES skaityti antraštinės eilutės duomenis.
            string word;//kintamasisi laikomas zodis atskirai
            vector<string> headers;//verktor string tipo ir pavadinimas 
            while (headerStream >> word) {  // Skaidome antraštinę eilutę į atskirus žodžius ir dedame juos į 'headers' vektorių.
                headers.push_back(word); //zodis pridedamas prie header naudojant psuh back metoda, kai konteineris +1 i pabaiga 
            }

            int ndCount = static_cast<int>(headers.size()) - 3;
            vector<Studentas> studentai;

            string vardas, pavarde;
            while (file >> vardas >> pavarde) {
                Studentas s;
                s.setVardas(vardas);  //seteriai 
                s.setPavarde(pavarde); //seteriai nsutatome varda ir pavarde 

                vector<int> pazymiaiV;
                string gradeStr;
                for (int i = 0; i < ndCount; i++) {
                    file >> gradeStr;
                    try {
                        int grade = stoi(gradeStr);
                        pazymiaiV.push_back(grade);
                    }
                    catch (const std::invalid_argument&) {
                        continue;   //jei konvertavimas nepavyksta tai su catch pagauname ir tesiame su kitais pazymiais darba
                        // Ignoruojame netinkamą pažymį, bet skaitymą tęsiame toliau
                    }
                }
                s.setPazymiaiV(pazymiaiV);

                double egzaminas;
                file >> egzaminas;
                s.setEgzaminas(egzaminas);


                s.calculateVidurkis();
                s.calculateMediana();


                studentai.push_back(s);
            }

            file.close();   // isvedimas i ekrana 

            cout << setw(15) << left << "Vardas" // varda spausdins 
                << setw(15) << left << "Pavarde"; //pavarde 

            if (choice == "vidurkis" || choice == "abu") {
                cout << setw(15) << left << "Vidurkis";   //vidurki 
            }
            if (choice == "mediana" || choice == "abu") {
                cout << setw(15) << left << "Mediana"; //mediana
            }
            cout << endl;
            cout << string(60, '-') << endl;



            for (const auto& studentas : studentai) { //per visus studentus, nuoroda i studentas yra  objekta, naudojame konstanta, kad nekistu data 
                cout << setw(15) << left << studentas.getVardas()
                    << setw(15) << left << studentas.getPavarde();
                if (choice == "vidurkis" || choice == "abu") {
                    cout << setw(15) << left << fixed << setprecision(2) << studentas.getVidurkis();
                }
                if (choice == "mediana" || choice == "abu") {
                    cout << setw(15) << left << fixed << setprecision(2) << studentas.getMediana();
                }
                cout << endl;
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
            studentai.reserve(skaicius); // Rezervuojama vietą vektoriaus dydžiui

            for (int j = 0; j < skaicius; j++) {
                Studentas s;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Iveskite " << j + 1 << "-ojo studento/studentes duomenis." << endl;
                cin >> s; // Naudokite overloadintą operatorių >> studento duomenims gauti   
                studentai.push_back(s);
            }

            // Studentų sąrašo rūšiavimas pagal pavardę
            sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
                return a.getPavarde() < b.getPavarde();
                });

            cout << fixed << setprecision(2);
            cout << setw(20) << left << "Pavarde"
                << setw(20) << left << "Vardas";

            if (choice == "vidurkis" || choice == "abu") {
                cout << setw(20) << left << "Galutinis(vid.)";
            }
            if (choice == "mediana" || choice == "abu") {
                cout << setw(20) << left << "Galutinis(med.)";
            }
            cout << endl;
            cout << string(80, '_') << endl;


            for (const Studentas& s : studentai) {
                cout << setw(20) << left << s.getPavarde()
                    << setw(20) << left << s.getVardas()
                    << setw(20) << left << s.getVidurkis()
                    << setw(20) << left << s.getMediana()
                    << endl;
            }
        
        
        }
 


    return 0;
}
