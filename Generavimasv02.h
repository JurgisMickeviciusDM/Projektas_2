#pragma once
#include "Studentasv02.h"
#include <vector>

void Ifaila();
void sortAndSave(const std::vector<Studentas>& students, const std::string& baseFilename);
void saveToFile(const std::vector<Studentas>& students, const std::string& filename);