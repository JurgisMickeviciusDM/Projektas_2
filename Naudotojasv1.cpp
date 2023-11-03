#include "Naudotojasv1.h"
#include <algorithm> 
using namespace std;

void toLowercase(string& str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

void naudotojas(string& inputMethod, string& choice, string& header1, string& header2, string& choice1, string& choice2 ) {
    do {
        cout << "Pasirinkite ar naudosite duomenis is failo, rasyti ,,Duomenys'' ar naudosite rankiniu budu ivedamus duomenis, rasyti ,,Ranka'' ar naudosite autogeneruojamus failus ,,Auto'' ";
        cin >> inputMethod;
        toLowercase(inputMethod); // Konvertuojame �vest� � ma��sias raides
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
                header1 = "Galutinis(vid.)";
                header2 = "";
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
                cout << "Neteisinga pasirinkimas! Bandykite dar karta. GALIMA TIK GALUTINIS" << endl;
            }
        } while (choice1 != "vardus" && choice1 != "pavardes" && choice1 != "vidurkius");
        
        do {
            cout << "Prasome pasirinkti strategija S arba D " << endl;
            cin >> choice2;
            toLowercase(choice2);
            if (choice2 == "s") {
                
            }
            else if (choice2 == "d") {
                
            }
            else {
                cout << "Neteisingas pasirinkimas strategijos, reikia rasyti s arba d " << endl;
            }
        } while (choice2 != "s" && choice2 != "d");

    }
    else {
        do {
            cout << "Prasome pasirinkti ka norite skaiciuoti vidurki ar mediana. Parasykite('vidurkis') arba ('mediana') arba ('abu')";
            cin >> choice;
            toLowercase(choice);

            if (choice == "vidurkis") {
                header1 = "Galutinis(vid.)";
            }
            else if (choice == "mediana") {
                header1 = "Galutinis(med.)";
            }
            else if (choice == "abu") {
                header1 = "Galutinis(vid.)";
                header2 = "Galutinis(med.)";
            }
            else {
                cout << "Neteisinga pasirinkimas! Bandykite dar karta." << endl;
            }
        } while (choice != "vidurkis" && choice != "mediana" && choice != "abu");
    }
    cin.ignore(); // leis per nauj ivesti 
}
