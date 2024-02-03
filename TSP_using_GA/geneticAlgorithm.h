/**
 * @file geneticAlgorithm.h
 * @author Oliwier Zasadni
 * 
 */

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <random>
#include <algorithm>

struct Chromosome
{
    std::vector<int> path;
    int fitness = 0;
};

/**
 * @brief Generates a random integer within a specified range.
 * 
 * This function utilizes a Mersenne Twister engine to generate a uniformly distributed
 * random integer within the given range. It's often used for selecting random elements
 * or determining random events within the genetic algorithm.
 *
 * @param from The lower bound of the range (inclusive).
 * @param to The upper bound of the range (inclusive).
 * @return A randomly generated integer within the specified range.
 */
int get_random_in_range(int from, int to);

/**
 * @brief Checks if there is a connection between two cities in a distance matrix.
 * 
 * The function evaluates the presence of a path or connection between two cities
 * by looking up their corresponding entry in the distance matrix. A value greater
 * than zero indicates a connection.
 *
 * @param distanceMatrix The matrix representing distances between cities.
 * @param city1 Index of the first city.
 * @param city2 Index of the second city.
 * @return True if there is a connection, false otherwise.
 */
bool checkConnection(const std::vector<std::vector<int>>& distanceMatrix, const std::vector<int>& path, const int& city);

/**
 * @brief Checks if a city has already been visited in a given path.
 * 
 * This function determines whether a city is already part of the path, helping to
 * avoid revisits in a path which is crucial for problems like the Traveling Salesman Problem.
 *
 * @param distanceMatrix The matrix representing distances between cities (unused in this function).
 * @param path The current path being evaluated.
 * @param city The city to check for in the path.
 * @return True if the city has not been visited, false if it has.
 */
bool pathBack(const std::vector<std::vector<int>>& distanceMatrix, const std::vector<int>& path);

/**
 * @brief Validates a given path to ensure all connections are valid and cities are not revisited.
 * 
 * This function is critical in ensuring that a generated path in the genetic algorithm
 * represents a valid solution. It checks for the existence of connections between
 * consecutive cities and ensures no city is visited more than once.
 *
 * @param distanceMatrix The matrix representing distances between cities.
 * @param path The path to validate.
 * @return True if the path is valid, false otherwise.
 */
bool checkPath(const std::vector<std::vector<int>>& distanceMatrix, const std::vector<int>& path);

/**
 * @brief Initializes a population of chromosomes for the genetic algorithm.
 * 
 * This function creates an initial population of chromosomes, where each chromosome
 * represents a potential solution to the problem. Each path in the chromosome is
 * randomly shuffled to ensure diversity in the initial population.
 *
 * @param distanceMatrix The matrix representing distances between cities.
 * @param cities The list of cities to include in the chromosomes.
 * @param populationSize The size of the population to initialize.
 * @return A vector of initialized Chromosomes.
 */
std::vector<Chromosome> initializePopulation(const std::vector<std::vector<int>>& distanceMatrix, const std::vector<int>& cities, const int& populationSize);

/**
 * @brief Performs crossover operation to generate a new chromosome from two parent chromosomes.
 * 
 * This function combines segments of two parent paths to create a child chromosome. It involves
 * copying a segment of one parent's path up to a random crossover point and then filling the
 * remainder of the path with cities from the second parent's path, maintaining the constraints
 * of the problem (like ensuring no city is visited twice and each connection is valid).
 *
 * @param distanceMatrix The matrix representing distances between cities.
 * @param path1 The path of the first parent chromosome.
 * @param path2 The path of the second parent chromosome.
 * @return A new Chromosome resulting from the crossover of the two parents. If the resulting
 *         path is invalid, the first parent's path is returned.
 */
Chromosome crossover(const std::vector<std::vector<int>>& distanceMatrix, const std::vector<int>& path1, const std::vector<int>& path2);

/**
 * @brief Breeds the next generation of chromosomes from the current population.
 * 
 * This function selects the top-performing chromosomes (elite) and uses them to breed
 * the next generation. The breeding involves randomly selecting pairs from the elite
 * group and performing crossover to produce offspring. The new generation is a mix
 * of these offspring and the elite chromosomes.
 *
 * @param distanceMatrix The matrix representing distances between cities.
 * @param population The current population of chromosomes.
 */
void breedNextPopulation(const std::vector<std::vector<int>>& distanceMatrix, std::vector<Chromosome>& population);