#pragma once

#include <vector>
#include <string>

// Structure representing a chromosome (a potential solution)
struct Chromosome
{
    std::vector<std::string> path;
    int fitness = 0;
};

extern std::vector<std::string> cityNames; // Implemented globally, so it wouldn't have to be passed to almost every function
extern std::vector<std::vector<int>> distanceMatrix;