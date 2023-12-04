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

    string pasirinkimass;
    pasirinkimas(pasirinkimass);

    string inputMethod, choice, header1, header2, choice1, choice2;
    // naudotojas(inputMethod, choice, header1, header2, choice1, choice2);

    if (pasirinkimass == "v") {


        srand(static_cast<unsigned int>(time(0)));
        std::string header1, header2, choice, inputMethod, choice1, choice2;
        naudotojas(inputMethod, choice, header1, header2, choice1, choice2);
        char sortChoice = choice2.empty() ? ' ' : choice2[0];
        int skaicius = 0;
        vector<Studentas> studentai; // studentas klase naudojama jau 

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
                    << setw(20) << left << s.getVardas();
                if (choice == "vidurkis" || choice == "abu") {
                    cout << setw(20) << left << s.getVidurkis();
                }
                if (choice == "mediana" || choice == "abu") {
                    cout << setw(20) << left << s.getMediana();
                }
                cout << endl;
            }


            cout << string(80, '_') << endl;

            for (const Studentas& s : studentai) {
                cout << setw(20) << left << s.getPavarde()
                    << setw(20) << left << s.getVardas()
                    << setw(20) << left << s.getVidurkis()
                    << setw(20) << left << s.getMediana()
                    << endl;
            }
        }
        
    }
    else if (pasirinkimass == "l") {
        int skaicius = 0;

        list<Studentas> studentai;
        srand(static_cast<unsigned int>(time(0)));
        string header1, header2, choice, inputMethod, choice1, choice2;  //kintamieji



        naudotojas(inputMethod, choice, header1, header2, choice1, choice2);
        char sortChoice = choice2.empty() ? ' ' : choice2[0];


        if (inputMethod == "auto") {


            list<int> studentuSkaiciai = { 1000, 10000, 100000 };

            for (int n : studentuSkaiciai) {
                Generavimas(n);
            }

            for (int n : studentuSkaiciai) {
                studentai = skaitytiStudentus(n);
                list<Studentas> vargsiukai;
                list<Studentas> kietiakiai;

                Rusiuoti(studentai, vargsiukai, kietiakiai, sortChoice);

                string vargsiukaiFilename = "vargsiukai_" + choice + to_string(n) + ".txt";
                string kietiakiaiFilename = "kietiakiai_" + choice + to_string(n) + ".txt";

                saveToFile(vargsiukai, vargsiukaiFilename, choice1);
                saveToFile(kietiakiai, kietiakiaiFilename, choice1);

                cout << "____________________" << endl;
                cout << n << " studentu laikas visos programos: " << endl;
                VisoLaikas();
                cout << "____________________" << endl;
            }
        }

        else if (inputMethod == "duomenys") {


            ifstream file;// Sukuriamas įvesties srautas failo skaitymui.
            string filename = "studentai1000.txt";  // failo vardas SKAITOMO

            do {
                file.open(filename);
                if (!file) {
                    cerr << "Nepavyko atidaryti failo '" << filename << "'. Prasome ivesti nauja failo pavadinima: ";
                    cin >> filename;  // naujas pavadinimas
                }
            } while (!file);  //kol atidarys, tai yra nebus fialo

            // readina headeri i eilute
            string headerLine;
            getline(file, headerLine); // Nuskaitome pirmą failo eilutę - antraštinę eilutę.
            istringstream headerStream(headerLine); // Sukuriamas srautas, padės skaityti antraštinės eilutės duomenis.
            string word; // Kintamasis laikomas žodis atskirai
            vector<string> headers; // Vektorius string tipo ir pavadinimas 
            while (headerStream >> word) { // Skaidome antraštinę eilutę į atskirus žodžius ir dedame juos į 'headers' vektorių.
                headers.push_back(word); // Žodis pridedamas prie header naudojant push_back metodą, kai konteineris +1 į pabaigą 
            }

            int ndCount = static_cast<int>(headers.size()) - 3; // Minus Vardas, Pavarde, ir Egzaminas skaiciuoja nd kiekį 

            vector<Studentas> studentai; // Sąrašas studentų

            string vardas, pavarde;
            while (file >> vardas >> pavarde) {
                Studentas s;
                s.setVardas(vardas);
                s.setPavarde(pavarde);

                vector<int> pazymiaiV;
                string gradeStr;
                for (int i = 0; i < ndCount; i++) {
                    file >> gradeStr;
                    try {
                        int grade = stoi(gradeStr);
                        pazymiaiV.push_back(grade);
                    }
                    catch (const std::invalid_argument&) {
                        continue;
                    }
                }
                // Konvertuojame vector<int> į list<int>
                std::list<int> pazymiaiList(pazymiaiV.begin(), pazymiaiV.end());
                s.setPazymiai(pazymiaiList);

                double egzaminas;
                file >> egzaminas;
                s.setEgzaminas(egzaminas);

                s.calculateVidurkis();
                s.calculateMediana();


                studentai.push_back(s);
            }

            file.close();
            cout << "\nStudentų duomenys:" << endl;
            cout << setw(15) << left << "Vardas"
                << setw(15) << left << "Pavarde";

            if (choice == "vidurkis" || choice == "abu") {
                cout << setw(15) << left << "Vidurkis";
            }
            if (choice == "mediana" || choice == "abu") {
                cout << setw(15) << left << "Mediana";
            }
            cout << endl;
            cout << string(60, '-') << endl;

            for (const auto& studentas : studentai) {
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
            for (int j = 0; j < skaicius; j++) {
                Studentas s;
                string vardas, pavarde;
                vector<int> pazymiaiV;

                // Vardo ir pavardės įvedimas
                do {
                    cout << "Iveskite " << j + 1 << "-ojo studento/studentes varda: ";
                    cin >> vardas;
                } while (!all_of(vardas.begin(), vardas.end(), ::isalpha));

                do {
                    cout << "Iveskite " << j + 1 << "-ojo studento/studentes pavarde: ";
                    cin >> pavarde;
                } while (!all_of(pavarde.begin(), pavarde.end(), ::isalpha));

                s.setVardas(vardas);
                s.setPavarde(pavarde);

                // Pazymiu ir egzamino rezultato generavimas arba ivedimas
                bool validChoice = false;
                string autoGenChoice;

                while (!validChoice) {
                    cout << "Ar norite, kad " << j + 1 << "-ojo studento pazymiai butu generuojami atsitiktinai? (taip/ne): ";
                    cin >> autoGenChoice;

                    if (autoGenChoice == "taip") {
                        int pazymiuKiekis = rand() % 10 + 1;
                        for (int k = 0; k < pazymiuKiekis; k++) {
                            int pazymys = rand() % 10 + 1;
                            pazymiaiV.push_back(pazymys);
                        }
                        validChoice = true;
                    }
                    else if (autoGenChoice == "ne") {
                        validChoice = true;
                    }
                    else {
                        cout << "Neteisinga pasirinkimas! Bandykite dar karta." << endl;
                    }
                }

                if (autoGenChoice == "ne") {
                    cout << "Iveskite " << j + 1 << "-ojo studento pazymius (desimtbale sistema) ir spauskite ENTER 2x, kad baigtumete ivedima:" << endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    string input;
                    while (getline(cin, input) && !input.empty()) {
                        try {
                            int pazymys = stoi(input);
                            if (pazymys >= 1 && pazymys <= 10) {
                                pazymiaiV.push_back(pazymys);
                            }
                        }
                        catch (const invalid_argument&) {
                            cout << "Neteisinga ivesta. Prasome ivesti pazymi nuo 1 iki 10: ";
                        }
                    }
                }

                double egzaminas;
                if (autoGenChoice == "taip") {
                    egzaminas = rand() % 10 + 1;
                }
                else {
                    cout << "Iveskite " << j + 1 << "-ojo studento egzamino rezultata nuo 1 iki 10: ";
                    while (!(cin >> egzaminas) || egzaminas < 1 || egzaminas > 10) {
                        cout << "Neteisinga ivesta. Prasome ivesti egzamino pazymi nuo 1 iki 10: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }

                s.setPazymiaiV(pazymiaiV);
                s.setEgzaminas(egzaminas);
                s.calculateVidurkis();
                s.calculateMediana();

                studentai.push_back(s);
            }

            // Studentu saraso rykiavimas ir spausdinimas
            if (inputMethod == "duomenys") {
                sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
                    return a.getPavarde() < b.getPavarde();
                    });
            }

            cout << fixed << setprecision(2);
            cout << setw(20) << left << "Pavarde"
                << setw(20) << left << "Vardas"
                << setw(20) << left << "Galutinis(vid.)"
                << setw(20) << left << "Galutinis(med.)" << endl;

            cout << string(80, '_') << endl;

            std::ostringstream output;
            output << fixed << setprecision(2);

            for (const auto& studentas : studentai) {
                output << setw(20) << left << studentas.getPavarde()
                    << setw(20) << left << studentas.getVardas()
                    << setw(20) << left << studentas.getVidurkis()
                    << setw(20) << left << studentas.getMediana() << endl;
            }

            cout << output.str();
        }
    }



    return 0;
}
