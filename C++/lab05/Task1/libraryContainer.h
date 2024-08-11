#include <set>
#include <string>

std::multiset<std::string> readMultiset(std::string filePath);

void printMultiset(std::string operation, std::string filePath, std::multiset<std::string> container);

std::multiset<std::string> multisetUnion(std::multiset<std::string> setA, std::multiset<std::string> setB);

std::multiset<std::string> multisetIntersection(std::multiset<std::string> setA, std::multiset<std::string> setB);

std::multiset<std::string> multisetDifference(std::multiset<std::string> setA, std::multiset<std::string> setB);