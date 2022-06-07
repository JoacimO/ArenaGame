#pragma once
#include <vector>
#include <string>
#include <iostream>
class LocationOption
{
public:
	LocationOption(int lenght, std::string optionName);
	void addLocationAlternativeName(std::string name);
	std::string getOptionName(int index);
	void printOptionAlternatives();
	int getNumOfAlternatives();
private:
	std::vector<std::string> mOptionAlternatives;
	std::string mOptionName;
	int mNumOfAlternatives;
};