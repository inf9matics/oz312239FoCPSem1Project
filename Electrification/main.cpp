#include <iostream>
#include <string>

#include "utilities.h"

int main()
{
    std::string inputFileName = "F:\\VSCode\\Final_Project\\Electrification\\input.txt";
    std::string outputFileName = "F:\\VSCode\\Final_Project\\Electrification\\output.txt";

    OrderedSet cityNames;
    std::vector<Edge> edges; 

    try
    {
        readFromInput(inputFileName, cityNames, edges);
        std::vector<Edge> mst = kruskal(edges, cityNames.values().size());
        print(outputFileName, cityNames, mst);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    
    return 0;
}