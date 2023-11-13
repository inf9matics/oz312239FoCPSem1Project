#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include "geneticAlgorithm.h"
#include "calculateDistance.h"
#include "distanceMatrix.h"

int main(){
    srand(time(0));
    
    int populationSize = std::rand() % 40 + 10;
    int generations = std::rand() % 1000 + 1;
    int numCities = 0;

    // Initialization of a "map"
    std::vector<std::vector<int>> distMatrix = distanceMatrix();
    
    for(int i = 0; i < ; i++){
        if(distMatrix[i] != ' '){
            numCities++;
        }
    }

    // Initializing population
    std::vector<Chromosome> population = initializePopulation(populationSize, numCities);

    // Main loop
    for(int generation = 0; generation < generations; generation++){
        // Calcute fitness
        for(Chromosome& chromosome : population){ // Loop iterates for every chromosome in the population
            if(chromosome.fitness == 0){
                chromosome.fitness = calculateDistance(chromosome.path, distMatrix);
            }
        }

        // Sort population based on fitness
        for(int i = 0; i < populationSize; i++){ // There's propably a better way to do it
            for(int j = i; j < populationSize; j++){
                if(population[i].fitness > population[j].fitness){
                    std::swap(population[i], population[j]);
                }
            }
        }

        // Display best fitness
        std::cout<< "Generation = " << generation + 1<< "   Best path length = " <<population[0].fitness << std::endl;

        // Select top 10% (elite) of population to breed
        int eliteSize = (populationSize > 0) ? populationSize / 10 : 1; // For this to work population size has to greater than 10, TODO find a fix
        std::vector<Chromosome> elite(population.begin(), population.begin() + eliteSize);

        // Breed and mutate offsprings
        std::vector<Chromosome> offspring;
        for(int i = 0; i < populationSize - populationSize/10; i++){
            int parent1 = std::rand() % eliteSize;
            int parent2 = std::rand() % eliteSize;
            Chromosome child = crossover(elite[parent1], elite[parent2]);
            if(std::rand() % 100 < 10){ //Implementing 10% chance to mutate child's path
                mutate(child);
            }
            offspring.push_back(child);
        }
        // Combine elite and offspring to create next generation
        population = elite;
        population.insert(population.end(), offspring.begin(), offspring.end());
    }

    //Display best solution after all generations
    std::cout<<"Best path = ";
    for (int i = 0; i < numCities; i++) {
        std::cout << population[0].path[i] << ", ";
    }

    std::cout<< std::endl;
    std::cout<< "Best distance = " << population[0].fitness <<std::endl;
    
    return 0;
}