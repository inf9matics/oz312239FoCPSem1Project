#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <random>
#include <algorithm>

struct Chromosome
{
    std::vector<int> path;
    int fitness = 0;
};

int get_random_in_range(int from, int to);
bool checkConnection(const std::vector<std::vector<int>>& distanceMatrix, const std::vector<int>& path, const int& city);
bool pathBack(const std::vector<std::vector<int>>& distanceMatrix, const std::vector<int>& path);
bool checkPath(const std::vector<std::vector<int>>& distanceMatrix, const std::vector<int>& path);
std::vector<Chromosome> initializePopulation(const std::vector<std::vector<int>>& distanceMatrix, const std::vector<int>& cities, const int& populationSize);
Chromosome crossover(const std::vector<std::vector<int>>& distanceMatrix, const std::vector<int>& path1, const std::vector<int>& path2);
void breedNextPopulation(const std::vector<std::vector<int>>& distanceMatrix, std::vector<Chromosome>& population);