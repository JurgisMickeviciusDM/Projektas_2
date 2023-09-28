// studentas.cpp

#include "studentas.h"
#include <cctype> // for isdigit()

bool comparePavardes(const Studentas& a, const Studentas& b) {
    size_t i = 0, j = 0;

    while (i < a.pavarde.size() && j < b.pavarde.size()) {
        if (isdigit(a.pavarde[i]) && isdigit(b.pavarde[j])) {
            int numA = 0, numB = 0;

            while (i < a.pavarde.size() && isdigit(a.pavarde[i])) {
                numA = numA * 10 + (a.pavarde[i] - '0');
                i++;
            }

            while (j < b.pavarde.size() && isdigit(b.pavarde[j])) {
                numB = numB * 10 + (b.pavarde[j] - '0');
                j++;
            }

            if (numA != numB) return numA < numB;
        }
        else {
            if (a.pavarde[i] != b.pavarde[j]) return a.pavarde[i] < b.pavarde[j];

            i++;
            j++;
        }
    }

    return a.pavarde.size() < b.pavarde.size();
}
