#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <vector>
#include <cmath>
#include "functions.h"
#include "geneticAlgorithm.h"

int main()
{
    std::string inputFileName = "input.txt"; // Temporary solution for debugging
    std::string outputFileName = "output.txt";
    int nGenerations = 200;
    int populationSize = 50;

    std::map<std::pair<std::string, std::string>, int> distanceMatrix = readInputFile(inputFileName);

    int numCities = sqrt(distanceMatrix.size()); // Since number of all roads between cities is always a squared number of cities

    std::vector<std::string> cityNames;
    
    for(const auto& entry : distanceMatrix)
    {
        const auto& key = entry.first;
        if(std::find(cityNames.begin(), cityNames.end(), key.first) == cityNames.end())
        {
            cityNames.push_back(key.first);
        }
        if(std::find(cityNames.begin(), cityNames.end(), key.second) == cityNames.end())
        {
            cityNames.push_back(key.second);
        }
    }

    std::vector<Chromosome> population = initializePopulation(distanceMatrix, populationSize, numCities, cityNames);

    return 0;
}