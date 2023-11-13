// Structure to represent a chromosome (a potential solution)
struct Chromosome {
    std::vector<int> path;
    int fitness = 0;
};

/// Function to initialize population
std::vector<Chromosome> initializePopulation(int populationSize, int numCities){
    std::vector<Chromosome> population(populationSize);
    for(int i = 0; i < populationSize; i++){
        population[i].path.resize(numCities);
        for(int j = 0; j < numCities; j++){
            population[i].path[j] = j; /// Initializing with path 0, 1, 2 ... numCities - 1
        }
        std::random_shuffle(population[i].path.begin() + 1, population[i].path.end()); /// Randomizing order to create diversity in first population
        population[i].fitness = 0; /// Setting fitness to 0, for later calculation
    }
    return population;
}

// Function to breed two chromosomes
Chromosome crossover(const Chromosome& parent1, const Chromosome& parent2){
    int numCities = parent1.path.size(); // Initializing number of cities in this function
    Chromosome child; // Initializing a child
    int crossoverPoint = std::rand() % (numCities - 1) + 1; // Randomly choosing crossover point, excluding first city
    std::copy_n(parent1.path.begin(), crossoverPoint, std::back_inserter(child.path));
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