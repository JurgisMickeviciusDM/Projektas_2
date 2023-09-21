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
#include <numeric> // for std::accumulate

using namespace std;

struct Studentas {
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    double galutinis = 0.0;
};

double calculateMedian(const vector<int>& grades) {
    vector<int> sortedGrades = grades;
    sort(sortedGrades.begin(), sortedGrades.end());

    size_t size = sortedGrades.size();
    if (size % 2 == 0) {
        return (static_cast<double>(sortedGrades[size / 2 - 1]) + sortedGrades[size / 2]) / 2.0;
    }
    else {
        return sortedGrades[size / 2];
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    string header, choice, inputMethod;
    vector<Studentas> studentai;

    do {
        cout << "Pasirinkite ar naudosite duomenis is failo, rasyti ,,Duomenys'' ar naudosite rankiniu budu ivedamus duomenis, rasyti ,,Ranka'': ";
        cin >> inputMethod;
        if (inputMethod != "Duomenys" && inputMethod != "Ranka") {
            cout << "Neteisingai parasete! Bandykite dar karta." << endl;
        }
    } while (inputMethod != "Duomenys" && inputMethod != "Ranka");
    
    do {
        cout << "Prasome pasirinkti ka norite skaiciuoti vidurki ar mediana. Parasykite('Vidurkis') arba ('Mediana'):";
        cin >> choice;

        if (choice == "Vidurkis") {
            header = "Galutinis(vid.)";
        }
        else if (choice == "Mediana") {
            header = "Galutinis(med.)";
        }
        else {
            cout << "Neteisinga pasirinkimas! Bandykite dar karta." << endl;
        }

    } while (choice != "Vidurkis" && choice != "Mediana");
    cin.ignore();

    int skaicius = 0;

    if (inputMethod == "Duomenys") {
        ifstream file;
        string filename = "Studentai100000.txt";  // failo vardas
        \

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

        int ndCount = headers.size() - 3;  // Minus Vardas, Pavarde, ir Egzaminas

        //duomenu skaitymas 
        Studentas s;
        while (file >> s.vardas >> s.pavarde) {
            int grade;
            for (int i = 0; i < ndCount; i++) {
                file >> grade;
                s.pazymiai.push_back(grade);
            }
            int egzaminas;
            file >> egzaminas;
            if (choice == "Vidurkis") {
                double vidurkis = accumulate(s.pazymiai.begin(), s.pazymiai.end() - 1, 0.0) / static_cast<double>(ndCount);
                s.galutinis = 0.4 * vidurkis + 0.6 * egzaminas;
            }
            else if (choice == "Mediana") {
                double mediana = calculateMedian(vector<int>(s.pazymiai.begin(), s.pazymiai.end() - 1));
                s.galutinis = 0.4 * mediana + 0.6 * egzaminas;
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

        if (autoGenChoice == "ne") {
            cout << "Įveskite " << j + 1 << "-ojo studento pažymius (dešimtbalė sistema) arba spauskite ENTER, kad baigtumėte įvedimą:" << endl;
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
                    }
                }
                catch (const invalid_argument&) {
                    cout << "Neteisinga įvesta. Prašome įvesti pažymį nuo 1 iki 10: ";
                }
            }
        }
        int egzaminas;
        if (autoGenChoice == "taip") {
            egzaminas = rand() % 10 + 1;  //generuos
        }
        else {
            cout << "Įveskite " << j + 1 << "-ojo studento egzamino rezultata nuo 1 iki 10:" << endl;
            cin >> egzaminas;
        }

        if (choice == "Vidurkis") {
            s.galutinis = (static_cast<double>(suma) / pazymiai.size()) * 0.4 + egzaminas * 0.6;
        }
        else if (choice == "Mediana") {
            s.galutinis = calculateMedian(pazymiai) * 0.4 + egzaminas * 0.6;
        }

        studentai.push_back(s);
    }
    cout << fixed << setprecision(2);
    cout << setw(20) << left << "Pavarde"
        << setw(20) << left << "Vardas"
        << setw(20) << left << header << endl;
    cout << "________________________________________________________________________" << endl;

    for (const Studentas& s : studentai) {
        cout << setw(20) << left << s.pavarde
            << setw(20) << left << s.vardas
            << setw(20) << left << s.galutinis << endl;
    }

    return 0;
}
