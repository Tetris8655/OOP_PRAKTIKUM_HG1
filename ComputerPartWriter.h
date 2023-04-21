#pragma once
#include "ComputerPart.h"
#include<fstream>

class ComputerPartWriter
{
public:
	void writeToFile(const ComputerPart & cp, const char* filePathAddr);

private:
	std::ofstream output;
};