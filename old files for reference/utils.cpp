#include "utils.h"

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

/// @brief Reads an input file containing city names and distance matrix to create a distance map.
/// @param inputFileName The name of the input file.
/// @return A distance map represented by std::map<std::pair<std::string, std::string>, int>.
/// @throws std::runtime_error if there is an issue with the input file.
std::map<std::pair<std::string, std::string>, int> readInputFile (const std::string& inputFileName)
{
    std::ifstream inputFile(inputFileName);

    if(!inputFile.is_open())
    {
        throw std::runtime_error("There is an issue with your input file.");
    }

    std::string line;
    std::vector<std::string> cityNames;
    int numCities = 0;

    if(getline(inputFile, line))
    {
        std::istringstream iss(line);
        std::string cityName;

        while(iss >> cityName)
        {   
            cityNames.push_back(cityName);
            numCities++;
        }
    }

    std::map<std::pair<std::string, std::string>, int> distanceMatrix;

    for(int i = 0; i < numCities; i++)
    {
        for(int j = 0; j < numCities; j++)
        {
            int distance;
            inputFile >> distance;
            distanceMatrix[std::make_pair(cityNames[i], cityNames[j])] = distance;
        }
    }

    inputFile.close();

    return distanceMatrix;    
}

/// @brief Extracts unique city names from a distance matrix.
/// @param distanceMatrix The distance matrix represented by std::map<std::pair<std::string, std::string>, int>.
/// @return A vector of strings containing unique city names.
std::vector<std::string> readCityNames(const std::map<std::pair<std::string, std::string>, int>& distanceMatrix)
{   
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

    return cityNames;
}

/// @brief Calculates the total distance of a path based on a distance matrix.
/// @param distanceMatrix The distance matrix represented by std::map<std::pair<std::string, std::string>, int>.
/// @param path           A vector of strings representing the path of cities.
/// @return The total distance of the path.
int calculateDistance(const std::map<std::pair<std::string, std::string>, int>& distanceMatrix, const std::vector<std::string>& path)
{
    int distance = 0;
    int numCities = path.size() - 1;

    for(int i = 0; i < numCities - 1; i++)
    {
        std::pair<std::string, std::string> pair = std::make_pair(path[i], path[i + 1]);
        auto it = distanceMatrix.find(pair);

        distance += it->second;
    }

    return distance;
}