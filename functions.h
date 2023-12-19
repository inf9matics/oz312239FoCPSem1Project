#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <map>
#include <vector>
#include <sstream>

std::map<std::pair<std::string, std::string>, int> readInputFile (const std::string& inputFileName);