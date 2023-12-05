#ifndef STUDENTASV25_H
#define STUDENTASV25_H

#include <vector>
#include <string>
#include <list>
#include <numeric>
#include <algorithm>
#include <iostream> 
#include <iomanip>


/*

class Zmogus {
protected:
    std::string vardas_;
    std::string pavarde_;

public:
    Zmogus(const std::string& vardas, const std::string& pavarde)
        : vardas_(vardas), pavarde_(pavarde) {}

    virtual ~Zmogus() = 0;

    // Getteriai
    std::string getVardas() const { return vardas_; }
    std::string getPavarde() const { return pavarde_; }

    // Seteriai
    void setVardas(const std::string& vardas) { vardas_ = vardas; }
    void setPavarde(const std::string& pavarde) { pavarde_ = pavarde; }
};
*/

class Zmogus {
protected:
    std::string vardas_;
    std::string pavarde_;

public:
    Zmogus(const std::string& vardas, const std::string& pavarde)
        : vardas_(vardas), pavarde_(pavarde) {}

    virtual ~Zmogus() {}

    virtual std::string getVardas() const { return vardas_; }
    virtual std::string getPavarde() const { return pavarde_; }

    virtual void setVardas(const std::string& vardas) { vardas_ = vardas; }
    virtual void setPavarde(const std::string& pavarde) { pavarde_ = pavarde; }

    virtual void informacija() const = 0; 
};

class Studentas : public Zmogus {
private:
    std::vector<int> pazymiaiV_;
    double vidurkis_ = 0.00;
    double egzaminas_ = 0.00;

public:

    Studentas() : Zmogus("", ""), vidurkis_(0.0), egzaminas_(0.0) {}
    Studentas(const std::string& vardas, const std::string& pavarde, const std::vector<int>& pazymiaiV, double egzaminas)
        : Zmogus(vardas, pavarde), pazymiaiV_(pazymiaiV), egzaminas_(egzaminas) {
        calculateVidurkis();
    }

        Studentas(const Studentas& other)
            : Zmogus(other.getVardas(), other.getPavarde()),
            pazymiaiV_(other.pazymiaiV_),
            vidurkis_(other.vidurkis_),
           
            egzaminas_(other.egzaminas_) {
        }

        Studentas& operator=(const Studentas& other) {
            if (this != &other) {
                Zmogus::setVardas(other.getVardas());
                Zmogus::setPavarde(other.getPavarde());
                pazymiaiV_ = other.pazymiaiV_;
                vidurkis_ = other.vidurkis_;
               
                egzaminas_ = other.egzaminas_;
            }
            return *this;
        }

        ~Studentas() { //destruktorius
            pazymiaiV_.clear();
        }


        //input and output operatoriai
        friend std::istream& operator>>(std::istream& is, Studentas& studentas) {
            // Vardo įvedimas su patikrinimu
            std::cout << "Iveskite varda: ";
            while (true) {
                is >> studentas.vardas_;
                if (std::all_of(studentas.vardas_.begin(), studentas.vardas_.end(), ::isalpha)) {
                    break;
                }
                else {
                    std::cout << "Neteisinga ivestis. Iveskite varda dar karta: ";
                }
            }

            // Pavardės įvedimas su patikrinimu
            std::cout << "Iveskite pavarde: ";
            while (true) {
                is >> studentas.pavarde_;
                if (std::all_of(studentas.pavarde_.begin(), studentas.pavarde_.end(), ::isalpha)) {
                    break;
                }
                else {
                    std::cout << "Neteisinga ivestis. Iveskite pavarde dar karta: ";
                }
            }

            // Pažymių skaičiaus įvedimas su patikrinimu
            std::string generuotiAtsitiktinai;
            while (true) {
                std::cout << "Ar norite generuoti pazymius atsitiktinai? (taip/ne): ";
                is >> generuotiAtsitiktinai;

                // Transform the input to lowercase
                std::transform(generuotiAtsitiktinai.begin(), generuotiAtsitiktinai.end(), generuotiAtsitiktinai.begin(),
                    [](unsigned char c) { return std::tolower(c); });

                if ((generuotiAtsitiktinai == "taip" || generuotiAtsitiktinai == "ne") &&
                    std::all_of(generuotiAtsitiktinai.begin(), generuotiAtsitiktinai.end(), ::isalpha)) {
                    break;
                }
                else {
                    std::cout << "Neteisinga ivestis. Iveskite 'taip' arba 'ne': ";
                    is.clear();
                    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }

            int pazymiuSk;
            if (generuotiAtsitiktinai == "taip") {
                std::cout << "Iveskite pazymiu skaiciu: ";
                while (!(is >> pazymiuSk) || pazymiuSk <= 0) {
                    is.clear();
                    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Neteisinga ivestis. Iveskite teigiamą pazymiu skaiciu: ";
                }

                studentas.pazymiaiV_.clear();
                for (int i = 0; i < pazymiuSk; ++i) {
                    studentas.pazymiaiV_.push_back(rand() % 10 + 1);
                }
                studentas.egzaminas_ = rand() % 10 + 1;
            }
            else {
                std::cout << "Iveskite pazymiu skaiciu: ";
                while (!(is >> pazymiuSk) || pazymiuSk <= 0) {
                    is.clear();
                    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Neteisinga ivestis. Iveskite teigiamą pazymiu skaiciu: ";
                }

                studentas.pazymiaiV_.clear();
                for (int i = 0; i < pazymiuSk; ++i) {
                    int pazymys;
                    std::cout << "Iveskite " << i + 1 << "-aji pazymi: ";
                    while (!(is >> pazymys) || pazymys < 1 || pazymys > 10) {
                        is.clear();
                        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << "Neteisinga ivestis. Iveskite " << i + 1 << "-aji pazymi dar karta (1-10): ";
                    }
                    studentas.pazymiaiV_.push_back(pazymys);
                }

                // Egzamino rezultato įvedimas su patikrinimu
                std::cout << "Iveskite egzamino rezultata: ";
                while (!(is >> studentas.egzaminas_) || studentas.egzaminas_ < 1 || studentas.egzaminas_ > 10) {
                    is.clear();
                    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Neteisinga ivestis. Iveskite egzamino rezultata dar karta (1-10): ";
                }
            }

            studentas.calculateVidurkis();
            //studentas.calculateMediana();

            return is;
        }



    friend std::ostream& operator<<(std::ostream& os, const Studentas& studentas) {
        os << std::left << std::setw(20) << studentas.vardas_
            << std::setw(20) << studentas.pavarde_
            << std::fixed << std::setprecision(2)
            << std::setw(10) << studentas.vidurkis_;

        return os;
    }
    /*
     friend std::ostream& operator<<(std::ostream& os, const Studentas& studentas) {
         os << std::left << std::setw(20) << studentas.getPavarde()
             << std::setw(20) << studentas.getVardas()
             << std::setw(20) << std::fixed << std::setprecision(2) << studentas.getVidurkis();
         return os;
     }*/


     /*end void printStudent(std::ostream& os, const Studentas& studentas, const std::string& choice) {
          os << std::left << std::setw(20) << studentas.vardas_
              << std::setw(20) << studentas.pavarde_;

          if (choice == "vidurkis" || choice == "abu") {
              os << std::fixed << std::setprecision(2)
                  << std::setw(10) << studentas.vidurkis_;
          }
          if (choice == "mediana" || choice == "abu") {
              os << std::fixed << std::setprecision(2)
                  << std::setw(10) << studentas.mediana_;
          }
          os << std::endl;
      }*/


      // Geteriai gauti reiksmes 
    std::string getVardas() const { return vardas_; }
    std::string getPavarde() const { return pavarde_; }
    std::vector<int> getPazymiaiV() const { return pazymiaiV_; }
    //std::list<int> getPazymiai() const { return pazymiai_; }
    double getVidurkis() const { return vidurkis_; } // rodykles i lelementtus 
    
    double getEgzaminas() const { return egzaminas_; }


    virtual void informacija() const override {
        std::cout << "Studentas: " << getVardas() << " " << getPavarde()
            << " Vidurkis: " << vidurkis_ << std::endl;
    }

    // Seteriai nustatymui privat reiksmem 
    void setVardas(const std::string& vardas) { vardas_ = vardas; }
    void setPavarde(const std::string& pavarde) { pavarde_ = pavarde; }
    void setPazymiaiV(const std::vector<int>& pazymiaiV) { pazymiaiV_ = pazymiaiV; }
    //void setPazymiai(const std::list<int>& pazymiai) { pazymiai_ = pazymiai; }
    void setEgzaminas(double egzaminas) { egzaminas_ = egzaminas; }

    void calculateVidurkis() {
        if (!pazymiaiV_.empty()) {
            double sum = std::accumulate(pazymiaiV_.begin(), pazymiaiV_.end(), 0.0);
            double vidurkis = sum / pazymiaiV_.size();
            vidurkis_ = 0.4 * vidurkis + 0.6 * egzaminas_;
        }
    }
 

};

#endif // STUDENTASV25_H





