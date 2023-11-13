std::vector<std::string> readCityNames(const std::string& fileName) {
    std::vector<std::string> cityNames;
    std::ifstream cities(fileName);
    std::string cityName;
    while (cities >> cityName) {
        cityNames.push_back(cityName);
    }
    cities.close();
    return cityNames;
}