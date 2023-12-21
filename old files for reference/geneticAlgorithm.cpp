#include "geneticAlgorithm.h"

/// @brief Generates a random integer within a specified range [from, to].
/// @param from The lower bound of the range (inclusive).
/// @param to   The upper bound of the range (inclusive).
/// @return A randomly generated integer within the specified range.
int get_random_in_range(int from, int to) 
{
    static std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(from, to);
    return distribution(generator);
}

/// @brief Lists cities that are available for selection based on a given distance matrix, a set of city names, and a current path.
/// @param distanceMatrix A map representing the distances between pairs of cities.
/// @param cityNames      A vector of strings containing the names of all cities.
/// @param path           A vector of strings representing the current path.
/// @return A vector of strings containing the names of cities that are available for selection.
std::vector<std::string> listAvailableCities(const std::map<std::pair<std::string, std::string>, int>& distanceMatrix, const std::vector<std::string>& cityNames, const std::vector<std::string>& path)
{
    std::vector<std::string> availableCities;
    std::string city = path.back();

    for(const std::string& candidateCity: cityNames)
    {
        std::pair<std::string, std::string> pair = std::make_pair(city, candidateCity); // Pairing the current city with one of the others

        auto it1 = distanceMatrix.find(pair);   
        auto it2 = std::find(path.begin(), path.end(), candidateCity);

        if(it1 != distanceMatrix.end() && it1 -> second > 0 && it2 == path.end()) // Check for cities which don't have a valid path, and those who were, already visited
        {
            availableCities.push_back(candidateCity);
        }
    }

    return availableCities;
}

/// @brief Checks if the last city in the path has a valid connection back to the first city based on the distance matrix.
/// @param distanceMatrix A map representing the distances between pairs of cities.
/// @param path           A vector of strings representing the path of cities to be checked.
/// @return True if the last city has a valid connection back to the first city, false otherwise.
bool pathBack(const std::map<std::pair<std::string, std::string>, int>& distanceMatrix, const std::vector<std::string>& path)
{
    std::pair<std::string, std::string> pair = std::make_pair(path.back(), path.front());
    auto it = distanceMatrix.find(pair);

    return it == distanceMatrix.end() || it->second >= 0;
}

/// @brief Initializes a population of chromosomes with random paths based on the given parameters.
/// @param distanceMatrix A map representing the distances between pairs of cities.
/// @param populationSize The size of the population to be generated.
/// @param numCities      The number of cities in each chromosome's path.
/// @param cityNames      A vector of strings containing the names of all cities.
/// @return A vector of Chromosomes representing the initialized population.
std::vector<Chromosome> initializePopulation(const std::map<std::pair<std::string, std::string>, int>& distanceMatrix, const int& populationSize, const int& numCities, const std::vector<std::string>& cityNames)
{
    std::vector<Chromosome> population(populationSize);

    for(int i = 0; i < populationSize; i++) // Function that randomly fills chromosome's paths
    {   
        std::string randomCity = cityNames[get_random_in_range(0, cityNames.size() - 1)];
        population[i].path.push_back(randomCity); 
        
        while(population[i].path.size() != numCities)
        {
            std::vector<std::string> availableCities = listAvailableCities(distanceMatrix, cityNames, population[i].path);

            if(availableCities.empty()) //In case there would be no available cities, the whole path is cleared to be filled once again
            {
                population[i].path.clear();
                population[i].path.push_back(cityNames[get_random_in_range(0, cityNames.size() - 1)]);
            }
            else
            {
                population[i].path.push_back(availableCities[get_random_in_range(0, availableCities.size() - 1)]);
            }            
        }

        if(!pathBack(distanceMatrix, population[i].path))
        {
            population[i].path.clear();
            i--;
        }
        else
        {
            population[i].path.push_back(randomCity);
        }
    }

    return population;
}

/// @brief Performs crossover between two parent chromosomes to generate a child chromosome.
/// @param distanceMatrix A map representing the distances between pairs of cities.
/// @param parent1        The first parent chromosome.
/// @param parent2        The second parent chromosome.
/// @return A Chromosome representing the child chromosome after crossover.
Chromosome crossover(const std::map<std::pair<std::string, std::string>, int>& distanceMatrix, const Chromosome& parent1, const Chromosome& parent2)
{
    int numCities = parent1.path.size() - 1;
    int crossoverPoint = get_random_in_range(1, numCities - 1); //Randomly choosing point in which parents' paths get mixed
    
    Chromosome child;

    // Copying first parents path up to the crossover point
    for(int i = 0; i < crossoverPoint; i++)
    {
        child.path.push_back(parent1.path[i]);
    }
    
    std::vector<std::string> availableCities = listAvailableCities(distanceMatrix, parent2.path, child.path);

    // Copying rest of the path from the second parent
    for(const std::string& city : availableCities)
    {
        child.path.push_back(city);
    }

    if(!pathBack(distanceMatrix, child.path))
    {
        child = parent1;
    }
    else
    {
        child.path.push_back(parent1.path[0]);
    }
    
    child.fitness = 0;
    return child;
}