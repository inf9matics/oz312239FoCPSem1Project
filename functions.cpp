#include "functions.h"

/// @brief Function that reads input file, and generates map of connections 
/// @param inputFileName 
/// @return distanceMatrix with format (cityname1, cityname2) = distance
std::map<std::pair<std::string, std::string>, int> readInputFile (const std::string& inputFileName)
{
    std::ifstream inputFile(inputFileName);

    if(!inputFile.is_open())
    {
        throw std::runtime_error("There is an issue with your input file.");
    }

    std::string line;
    std::vector<std::string> cityNames;
    int nOfCities = 0;

    if(getline(inputFile, line))
    {
        std::istringstream iss(line);
        std::string cityName;

        while(iss >> cityName)
        {   
            cityNames.push_back(cityName);
            nOfCities++;
        }
    }

    std::map<std::pair<std::string, std::string>, int> distanceMatrix;

    for(int i = 0; i < nOfCities; i++)
    {
        for(int j = 0; j < nOfCities; j++)
        {
            int distance;
            inputFile >> distance;
            distanceMatrix[std::make_pair(cityNames[i], cityNames[j])] = distance;
        }
    }

    inputFile.close();

    return distanceMatrix;    
}