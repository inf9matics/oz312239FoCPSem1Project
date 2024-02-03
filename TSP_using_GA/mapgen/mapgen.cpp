#include <fstream>
#include <random>
#include <chrono>
#include <iomanip>

int get_random_in_range(int from = std::numeric_limits<int>::min(), int to = std::numeric_limits<int>::max())
{
    static std::mt19937 generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(from, to);
    return distribution(generator);
}

int main() // Code that generates random maps for inputs
{
    std::ofstream outputFile("funnylittlemap.txt");    

    int x = 10; // Map size
    int map[x][x];

    for(int i = 0; i < x; i++)
    {
        outputFile << std::setw(5) << i;
    }

    outputFile << "\n";

    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < x; j++)
        {
            if(i != j)
            {
                if(map[j][i] > 0)
                {
                    map[i][j] = get_random_in_range(-1, 100);
                }
                else
                {
                    map[i][j] = get_random_in_range(1, 100);
                }
            }
            else
            {
                map[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < x; j++)
        {
            outputFile << std::setw(5) << map[i][j];
        }

        outputFile << "\n";
    }

    return 0;
}