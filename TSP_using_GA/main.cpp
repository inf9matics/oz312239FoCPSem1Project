#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

#include "utils.h"
#include "geneticAlgorithm.h"

int main(int argc, char *argv[]) // .\build\project\project -i .\\TSP_using_GA\\input.txt -o .\\TSP_using_GA\\output.txt -g 30 -n 1000
{
    std::string inputFileName;
    std::string outputFileName;
    int generations = 0;
    int populationSize = 0;

    if(argc < 9) 
    {
        std::cerr << "Proper use of the program:\n"
                  << "project.exe -i <input file name> -o <output file name> -g <number of generations> -n <number of individuals in a generation(at least 100)>\n";
        return 1;
    }

    for (int i = 1; i < argc; i++) 
    {
        std::string arg = argv[i];
        if (arg == "-i") 
        {
            if (i + 1 < argc) 
            { 
                inputFileName = argv[++i]; 
            } 
            else 
            { 
                std::cerr << "-i option requires one argument.\n";
                return 1;
            }
        } 
        else if (arg == "-o") 
        {
            if (i + 1 < argc) 
            {
                outputFileName = argv[++i];
            } else 
            {
                std::cerr << "-o option requires one argument.\n";
                return 1;
            }
        } 
        else if (arg == "-g") 
        {
            if (i + 1 < argc) 
            {
                generations = std::atoi(argv[++i]);
            } 
            else 
            {
                std::cerr << "-g option requires one argument.\n";
                return 1;
            }
        } 
        else if (arg == "-n") 
        {
            if (i + 1 < argc) 
            {
                populationSize = std::atoi(argv[++i]);
            } 
            else 
            {
                std::cerr << "-n option requires one argument.\n";
                return 1;
            }
        }
    }

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