#include "geneticAlgorithm.h"

int get_random_in_range(int from, int to) 
{
    static std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(from, to);
    return distribution(generator);
}

void listAvailableCities(const std::vector<int>& path1, const std::vector<int>& path2, std::vector<int>& availableCities)
{
    int city = path1.back();

    for (const int& candidateCity : path2)
    {
        if (distanceMatrix[city][candidateCity] > 0 && std::find(path1.begin(), path1.end(), candidateCity) == path1.end())
        {
            availableCities.push_back(candidateCity);
        }
    }
}

bool pathBack(const std::vector<int>& path)
{
    return distanceMatrix[path.front()][path.back()] > 0;
}

std::vector<Chromosome> initializePopulation(int populationSize)
{
    std::vector<Chromosome> population(populationSize);

    for(int i = 0; i < populationSize; i++) // Function that randomly fills chromosome's paths
    {   
        int randomCity = cities[get_random_in_range(0, cities.back())];
        population[i].path.push_back(randomCity); 
        
        while(population[i].path.size() != cities.size())
        {
            std::vector<int> availableCities;

            listAvailableCities(population[i].path, cities, availableCities);

            if(availableCities.empty()) //In case there would be no available cities, the whole path is cleared to be filled once again
            {
                population[i].path.clear();
                population[i].path.push_back(randomCity);
            }
            else
            {
                population[i].path.push_back(availableCities[get_random_in_range(0, availableCities.size() - 1)]);
            }            
        }

        if(!pathBack(population[i].path))
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

Chromosome crossover(const Chromosome& parent1, const Chromosome& parent2)
{
    int numCities = cities.size();
    int crossoverPoint = get_random_in_range(1, numCities - 1); //Randomly choosing point in which parents' paths get mixed
    
    Chromosome child;

    // Copying first parent's path up to the crossover point
    for(int i = 0; i < crossoverPoint; i++)
    {
        child.path.push_back(parent1.path[i]);
    }
    
    // Copying second parent's path, leaving last city
    for(int i = 0; i < numCities - crossoverPoint; i++)
    {
        std::vector<int> availableCities;
        listAvailableCities(child.path, parent2.path, availableCities);
        child.path.push_back(availableCities[0]);
    }

    if(!pathBack(child.path))
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