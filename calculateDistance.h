// Function to calculate distance of a path
int calculateDistance(const std::vector<int>& path, const std::vector<std::vector<int>>& distanceMatrix){
    int distance = 0;
    int numCities = path.size();
    for(int i = 0; i < numCities - 1; i++){
        distance += distanceMatrix[path[i]][path[i + 1]];
    }
    distance += distanceMatrix[path[numCities - 1]][path[0]]; // Return to the starting city
    return distance;
}