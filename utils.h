#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <iterator>

#include "geneticAlgorithm.h"

bool isNumber(const std::string& s);
std::vector<std::string> readInputFile(const std::string& inputFileName, std::vector<std::vector<int>>& distanceMatrix, std::vector<int>& cities);
void outputBestSolution(std::ofstream& outputFile, const int& generation, const Chromosome& chromosome, const std::vector<std::string>& cityNames);
void calculateDistance(const std::vector<std::vector<int>>& distanceMatrix, Chromosome& chromosome);
bool compareChromosomes(const Chromosome& a, const Chromosome& b);
void sort(const std::vector<std::vector<int>>& distanceMatrix, std::vector<Chromosome>& population);