#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// Structure to represent a chromosome (a potential solution)
struct Chromosome {
    std::vector<int> path;
    int fitness = 0;
};

// Function to initialize population
std::vector<Chromosome> initializePopulation(int populationSize, int numCities){
    std::vector<Chromosome> population(populationSize);
    for(int i = 0; i < populationSize){
        population[i].path.resize(numCities);
        for(int j = 0; j < numCities; j++){
            population[i].path[j] = j; // Initializing with path 0, 1, 2 ... numCities - 1
        }
        std::random_shuffle(population[i].path.begin() + 1, population[i].path.end()); // Randomizing order to create diversity in first population
        population[i].fitness = 0; // Setting fitness to 0, for later calculation
    }
    return population;
}

// Function to calculate distance of a path
int CalculateDistance(const std::vector<int>& path, const std::vector<std::vector<int>>& distanceMatrix){
    int distance = 0;
    int numCities = path.size();
    for(int i = 0; i < numCities; i++){
        distance += distanceMatrix[path[i]][path[i + 1]];
    }
    distance += distanceMatrix[path[numCities - 1]][path[0]]; // Return to the starting city
    return distance;
}

// Function to breed two chromosomes
Chromosome crossover(const Chromosome& parent1, const Chromosome& parent2){
    int numCities = parent1.path.size(); // Initializing number of cities in this function
    Chromosome child; // Initializing a child
    int crossoverPoint = std::rand() % (numCities - 1) + 1; // Randomly choosing crossover point, excluding first city
    std::copy_n(parent1.path.begin(), crossoverPoint, std::back_insterter(child.path));
    std::copy_if(parent2.path.begin(), parent2.path.end(), std::back_inserter(child.path), [child](int city){ // Functions that copies rest of the path from second parent
                return std::find(child.path.begin(), child.path.end(), city) == child.path.end(); // Condition, that check whether this city wasn't already in child's path 
                }); // Gonna be completety honest, this solution was achieved with a lot of outside help
    child.fitness = 0;
    return child;
}

// Function to randomly mutate chromosomes
void mutate(Chromosome& chromosome){
    int numCities = chromosome.path.size(); // Initializing number of cities in this function
    int mPoint1 = std::rand() % numCities;
    int mPoint2 = std::rand() % numCities;
    std::swap(chromosome.path[mPoint1], chromosome.path[mPoint2]);
    chromosome.fitness = 0;
}

int main(){
    srand(time(0));
    
    int populationSize = 50;
    int numCities = 5;
    int generations = 30;

    std::vector<std::vector<int>> distanceMatrix(numCities, std::vector<int>(numCities, 0)); // Initialization of a "map"

    for (int i = 0; i < numCities; ++i) {
        for (int j = 0; j < numCities; ++j) {
            if (i != j) {
                distanceMatrix[i][j] = rand() % 91 + 10; // Assignes random distance between 10 and 100
            }
        }
    }

    // Placeholder for initialization of population

    // Main loop
    for(int generation = 0; generation < generations; generation++){
        //Calculate the fitness of generation

        // Sort population based on fitness

        // Display best fitness

        // Select top 10% (elite) of population to breed

        // Breed and mutate

        // Combine elite and offspring to create next generation
    }

    //Display best solution after all generations
    
    return 0;
}