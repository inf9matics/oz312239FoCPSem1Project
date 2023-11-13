// Function to calculate distance of a path
int calculateDistance(const std::vector<char>& path, const std::vector<std::vector<int>>& distMatrix){
    int distance = 0;
    int numCities = path.size();
    for(int i = 0; i < numCities - 1; i++){
        distance += distMatrix[path[i]][path[i + 1]];;
    }
     distance += distMatrix[path[numCities - 1]][path[0]]; // Return to the starting city
    return distance;
}