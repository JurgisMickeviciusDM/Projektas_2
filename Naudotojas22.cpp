#include "Naudotojas22.h"
#include <algorithm> 
using namespace std;

void toLowercase(string& str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}


void naudotojas(string& inputMethod, string& choice, string& choice1, string& choice2) {
    do {
        cout << "Pasirinkite ar naudosite duomenis is failo, rasyti ,,Duomenys'' ar naudosite rankiniu budu ivedamus duomenis, rasyti ,,Ranka'' ar naudosite autogeneruojamus failus ,,Auto'' ";
        cin >> inputMethod;
        toLowercase(inputMethod);
        if (inputMethod != "duomenys" && inputMethod != "ranka" && inputMethod != "auto") {
            cout << "Neteisingai parasete! Bandykite dar karta." << endl;
        }
    } while (inputMethod != "duomenys" && inputMethod != "ranka" && inputMethod != "auto");

    if (inputMethod == "auto") {
        do {
            cout << "Noredami suskaiciuoti galutini auto rezime prasome parasyti ,,Galutinis'' ";
            cin >> choice;
            toLowercase(choice);

            if (choice == "galutinis") {
                
            }
            else {
                cout << "Neteisinga pasirinkimas! Bandykite dar karta. GALIMA TIK GALUTINIS" << endl;
            }
        } while (choice != "galutinis");

        do {
            cout << "Prasome pasirinkti pagal ka rikiuosite vardus, pavardes, vidurkius: ";
            cin >> choice1;
            toLowercase(choice1);

            if (choice1 == "vardus") {

            }
            else if (choice1 == "pavardes") {

            }
            else if (choice1 == "vidurkius") {

            }
            else {
                cout << "Neteisinga pasirinkimas! Bandykite dar karta. " << endl;
            }
        } while (choice1 != "vardus" && choice1 != "pavardes" && choice1 != "vidurkius");

        do {
            cout << "Prasome pasirinkti strategija S arba D arba TOBULESNIA strategija DT " << endl;
            cin >> choice2;
            toLowercase(choice2);
            if (choice2 == "s") {

            }
            else if (choice2 == "d") {

            }
            else if (choice2 == "dt") {

            }
            else {
                cout << "Neteisingas pasirinkimas strategijos, reikia rasyti s arba d " << endl;
            }
        } while (choice2 != "s" && choice2 != "d" && choice2 != "dt");

    }
    
    cin.ignore(); // leis per nauj ivesti 
}

