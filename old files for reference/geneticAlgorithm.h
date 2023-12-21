#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <chrono>
#include <random>
#include <algorithm>

// Structure representing a chromosome (a potential solution)
struct Chromosome
{
    std::vector<std::string> path;
    int fitness = 0;
};

int get_random_in_range(int from, int to);
std::vector<std::string> listAvailableCities(const std::map<std::pair<std::string, std::string>, int>& distanceMatrix, const std::vector<std::string>& cityNames, const std::vector<std::string>& path);
std::vector<Chromosome> initializePopulation(const std::map<std::pair<std::string, std::string>, int>& distanceMatrix, const int& populationSize, const int& numCities, const std::vector<std::string>& cityNames);
Chromosome crossover(const std::map<std::pair<std::string, std::string>, int>& distanceMatrix, const Chromosome& parent1, const Chromosome& parent2);