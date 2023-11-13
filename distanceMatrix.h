std::vector<std::string> stringToStringVector(std::string str){ // There's propably a better way to do it
    std::vector<std::string> vector;
    std::string currentString;
    for(int i=0; i<str.size(); i++){
        std::string currentChar(1, str.at(i));
        if(currentChar != " "){
            currentString.append(currentChar);
        }
        else{
            vector.push_back(currentString);
            currentString.clear();
        }
    }
    vector.push_back(currentString);
    
    return vector;
}

std::vector<std::vector<int>> distanceMatrix(){
    std::ifstream map;
    std::string cities;
    int numCities = 1;

    map.open("map.txt"); // Opening file containing a map of cities
    getline(map,cities);

    for(int i = 0; i < cities.length(); i++){ // Calculating number of cities in provided map
        if(cities[i] == ' '){
            numCities++;
        }
    }
    
    std::vector<std::vector<int>> distanceMatrix(numCities, std::vector<int>(numCities, 0));

    for (int i = 0; i < numCities; i++) { // Inputing data from text file to vector
            getline(map,cities);
            for (int j = 0; j < numCities; j++) {
                if (i != j) {
                    std::vector<std::string> citiesVector = stringToStringVector(cities);
                    int num = std::stoi(citiesVector.at(j));
                    distanceMatrix[i][j] = num;
                }
            }
        }
    
    map.close();

    return distanceMatrix;
}