std::vector<std::string> readcityNames(const std::string& "map.txt"){
    std::vector<std::string> cityNames;
    std::ifstream list("map.txt");
    std::string cityName;
    while (list >> cityName){
        cityNames.push_back(cityName);
    }
    list.close();
    return cityNames;
}