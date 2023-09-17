#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

int main() {
    string vardas, pavarde;
    int skaicius, skaicius1, pazymys;

    cout << "Iveskite kiek bus studentu: ";
    while (!(cin >> skaicius) || skaicius <= 0) {
        cout << "Neteisingai ivedete skaiciu. Prasome per nauja ivesti skaiciu: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Iveskite kiek studentas tures namų darbų, tai yra pazymiu: ";
    while (!(cin >> skaicius1) || skaicius1 <= 0) {
        cout << "Neteisingai ivedete skaiciu. Prasome per nauja ivesti skaiciu: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int j = 0; j < skaicius; j++) {
        // Vardo tikrinimas
        bool teisingasVardas = false;
        while (!teisingasVardas) {
            cout << "Iveskite " << j + 1 << "-ojo studento varda: ";
            cin >> vardas;

            teisingasVardas = true;
            for (char c : vardas) {
                if (!isalpha(c)) {
                    teisingasVardas = false;
                    cout << "Neteisingai ivedete varda. Vardas turi susidaryti tik is raidziu." << endl;
                    break;
                }
            }
        }

        // Pavardės tikrinimas
        bool teisingaPavarde = false;
        while (!teisingaPavarde) {
            cout << "Iveskite " << j + 1 << "-ojo studento pavarde: ";
            cin >> pavarde;

            teisingaPavarde = true;
            for (char c : pavarde) {
                if (!isalpha(c)) {
                    teisingaPavarde = false;
                    cout << "Neteisingai ivedete pavarde. Pavarde turi susidaryti tik is raidziu." << endl;
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


        s.vidurkis = static_cast<double>(suma) / skaicius1;
        studentai.push_back(s);
    }

    cout << "\nVardas" << "    " << "Pavarde" << "    " << "Vidurkis" << endl;
    cout << "________________________________________________" << endl;

    for (Studentas s : studentai) {
        cout << s.vardas << "      " << s.pavarde << "      " << s.vidurkis << endl;
    }

    return 0;
}























































