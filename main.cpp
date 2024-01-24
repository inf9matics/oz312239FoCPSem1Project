#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "utils.h"
#include "geneticAlgorithm.h"

int main(/*int argc, char *argv[]*/)
{
    // Temporary solution for debugging
    std::string inputFileName = "input.txt"; 
    std::string outputFileName = "output.txt";
    int generations = 30;
    int populationSize = 500;

    // Checks for proper input values
    /*if(argc < 9) 
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
    int populationSize = std::stoi(argv[8]);*/

    // Reading data from a file
    std::vector<int> cities;
    std::vector<std::string> cityNames;
    std::vector<std::vector<int>> distanceMatrix;
    try
    {
        cityNames = readInputFile(inputFileName, distanceMatrix, cities);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }

    // Initialization of population
    std::vector<Chromosome> population = initializePopulation(distanceMatrix, cities, populationSize);

    std::ofstream outputFile(outputFileName); 

    // Main loop
    for(int generation = 0; generation < generations; generation++) 
    {
        // Calculate fitness, and sort
        sort(distanceMatrix, population);

        // Outputting best solution for each genereation into a file
        outputBestSolution(outputFile, generation, population[0], cityNames);

        // Generating next generation based on top 10% of the previous one
        breedNextPopulation(distanceMatrix, population);
    }

    outputFile.close();
    return 0;
}