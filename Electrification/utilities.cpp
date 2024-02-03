#include "utilities.h"

void OrderedSet::insert(std::string value) 
{
    if (set.insert(value).second) 
    {
        vector.push_back(value);
    }
}

const std::vector<std::string>& OrderedSet::values() const 
{
    return vector;
}

int OrderedSet::find(const std::string& x) const
{
    auto it = std::find(vector.begin(), vector.end(), x);
    if(it != vector.end())
    {
        return std::distance(vector.begin(), it);
    }
    else
    {
        return -1;
    }
}

void readFromInput(const std::string& inputFileName, OrderedSet& cityNames, std::vector<Edge>& edges)
{
    std::ifstream inputFile(inputFileName);

    if(!inputFile.is_open())
    {
        throw std::runtime_error("There is an issue with your input file.");
    }

    std::string line;
    while(std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        std::string city1, city2;
        float d = 0;

        if (iss >> city1 >> city2 >> d) {
            cityNames.insert(city1);
            cityNames.insert(city2);
            int c1n = cityNames.find(city1);
            int c2n = cityNames.find(city2);
            edges.emplace_back(c1n, c2n, d);
            edges.emplace_back(c2n, c1n, d);
        }
    }

    inputFile.close();
}

UnionFind::UnionFind(int size) : parent(size), rank(size, 0)
{
    for(int i = 0; i < size; i++)
    {
        parent[i] = i;
    }
}

int UnionFind::find(int x)
{
    if(parent[x] != x)
    {
        parent[x] = find(parent[x]);
    }

    return parent[x];
}

void UnionFind::unionSets(int x, int y)
{
    int rootX = find(x), rootY = find(y);
    if (rootX != rootY) 
    {
        if (rank[rootX] < rank[rootY]) 
        {
            parent[rootX] = rootY;
        }
        else 
        {
            if (rank[rootX] == rank[rootY]) 
            {    
                rank[rootX]++;
            }
            parent[rootY] = rootX;
        }
    }
}

std::vector<Edge> kruskal(std::vector<Edge>& edges, const int& n)
{
    std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b){return a.weight < b.weight;});

    UnionFind uf(n);
    std::vector<Edge> mst;

    for(const Edge& e : edges)
    {
        if(uf.find(e.a) != uf.find(e.b))
        {
            mst.push_back(e);
            uf.unionSets(e.a, e.b);
        }
    }

    return mst;
}

void print(const std::string& outputFileName, const OrderedSet& cityNames, const std::vector<Edge>& mst)
{
    std::ofstream outputFile(outputFileName);

    if(!outputFile.is_open())
    {
        throw std::runtime_error("There is an issue with your output file.");
    }

    outputFile << "MST: \n";

    for(int i = 0; i < mst.size(); i++)
    {
        outputFile << cityNames.values().at(mst[i].a) << " - " 
                   << cityNames.values().at(mst[i].b) << " "
                   << mst[i].weight << "\n";
    }

    outputFile.close();
}