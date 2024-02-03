#include <iostream>
#include <string>

#include "utilities.h"

int main(int argc, char* argv[]) // https://tug.org/texlive/
{
    std::string inputFileName;
    std::string outputFileName;

    if(argc < 5) 
    {
        std::cerr << "Proper use of the program:\n"
                  << "? -i <input file name> -o <output file name>\n";
        return 1;
    }

    for (int i = 1; i < argc; i++) 
    {
        std::string arg = argv[i];
        if (arg == "-i") 
        {
            if (i + 1 < argc) 
            { 
                inputFileName = argv[i++]; 
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
                outputFileName = argv[i++];
            } else 
            {
                std::cerr << "-o option requires one argument.\n";
                return 1;
            }
        }
    }

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