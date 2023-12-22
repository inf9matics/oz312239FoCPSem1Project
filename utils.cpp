#include "utils.h"
#include "storages.h"

/// @brief Checks if a string is a numeric value.
/// @param s The input string to be checked.
/// @return True if the string is a numeric value, false otherwise.
bool isNumber(const std::string& s)
{
    for (char const &ch : s) 
    {
        if (std::isdigit(ch) == 0) 
        {
            return false;
        }
    }
    return true;
}

std::vector<std::string> readInputFile(const std::string& inputFileName, std::vector<std::vector<int>>& distanceMatrix, std::vector<int>& cities)
{
    std::ifstream inputFile(inputFileName);

    if(!inputFile.is_open())
    {
        throw std::runtime_error("There is an issue with your input file.");
    }

    std::vector<std::string> cityNames;
    std::string line;

    if(getline(inputFile, line))
    {
        std::istringstream iss(line);
        std::string cityName;

        while(iss >> cityName)
        {   
            cityNames.push_back(cityName);
        }
    }

    int numCities = cityNames.size();

    distanceMatrix.resize(numCities, std::vector<int>(numCities, 0));

    for(int i = 0; i < numCities; i++)
    {
        cities.push_back(i);

        for(int j = 0; j < numCities; j++)
        {
            inputFile >> distanceMatrix[i][j];
        }
    }

    inputFile.close();

    return cityNames;    
}

void calculateDistance(Chromosome& chromosome)
{
    for(int i = 0; i < cities.size(); i++)
    {
        chromosome.fitness += distanceMatrix[chromosome.path[i]][chromosome.path[i+1]];
    }  
}