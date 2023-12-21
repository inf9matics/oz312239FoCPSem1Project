#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <random>
#include <algorithm>

#include "storages.h"

int get_random_in_range(int from, int to);
void listAvailableCities(const std::vector<std::string>& path1, const std::vector<std::string>& path2, std::vector<std::string>& availableCities);
bool pathBack(const std::vector<std::string>& path);
std::vector<Chromosome> initializePopulation(int populationSize, int numCities);
Chromosome crossover(const Chromosome& parent1, const Chromosome& parent2);