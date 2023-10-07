#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <string>
#include "Skaiciavimasv02.h"



using namespace std; // apsira6au std erdve, kad nereik4tu kiekviena kart paskui naudoti .


// Implementation for calculateVidurkis function
double calculateVidurkis(const std::vector<int>& nums) {
    return static_cast<double>(std::accumulate(nums.begin(), nums.end(), 0)) / nums.size();
}

// Implementation for calculateMedian function
double calculateMedian(const vector<int>& grades) {
    vector<int> sortedGrades = grades;
    sort(sortedGrades.begin(), sortedGrades.end());

    size_t size = sortedGrades.size();
    if (size % 2 == 0) {
        return (static_cast<double>(sortedGrades[size / 2 - 1]) + sortedGrades[size / 2]) / 2.00;
    }
    else {
        return sortedGrades[size / 2];
    }
}