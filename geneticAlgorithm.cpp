#include "geneticAlgorithm.h"

int get_random_in_range(int from, int to) 
{
    static std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(from, to);
    return distribution(generator);
}

std::vector<std::string> listAvailableCities(const std::map<std::pair<std::string, std::string>, int>& distanceMatrix, const std::string& city, const std::vector<std::string>& cityNames, const std::vector<std::string>& path)
{
    std::vector<std::string> availableCities;

    for(const std::string& candidateCity: cityNames)
    {
        std::pair<std::string, std::string> pair = std::make_pair(city, candidateCity);

        auto it1 = distanceMatrix.find(pair);
        auto it2 = std::find(path.begin(), path.end(), candidateCity);

        if(it1 != distanceMatrix.end() && it1 -> second > 0 && it2 == path.end())
        {
            availableCities.push_back(candidateCity);
        }
    }

    return availableCities;
}

std::vector<Chromosome> initializePopulation(const std::map<std::pair<std::string, std::string>, int>& distanceMatrix, const int& populationSize, const int& numCities, const std::vector<std::string>& cityNames)
{
    std::vector<Chromosome> population(populationSize);

    for(int i = 0; i < populationSize; i++)
    {   
        population[i].path.push_back(cityNames[get_random_in_range(0, cityNames.size() - 1)]);

        std::cout << population[i].path.back();
        
        while(population[i].path.size() != numCities)
        {
            std::vector<std::string> availableCities = listAvailableCities(distanceMatrix, population[i].path.back(), cityNames, population[i].path);

            if(availableCities.empty())
            {
                population[i].path.clear();
                population[i].path.push_back(cityNames[get_random_in_range(0, cityNames.size() - 1)]);
            }
            else
            {
                population[i].path.push_back(availableCities[get_random_in_range(0, availableCities.size() - 1)]);
                std::cout << ", " << population[i].path.back();
            }
            
        }
        std::cout << std::endl;
    }

    return population;
}