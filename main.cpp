#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// Structure to represent a chromosome (a potential solution)
struct Chromosome {
    std::vector<int> path;
    int fitness;
};

// Function to initialize population
// Placeholder

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
// Placeholder

// Function to randomly mutate chromosomes
// Placeholder

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