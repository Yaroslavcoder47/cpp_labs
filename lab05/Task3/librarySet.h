#include <vector>
#include <string>
#include <map>

std::string readStrings(std::string filePath);

std::string changeString(std::string& text);

std::map<std::string, size_t> createMap(std::string str, std::map<std::string, size_t>& container);

void printMap(std::string filePath, std::map<std::string, size_t> container);