#include "geneticAlgorithm.h"

int get_random_in_range(int from, int to) 
{
    static std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(from, to);
    return distribution(generator);
}

bool checkConnection(const std::vector<std::vector<int>>& distanceMatrix, const int& city1, const int& city2)
{
    return distanceMatrix[city1][city2] > 0; 
}

bool checkVisitedCities(const std::vector<std::vector<int>>& distanceMatrix, const std::vector<int>& path, const int& city)
{
    return std::find(path.begin(), path.end(), city) == path.end();
}

bool checkPath(const std::vector<std::vector<int>>& distanceMatrix, const std::vector<int>& path)
{
    std::vector<int> visitedCities;
    int numCities = distanceMatrix.size();

    for(int i = 0; i < numCities - 1; i++)
    {
        visitedCities.push_back(path[i]);

        if(!checkConnection(distanceMatrix, path[i], path[i+1]) || !checkVisitedCities(distanceMatrix, visitedCities, path[i+1]))
        {
            return false;
        }
    }

    if(!checkConnection(distanceMatrix, path.back(), path.front()))
    {
        return false;
    }
    
    return true;
}

std::vector<Chromosome> initializePopulation(const std::vector<std::vector<int>>& distanceMatrix, const std::vector<int>& cities, const int& populationSize)
{
    std::vector<Chromosome> population(populationSize);

    for(int i = 0; i < populationSize; i++) // Function that randomly fills chromosome's paths
    {   
        population[i].path = cities; 

        std::shuffle(population[i].path.begin(), population[i].path.end(), std::default_random_engine(std::random_device()()));

        if(!checkPath(distanceMatrix, population[i].path))
        {
            population[i].path.clear();
            i--;
        }
        else
        {
            population[i].path.push_back(population[i].path.front());
        }
    }

    return population;
}

Chromosome crossover(const std::vector<std::vector<int>>& distanceMatrix, const std::vector<int>& path1, const std::vector<int>& path2)
{
    int numCities = path1.size() - 1;
    int crossoverPoint = get_random_in_range(1, numCities - 1); //Randomly choosing point in which parents' paths get mixed
    
    Chromosome child;

    // Copying first parent's path up to the crossover point
    child.path.insert(child.path.begin(), path1.begin(), path1.begin() + crossoverPoint);
    
    // Copying second parent's path, leaving last city
    while(child.path.size() != numCities)
    {
        for(const int& city : path2)
        {
            if(checkConnection(distanceMatrix, child.path.back(), city) && checkVisitedCities(distanceMatrix, child.path, city))
            {
                child.path.push_back(city);
            }
        }
    }

    if(!checkConnection(distanceMatrix, child.path.back(), child.path.front()))
    {
        child.path = path1;
    }
    else
    {
        child.path.push_back(child.path.front());
    }

    
    child.fitness = 0;
    return child;
}

void breedNextPopulation(const std::vector<std::vector<int>>& distanceMatrix, std::vector<Chromosome>& population)
{
    // Picking top 10% of population for breeding
    int eliteSize = population.size() / 10;
    std::vector<Chromosome> elite(population.begin(), population.begin() + eliteSize); 

    // Breeding offspring from elite
    std::vector<Chromosome> offspring;
    for(int i = 0; i < population.size() - eliteSize; i++)
    {
        int parent1 = get_random_in_range(0, eliteSize - 1);
        int parent2 = get_random_in_range(0, eliteSize - 1);
            
        offspring.push_back(crossover(distanceMatrix, elite[parent1].path, elite[parent2].path));
    }

    // Combining elite and offspring into a new population
    population = elite; 
    population.insert(population.end(), offspring.begin(), offspring.end()); 
}