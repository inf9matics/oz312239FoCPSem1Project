#pragma once

#include <fstream>
#include <string>
#include <set>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <algorithm>

struct Edge
{
    int a, b;
    float weight;
    Edge(int A, int B, float D) : a(A), b(B), weight(D) {}
};

class OrderedSet 
{
private:
    std::vector<std::string> vector;
    std::set<std::string> set;

public:
    void insert(std::string value);
    const std::vector<std::string>& values() const; 
    int find(const std::string& x) const;
};

class UnionFind
{
private:
    std::vector<int> parent;
    std::vector<int> rank;
    
public:
    UnionFind(int size);
    int find(int x);
    void unionSets(int x, int y);
};

void readFromInput(const std::string& inputFileName, OrderedSet& cityNames, std::vector<Edge>& edges);
std::vector<Edge> kruskal(std::vector<Edge>& edges, const int& n);
void print(const std::string& outputFileName, const OrderedSet& cityNames, const std::vector<Edge>& mst);