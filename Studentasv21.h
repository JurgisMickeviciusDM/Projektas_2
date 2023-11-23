#ifndef STUDENTASV21_H
#define STUDENTASV21_H

#include <vector>
#include <string>
#include <list>
#include <numeric>
#include <algorithm>

class Studentas {
private:
    std::string vardas_;
    std::string pavarde_;
    std::vector<int> pazymiaiV_;
    std::list<int> pazymiai_;
    double vidurkis_ = 0.00;
    double mediana_ = 0.00;
    double egzaminas_ = 0.00;

public:
    // Konstruktorius
    Studentas() = default;
    Studentas(const std::string& vardas, const std::string& pavarde,
        const std::vector<int>& pazymiaiV, double egzaminas)
        : vardas_(vardas), pavarde_(pavarde), pazymiaiV_(pazymiaiV), egzaminas_(egzaminas) {
        
    }

    // Getteriai
    std::string getVardas() const { return vardas_; }
    std::string getPavarde() const { return pavarde_; }
    std::vector<int> getPazymiaiV() const { return pazymiaiV_; }
    std::list<int> getPazymiai() const { return pazymiai_; }
    double getVidurkis() const { return vidurkis_; }
    double getMediana() const { return mediana_; }
    double getEgzaminas() const { return egzaminas_; }

    // Setteriai
    void setVardas(const std::string& vardas) { vardas_ = vardas; }
    void setPavarde(const std::string& pavarde) { pavarde_ = pavarde; }
    void setPazymiaiV(const std::vector<int>& pazymiaiV) { pazymiaiV_ = pazymiaiV; }
    void setPazymiai(const std::list<int>& pazymiai) { pazymiai_ = pazymiai; }
    void setEgzaminas(double egzaminas) { egzaminas_ = egzaminas; }

    void calculateVidurkis() {
        if (!pazymiai_.empty()) {
            // Skaièiuoti vidurká naudojant list
            vidurkis_ = std::accumulate(pazymiai_.begin(), pazymiai_.end(), 0.0) / pazymiai_.size();
        }
        else if (!pazymiaiV_.empty()) {
            // Skaièiuoti vidurká naudojant vector
            vidurkis_ = std::accumulate(pazymiaiV_.begin(), pazymiaiV_.end(), 0.0) / pazymiaiV_.size();
        }
    }

    void calculateMediana() {
        if (!pazymiai_.empty()) {
            // Rûðiuojame sàraðà
            pazymiai_.sort();
            size_t size = pazymiai_.size();
            auto mid = next(pazymiai_.begin(), size / 2);
            if (size % 2 == 0) {
                auto midPrev = prev(mid, 1);
                mediana_ = (*mid + *midPrev) / 2.0;
            }
            else {
                mediana_ = *mid;
            }
        }
        else if (!pazymiaiV_.empty()) {
            // Skaièiuoti medianà naudojant vector
            std::vector<int> sortedGrades = pazymiaiV_;
            sort(sortedGrades.begin(), sortedGrades.end());
            size_t size = sortedGrades.size();
            if (size % 2 == 0) {
                mediana_ = (static_cast<double>(sortedGrades[size / 2 - 1]) + sortedGrades[size / 2]) / 2.00;
            }
            else {
                mediana_ = sortedGrades[size / 2];
            }
        }
    }


    

    
};

#endif // STUDENTASV21_H
