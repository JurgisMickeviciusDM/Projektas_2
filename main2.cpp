#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Studentas { //saugo vienoj vietoj???
    string vardas;
    string pavarde;
    double vidurkis;
    int  egzaminas;
    double galutinis;
};

int main() {
    int skaicius, skaicius1, skaicius2, pazymys, egzaminas;

    cout << "Pasirinkite norima skaiciu studentu. Iveskite ju skaiciu(naudoti tik skaicius): ";
    while (!(cin >> skaicius) || skaicius <= 0) {
        cout << "Neteisingai ivedete skaiciu, pakartokite norima skaiciu ivesdami skaitmenis ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Iveskite kiek studentas tures namų darbų, tai yra kiek gaus pazymiu, kiekvienas pazymis atspindi viena namu darba : ";
    while (!(cin >> skaicius1) || skaicius1 <= 0) {
        cout << "Neteisingai ivedete skaiciu. Prasome per nauja ivesti skaiciu: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Iveskite kiek studentas tures egzaminu, galima ivesti tik VIENA!. Rasyti skaiciu 1: ";
    while (!(cin >> skaicius2) || skaicius2 <= 0 and skaicius2 > 1) {
        cout << "Neteisingai ivedete skaiciu. Prasome per nauja ivesti skaiciu: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }


    vector<Studentas> studentai;

    for (int j = 0; j < skaicius; j++) {
        Studentas s;

        // Vardo tikrinimas
        bool teisingasVardas = false;
        while (!teisingasVardas) {
            cout << "Iveskite " << j + 1 << "-ojo studento/studentes varda: ";
            cin >> s.vardas;

            teisingasVardas = true;
            for (char c : s.vardas) {
                if (!isalpha(c)) {
                    teisingasVardas = false;
                    cout << "Neteisingai ivedete varda. Vardas turi buti tik is raidziu." << endl;
                    break;
                }
            }
        }

        // Pavardės tikrinimas
        bool teisingaPavarde = false;
        while (!teisingaPavarde) {
            cout << "Iveskite " << j + 1 << "-ojo studento/studentes  pavarde: ";
            cin >> s.pavarde;

            teisingaPavarde = true;
            for (char c : s.pavarde) {
                if (!isalpha(c)) {
                    teisingaPavarde = false;
                    cout << "Neteisingai ivedete pavarde. Pavarde turi buti  tik is raidziu." << endl;
                    break;
                }
            }
        }

    
        // Pažymių įvedimas
        vector<int> pazymiai;
        int suma = 0;

        cout << "Įveskite " << j + 1 << "-ojo studento pažymius (dešimtbalė sistema):" << endl;

        for (int i = 0; i < skaicius1; ) {
            cin >> pazymys;

            if (!cin || pazymys < 1 || pazymys > 10) {
                cout << "Neteisinga įvesta. Prašome įvesti pažymį nuo 1 iki 10: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                pazymiai.push_back(pazymys);
                suma += pazymys;
                i++;
            }
        }


        vector<int>egzaminai;
        int suma1 = 0;
        cout << "Įveskite " << j + 1 << "-ojo studento egzamino rezultata nuo 1 iki 10:" << endl;
        cin >> s.egzaminas;

        while (!cin || s.egzaminas < 1 || s.egzaminas > 10) {
            cout << "Neteisinga įvesta. Prašome įvesti egzamino rezultata nuo 1 iki 10: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> s.egzaminas;
        }
        cout << "Prasome pasirinkti ka norite skaiciuoti vidurki ar mediana. Parasykite('Vidurkis') arba ('Mediana'):";
        string choice;
        cin >> choice;
        string header;

        if (choice == "Vidurkis") {
            header = "Galutinis(vid.)";
        }
        else if (choice == "Mediana") {
            header = "Galutinis(med.)";
        }
        else {
            cout << "Neteisinga pasirinkimas!" << endl;
            return 1;
        }

        vector<Studentas> studentai;

        for (int j = 0; j < skaicius; j++) {
            Studentas s;

            
            if (choice == "Vidurkis") {
                s.galutinis = (static_cast<double>(suma) / skaicius1) * 0.4 + s.egzaminas * 0.6;
            }
            else if (choice == "Mediana") {
                vector<int> pazymiai;
                s.galutinis = calculateMedian(pazymiai) * 0.4 + s.egzaminas * 0.6;
            }

            studentai.push_back(s);
        }

        cout << fixed << setprecision(2);

        cout << setw(20) << left << "Pavarde"
            << setw(20) << left << "Vardas"
            << setw(20) << left << header << endl;
        cout << "________________________________________________________________________" << endl;

        for (Studentas s : studentai) {
            cout << setw(20) << left << s.pavarde
                << setw(20) << left << s.vardas
                << setw(20) << left << s.galutinis << endl;
        }

        return 0;
    }
