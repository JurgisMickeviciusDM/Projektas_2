#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Studentas {
    string vardas;
    string pavarde;
    double galutinis;
};

double calculateMedian(const vector<int>& grades) {
    vector<int> sortedGrades = grades;
    sort(sortedGrades.begin(), sortedGrades.end());

    size_t size = sortedGrades.size();
    if (size % 2 == 0) {
        return (sortedGrades[size / 2 - 1] + sortedGrades[size / 2]) / 2.0;
    }
    else {
        return sortedGrades[size / 2];
    }
}

int main() {
    srand(time(0)); 
    int skaicius;
    string header, choice;

    cout << "Pasirinkite norima skaiciu studentu. Iveskite ju skaiciu(naudoti tik skaicius): ";
    while (!(cin >> skaicius) || skaicius <= 0) {
        cout << "Neteisingai ivedete skaiciu, pakartokite norima skaiciu ivesdami skaitmenis ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

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

    vector<Studentas> studentai;

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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // clear the buffer
            string input;
            while (getline(cin, input) && !input.empty()) {
                int pazymys = stoi(input);
                if (pazymys >= 1 && pazymys <= 10) {
                    pazymiai.push_back(pazymys);
                    suma += pazymys;
                }
                else {
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
