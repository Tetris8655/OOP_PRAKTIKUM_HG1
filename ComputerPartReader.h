#pragma once
#include"ComputerPart.h"
#include<fstream>

class ComputerPartReader 
{
public:
	ComputerPart readFromFile(const char* filePathAddr);

private:
	std::ifstream input;
};
