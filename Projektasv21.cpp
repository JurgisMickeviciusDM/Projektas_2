
#include "studentasv21.h"
#include "Skaiciavimasv21.h"
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
#include "Naudotojasv21.h"
#include "Generavimasv21.h"

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
        vector<Studentas> studentai;

        if (inputMethod == "auto") {


            std::vector<int> studentuSkaiciai = { 1000, 10000, 100000, 1000000 };
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
                    try {
                        int grade = stoi(gradeStr);
                        pazymiaiV.push_back(grade);
                    }
                    catch (const std::invalid_argument&) {
                        continue;
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

                bool klaida;
                do {
                    klaida = false;

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
                                klaida = true;
                                break;
                            }
                        }
                    }
                } while (klaida);

                s.setPazymiaiV(pazymiaiV);

                int egzaminas;
                if (autoGenChoice == "taip") {
                    egzaminas = rand() % 10 + 1;
                }
                else {
                    bool validEgzaminas = false;
                    while (!validEgzaminas) {
                        cout << "Iveskite " << j + 1 << "-ojo studento egzamino rezultata nuo 1 iki 10: ";
                        if (cin >> egzaminas) {
                            if (egzaminas >= 1 && egzaminas <= 10) {
                                validEgzaminas = true;
                            }
                        }
                        else {
                            cout << "Neteisinga ivesta. Prasome ivesti egzamino pazymi nuo 1 iki 10: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    }
                }
                s.setEgzaminas(egzaminas);

                s.calculateVidurkis();
                s.calculateMediana();
                

                studentai.push_back(s);
                cout << j + 1 << "-ojo studento objekto adresas atmintyje: " << &s << endl;
            }

            auto compareFromFile = [](const Studentas& a, const Studentas& b) {
                int numA = stoi(a.getPavarde().substr(7));
                int numB = stoi(b.getPavarde().substr(7));
                return numA < numB;
                };

            if (inputMethod == "duomenys") {
                sort(studentai.begin(), studentai.end(), compareFromFile);
            }
            else {
                sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
                    return a.getPavarde() < b.getPavarde();
                    });
            }

            cout << fixed << setprecision(2); // 2 skaičiai po kablelio
            if (inputMethod == "duomenys" || inputMethod == "ranka") {
                cout << setw(20) << left << "Pavarde"
                    << setw(20) << left << "Vardas";

                if (choice == "vidurkis" || choice == "abu") {
                    cout << setw(20) << left << "Galutinis(vid.)";
                }
                if (choice == "mediana" || choice == "abu") {
                    cout << setw(20) << left << "Galutinis(med.)";
                }

                cout << endl;
                cout << "________________________________________________________________________________________" << endl;
            }

            std::ostringstream output;
            output << fixed << setprecision(2);

            for (const Studentas& s : studentai) {
                output << setw(20) << left << s.getPavarde()
                    << setw(20) << left << s.getVardas();
                if (choice == "vidurkis" || choice == "abu") {
                    output << setw(20) << left << s.getVidurkis();
                }
                if (choice == "mediana" || choice == "abu") {
                    output << setw(20) << left << s.getMediana();
                }

                output << endl;
            }
            cout << output.str();

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

            // Studentu saraso rikiavimas ir spausdinimas
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
