#include "vidurkis.h"
#include <numeric>

double calculateVidurkis(const std::vector<int>& nums) {
    return static_cast<double>(std::accumulate(nums.begin(), nums.end(), 0)) / nums.size();
}
//double vidurkis = accumulate(s.pazymiai.begin(), s.pazymiai.end(), 0.00) / static_cast<double>(ndCount);
