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

std::vector<std::vector<int>> readInputFile(const std::string& inputFileName)
{
    std::ifstream inputFile(inputFileName);

    if(!inputFile.is_open())
    {
        throw std::runtime_error("There is an issue with your input file.");
    }

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

    std::vector<std::vector<int>> distanceMatrix(numCities, std::vector<int>(numCities, 0));

    for(int i = 0; i < numCities; i++)
    {
        for(int j = 0; j < numCities; j++)
        {
            inputFile >> distanceMatrix[i][j];
        }
    }

    inputFile.close();

    return distanceMatrix;    
}

int calculateDistance(const std::vector<std::string>& path)
{
    int distance = 0;
    int numCities = cityNames.size();

    for(int i = 0; i < numCities - 1; i++)
    {
        auto ptrCity1 = std::find(cityNames.begin(), cityNames.end(), path[i]);
        int city1 = std::distance(cityNames.begin(), ptrCity1);
        auto ptrCity2 = std::find(cityNames.begin(), cityNames.end(), path[i + 1]);
        int city2 = std::distance(cityNames.begin(), ptrCity2);
        
        distance += distanceMatrix[city1][city2];
    }

    return distance;  
}


