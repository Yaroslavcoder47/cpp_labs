#include <vector>
#include <string>

std::vector<size_t> readContainerOfData(std::string filePath);

std::vector<std::string> readContainerOfCommands(std::string filePath);

void makeOperations(std::string filePaht, std::vector<size_t>& containerOfData, 
	std::vector<std::string>& containerOfCommands);
