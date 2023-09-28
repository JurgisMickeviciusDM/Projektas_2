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
#include "studentas.h"
#include "Mediana.h"
#include <chrono>
#include "vidurkis.h"
#include <fstream>


//STUDENTAS APIBRĖŽTA STUDETAS.H
using namespace std;

//double Mediana.h

int main() {
    srand(static_cast<unsigned int>(time(0)));

    string header1, header2, choice, inputMethod;
    vector<Studentas> studentai;


    do {
        cout << "Pasirinkite ar naudosite duomenis is failo, rasyti ,,Duomenys'' ar naudosite rankiniu budu ivedamus duomenis, rasyti ,,Ranka'': ";
        cin >> inputMethod;
        if (inputMethod != "Duomenys" && inputMethod != "Ranka") {
            cout << "Neteisingai parasete! Bandykite dar karta." << endl;
        }
    } while (inputMethod != "Duomenys" && inputMethod != "Ranka");
         
    do {
        cout << "Prasome pasirinkti ka norite skaiciuoti vidurki ar mediana. Parasykite('Vidurkis') arba ('Mediana') arba ('ABU'):";
        cin >> choice;

        if (choice == "Vidurkis") {
            header1 = "Galutinis(vid.)";
        }
        else if (choice == "Mediana") {
            header1 = "Galutinis(med.)";
        }
        else if (choice == "ABU") {
            header1 = "Galutinis(vid.)";
            header2 = "Galutinis(med.)";
        }
        else {
            cout << "Neteisinga pasirinkimas! Bandykite dar karta." << endl;
        }

    } while (choice != "Vidurkis" && choice != "Mediana" && choice != "ABU");
    cin.ignore();


    int skaicius = 0;
    auto start = std::chrono::high_resolution_clock::now();
    if (inputMethod == "Duomenys") {
        ifstream file;
        string filename = "Studentai10000.txt";  // failo vardas

        do {
            file.open(filename);
            if (!file) {
                cerr << "Nepavyko atidaryti failo '" << filename << "'. Prašome įvesti naują failo pavadinimą: ";
                cin >> filename;  // naujai 
            }
        } while (!file);  //kol atidarys

        // readina headeri
        string headerLine;
        getline(file, headerLine);
        istringstream headerStream(headerLine);
        string word;
        vector<string> headers;
        while (headerStream >> word) {
            headers.push_back(word);
        }

        int ndCount = static_cast<int>(headers.size()) - 3;// Minus Vardas, Pavarde, ir Egzaminas
       

        //duomenu skaitymas 
        Studentas s;
        while (file >> s.vardas >> s.pavarde) {
            string gradeStr;
            for (int i = 0; i < ndCount; i++) {
                file >> gradeStr;
                try {
                    int grade = stoi(gradeStr);
                    s.pazymiai.push_back(grade);
                }
               catch (const std::invalid_argument& e) {
                    // Ignoruojame netinkamą pažymį, bet skaitymą tęsiame toliau
                    continue;
                }
            }
            int egzaminas;
            file >> egzaminas;

            if (choice == "Vidurkis" || choice == "ABU") {
                double vidurkis = calculateVidurkis(s.pazymiai);

                s.vidurkis = 0.40 * vidurkis + 0.60 * egzaminas;
            }
            if (choice == "Mediana" || choice == "ABU") {
              
                double mediana = calculateMedian(s.pazymiai);
                s.mediana = 0.40 * mediana + 0.60 * egzaminas;
            }

            studentai.push_back(s);
            s.pazymiai.clear();
        }

        file.close();
    }
    else if (inputMethod == "Ranka") {
        cout << "Pasirinkite norima skaiciu studentu. Iveskite ju skaiciu(naudoti tik skaicius): ";
        while (!(cin >> skaicius) || skaicius <= 0) {
            cout << "Neteisingai ivedete skaiciu, pakartokite norima skaiciu ivesdami skaitmenis ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    for (int j = 0; j < skaicius; j++) {
        Studentas s;
        vector<int> pazymiai;
        int suma = 0;


        do {
            cout << "Iveskite " << j + 1 << "-ojo studento/studentes varda (tik raides): ";
            cin >> s.vardas;
        } while (!all_of(s.vardas.begin(), s.vardas.end(), ::isalpha));


        do {
            cout << "Iveskite " << j + 1 << "-ojo studento/studentes pavarde (tik raides): ";
            cin >> s.pavarde;
        } while (!all_of(s.pavarde.begin(), s.pavarde.end(), ::isalpha));

        bool validChoice = false;

        string autoGenChoice;

        while (!validChoice) {
            cout << "Ar norite, kad " << j + 1 << "-ojo studento pazymiai butu generuojami atsitiktinai? (taip/ne): ";
            cin >> autoGenChoice;

            if (autoGenChoice == "taip") {
                int pazymiuKiekis = rand() % 10 + 1;
                for (int k = 0; k < pazymiuKiekis; k++) {
                    int pazymys = rand() % 10 + 1;
                    pazymiai.push_back(pazymys);
                    suma += pazymys;
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
                cout << "Įveskite " << j + 1 << "-ojo studento pažymius (dešimtbalė sistema) ir spauskite ENTER 2x, kad baigtumėte įvedimą:" << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string input;
                while (getline(cin, input) && !input.empty()) {
                    try {
                        int pazymys = stoi(input);
                        if (pazymys >= 1 && pazymys <= 10) {
                            pazymiai.push_back(pazymys);
                            suma += pazymys;
                        }
                        else {
                            cout << "Neteisinga įvesta. Prašome įvesti pažymį nuo 1 iki 10: ";
                            klaida = true;
                            break;
                        }
                    }
                    catch (const invalid_argument&) {
                        cout << "Neteisinga įvesta. Prašome įvesti pažymį nuo 1 iki 10: ";
                        klaida = true;
                        break;
                    }
                }
            }


            if (pazymiai.empty() && autoGenChoice == "ne") {
                cout << "Klaida! Jus neivedete jokiu pazymiu. Negalima skaiciuoti vidurkio ar medianos be pazymiu." << endl;
                klaida = true;
            }
        } while (klaida);




        int egzaminas;
        if (autoGenChoice == "taip") {
            egzaminas = rand() % 10 + 1;  //generuos
        }
        else {
            bool validEgzaminas = false;
            while (!validEgzaminas) {
                cout << "Įveskite " << j + 1 << "-ojo studento egzamino rezultata nuo 1 iki 10:" << endl;
                if (cin >> egzaminas) {
                    if (egzaminas >= 1 && egzaminas <= 10) {
                        validEgzaminas = true;
                    }
                    else {
                        cout << "Neteisinga ivesta. Prašome ivesti egzamino pazymi nuo 1 iki 10." << endl;
                        cin.clear();
                    }
                }
                else {
                    cout << "Neteisinga ivesta. Prasome ivesti egzamino pazymi nuo 1 iki 10." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }
        }

        if (choice == "Vidurkis" || choice == "ABU") {

            double vidurkis = static_cast<double>(suma) / pazymiai.size();
            s.vidurkis = 0.40 * vidurkis + 0.60 * egzaminas;
        }

        if (choice == "Mediana" || choice == "ABU") {

            double mediana = calculateMedian(pazymiai);
            s.mediana = 0.40 * mediana + 0.60 * egzaminas;
        }

        studentai.push_back(s);
    }

    auto compareFromFile = [](const Studentas& a, const Studentas& b) {
        int numA = stoi(a.pavarde.substr(7));
        int numB = stoi(b.pavarde.substr(7));
        return numA < numB;
        };

    auto simpleCompare = [](const Studentas& a, const Studentas& b) {
        return a.pavarde < b.pavarde;
        };

    // 
    if (inputMethod == "Duomenys") {
        
        sort(studentai.begin(), studentai.end(), compareFromFile);
    }
    else {
        sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
            return a.pavarde < b.pavarde;
            });
    }

    cout << fixed << setprecision(2);
    cout << setw(20) << left << "Pavarde"
        << setw(20) << left << "Vardas";

    if (choice == "Vidurkis" || choice == "ABU") {
        cout << setw(20) << left << "Galutinis(vid.)";
    }
    if (choice == "Mediana" || choice == "ABU") {
        cout << setw(20) << left << "Galutinis(med.)";
    }

    cout << endl;

    cout << "________________________________________________________________________________________" << endl;

    std::ostringstream output;
    output << std::fixed << std::setprecision(2);  // kad butu 0,00

    for (const Studentas& s : studentai) {
        output << setw(20) << left << s.pavarde
            << setw(20) << left << s.vardas;

        if (choice == "Vidurkis" || choice == "ABU") {
            output << setw(20) << left << s.vidurkis;
        }
        if (choice == "Mediana" || choice == "ABU") {
            output << setw(20) << left << s.mediana;
        }

        output << endl;
    }

    std::cout << output.str();
   
auto finish = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> elapsed = finish - start;
std::cout << "\nLaikas: " << elapsed.count() << " s\n";

return 0;
}