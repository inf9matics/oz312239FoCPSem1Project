#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <map>
#include <vector>
#include <sstream>
#include<cctype>

bool isNumber(const std::string& s);
std::map<std::pair<std::string, std::string>, int> readInputFile (const std::string& inputFileName);
std::vector<std::string> readCityNames(const std::map<std::pair<std::string, std::string>, int>& distanceMatrix);
int calculateDistance(const std::map<std::pair<std::string, std::string>, int>& distanceMatrix, const std::vector<std::string>& path);