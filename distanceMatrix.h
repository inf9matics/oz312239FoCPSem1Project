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
    int numCities = 0;

    map.open("map.txt");
    getline(map,cities);

    for(int i = 0; i < cities.length(); i++){
        if(cities[i] != ' '){
            numCities++;
        }
    }
    
    std::vector<std::vector<int>> distanceMatrix(numCities, std::vector<int>(numCities, 0));

    for (int i = 0; i < numCities; i++) { // TODO make matrix customizable, and ask about amount of cities
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