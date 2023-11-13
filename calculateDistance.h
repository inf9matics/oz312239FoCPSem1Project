// Function to calculate distance of a path
int calculateDistance(const std::vector<char>& path, const std::vector<std::vector<int>>& distanceMatrix){
    int distance = 0;
    int numCities = path.size();
    for(int i = 0; i < numCities - 1; i++){
        distance += distanceMatrix[path[i] - 'A'][path[i + 1] - 'A'];
    }
    distance += distanceMatrix[path[numCities - 1] - 'A'][path[0] - 'A']; // Return to the starting city
    return distance;
}