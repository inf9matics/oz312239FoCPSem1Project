#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <vector>
#include <cmath>
#include <fstream>
#include "utils.h"
#include "geneticAlgorithm.h"

int main(int argc, char *argv[])
{
    // Temporary solution for debugging
    /*std::string inputFileName = "input.txt"; 
    std::string outputFileName = "output.txt";
    int generations = 200;
    int populationSize = 50;*/

    // Checks for proper input values
    if(argc < 9) 
    {
        std::cerr << "Proper use of the program:\n"
                  << "project.exe -i <input file name> -o <output file name> -g <number of generations> -n <number of individuals in a generation(at least 100)>\n";
        return 1;
    }

    std::string inputFileName = argv[2];
    std::string outputFileName = argv[4];
    
    if(!isNumber(argv[6]) || !isNumber(argv[8]) || std::stoi(argv[6]) < 1 || std::stoi(argv[8]) < 100)
    {
        std::cerr << "Number of generations or number of individuals constains invalid data.\n";
        return 1;
    }
    int generations = std::stoi(argv[6]);
    int populationSize = std::stoi(argv[8]);

    std::map<std::pair<std::string, std::string>, int> distanceMatrix = readInputFile(inputFileName);

    // Vector containing names of cities
    std::vector<std::string> cityNames = readCityNames(distanceMatrix); 

    int numCities = cityNames.size();

    // Initialization of population
    std::vector<Chromosome> population = initializePopulation(distanceMatrix, populationSize, numCities, cityNames); 
    // Opening file for output in the main loop
    std::ofstream outputFile(outputFileName); 

    // Main loop
    for(int generation = 0; generation < generations; generation++) 
    {
        // Calculate fitness
        for(Chromosome& chromosome : population) 
        {
            if(chromosome.fitness == 0)
            {
                chromosome.fitness = calculateDistance(distanceMatrix, chromosome.path);
            }
        }

        // Sorting loop
        for(int i = 0; i < populationSize - 1; i++) 
        {
            int min = population[i].fitness;
            int temp = i;
            
            for(int j = i + 1; j < populationSize; j++)
            {
                if(population[j].fitness < min)
                {
                    min = population[j].fitness;
                    temp = j;
                }
            }

            std::swap(population[i], population[temp]);
        }

        // Outputting best solution in the generation
        outputFile << "\nGeneration " << generation + 1 << ", length " << population[0].fitness << "\n"; 
        for(const std::string& cityName : population[0].path)
        {
            outputFile << cityName << " ";
        }

        // Picking top 10% of population for breeding
        int eliteSize = populationSize / 10;
        std::vector<Chromosome> elite(population.begin(), population.begin() + eliteSize); 

        // Breeding offspring from elite
        std::vector<Chromosome> offspring;
        for(int i = 0; i < populationSize - eliteSize; i++)
        {
            int parent1 = get_random_in_range(0, eliteSize - 1);
            int parent2 = get_random_in_range(0, eliteSize - 1);
            
            Chromosome child = crossover(distanceMatrix, elite[parent1], elite[parent2]);
            offspring.push_back(child);
        }

        // Combining elite and offspring into a new population
        population = elite; 
        population.insert(population.end(), offspring.begin(), offspring.end()); 
    }

    outputFile.close();
    return 0;
}