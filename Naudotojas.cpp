#include "Naudotojas.h"
using namespace std;

void naudotojas(string& inputMethod, string& choice, string& header1, string& header2) {

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




}