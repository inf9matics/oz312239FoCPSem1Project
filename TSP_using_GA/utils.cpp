#include "utils.h"

bool isNumber(const std::string& s)
{
    for (char const &ch : s) 
    {
        if (std::isdigit(ch) == 0) 
        {
            return false;
        }
    }
    return true;
}

std::vector<std::string> readInputFile(const std::string& inputFileName, std::vector<std::vector<int>>& distanceMatrix, std::vector<int>& cities)
{
    std::ifstream inputFile(inputFileName);

    if(!inputFile.is_open())
    {
        throw std::runtime_error("There is an issue with your input file.");
    }

    std::vector<std::string> cityNames;
    std::string line;

    if(getline(inputFile, line))
    {
        std::istringstream iss(line);
        std::string cityName;

        while(iss >> cityName)
        {   
            cityNames.push_back(cityName);
        }
    }

    int numCities = cityNames.size();

    distanceMatrix.resize(numCities, std::vector<int>(numCities, 0));

    for(int i = 0; i < numCities; i++)
    {
        cities.push_back(i);

        for(int j = 0; j < numCities; j++)
        {
            inputFile >> distanceMatrix[i][j];
        }
    }

    inputFile.close();

    return cityNames;    
}

void outputBestSolution(std::ofstream& outputFile, const int& generation, const Chromosome& chromosome, const std::vector<std::string>& cityNames)
{
    outputFile << "\nGeneration " << generation + 1 << ", length " << chromosome.fitness << "\n"; 
    for(const int& city : chromosome.path)
    {
        outputFile << cityNames[city] << " ";
    }
}

void calculateDistance(const std::vector<std::vector<int>>& distanceMatrix, Chromosome& chromosome)
{
    for(int i = 0; i < chromosome.path.size() - 1; i++)
    {
        chromosome.fitness += distanceMatrix[chromosome.path[i]][chromosome.path[i+1]];
    }  
}

bool compareChromosomes(const Chromosome& a, const Chromosome& b)
{
    return a.fitness < b.fitness;
}

void sort(const std::vector<std::vector<int>>& distanceMatrix, std::vector<Chromosome>& population)
{
    for(Chromosome& chromosome : population) 
    {
        if(chromosome.fitness == 0)
        {
            calculateDistance(distanceMatrix, chromosome);
        }
    }

    std::sort(population.begin(), population.end(), compareChromosomes);
}