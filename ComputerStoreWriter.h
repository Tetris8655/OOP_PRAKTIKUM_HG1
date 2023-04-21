#pragma once
#include"ComputerStore.h"
#include<fstream>

class ComputerStoreWriter 
{
public:
	void write(const ComputerStore& cs, const char* filePathAddr);
private:
	std::ofstream output;
};
