#pragma once
#include <fstream>
#include <string>
#include <set>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <algorithm>

/**
 * @brief Represents an edge in a graph with nodes and a weight.
 */
struct Edge
{
    int node1,node2; /**< Nodes connected by the edge. */
    float weight; /**< Weight of the edge. */
    /**
     * @brief Constructs an Edge with the given parameters.
     *
     * @param N1 The first node.
     * @param N2 The second node.
     * @param D The weight of the edge.
     */
    Edge(int N1, int N2, float D) : node1(N1),node2(N2),weight(D) {}
};
/**
 * @brief Represents a set of ordered unique strings with associated vector and set data structures.
 */
class OrderedSet
{
    private:
        std::vector<std::string> vector; /**< Internal vector storing ordered unique strings. */
        std::set<std::string> set; /**< Internal set for quick insertion check. */
    public:
        /**
         * @brief Inserts a value into the OrderedSet if it's not already present and updates the internal vector.
         *
         * @param value The string value to be inserted.
         */
        void insert(std::string value);
        /**
         * @brief Returns a const reference to the internal vector containing values of the OrderedSet.
         *
         * @return Const reference to the internal vector of string values.
         */
        const std::vector<std::string>& values() const;
        /**
         * @brief Finds the index of the given string in the internal vector of the OrderedSet.
         *
         * @param x The string to be searched in the internal vector.
         * @return Index of the string if found, otherwise -1.
         */
        int find(const std::string& x) const;
};
/**
 * @brief Represents a Union-Find data structure for efficient set union and find operations.
 */
class UnionFind
{
    private:
        std::vector<int> parent; /**< Parent array for Union-Find. */
        std::vector<int> rank; /**< Rank array for Union-Find. */
    public:
        /**
         * @brief Constructs an instance of UnionFind with the specified size.
         *
         * Initializes parent and rank vectors for UnionFind with the given size.
         *
         * @param size The size of the UnionFind data structure.
         */
        explicit UnionFind(int size);
        /**
         * @brief Finds the root of the set containing the element x using path compression.
         *
         * @param x The element for which to find the root.
         * @return The root of the set containing x.
         */
        int find(int x);
        /**
         * @brief Unions two sets based on their ranks to maintain balance.
         *
         * Unions the sets represented by the given elements x and y based on their ranks.
         *
         * @param x The representative of the first set.
         * @param y The representative of the second set.
         */
        void unionSets(int x,int y);
};
/**
 * @brief Reads input from a file and populates an OrderedSet and a vector of Edges.
 *
 * Reads input from the specified input file, extracts city names and distances,
 * and populates the OrderedSet with city names and the vector of Edges with corresponding information.
 *
 * @param inputFileName The name of the input file.
 * @param cityNames Reference to an OrderedSet to store city names.
 * @param edges Reference to a vector of Edges to store the graph edges.
 */
void readFromInput(const std::string& inputFileName,OrderedSet& cityNames,std::vector<Edge>& edges);
/**
 * @brief Applies Kruskal's algorithm to find the Minimum Spanning Tree of a graph.
 *
 * Sorts the edges based on weight and applies Kruskal's algorithm to find the Minimum Spanning Tree.
 *
 * @param edges Reference to a vector of Edges representing the graph.
 * @param n The number of nodes in the graph.
 * @return Vector of Edges representing the Minimum Spanning Tree.
 */
std::vector<Edge> kruskal(std::vector<Edge>& edges,const int& n);
/**
 * @brief Writes the Minimum Spanning Tree information to an output file.
 *
 * Writes the Minimum Spanning Tree information, including city names and edge weights, to the specified output file.
 *
 * @param outputFileName The name of the output file.
 * @param cityNames Reference to an OrderedSet containing city names.
 * @param mst Reference to a vector of Edges representing the Minimum Spanning Tree.
 */
void print(const std::string& outputFileName,const OrderedSet& cityNames,const std::vector<Edge>& mst);
