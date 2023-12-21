#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <iterator>

#include "storages.h"

bool isNumber(const std::string& s);
std::vector<std::vector<int>> readInputFile(const std::string& inputFileName);
int calculateDistance(const std::vector<std::string>& path);