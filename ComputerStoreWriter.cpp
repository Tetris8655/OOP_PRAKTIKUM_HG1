#include"ComputerStoreWriter.h"
#include"ComputerPartWriter.h"

void ComputerStoreWriter::write(const ComputerStore& cs, const char* filePathAddr)
{
	output.open(filePathAddr,std::ios::out | std::ios::app);
	if (!output) return;

	size_t size = cs.getISize();
	ComputerPartWriter cpw;

	output << cs.getName() << "\n" 
		   << cs.getWorkTime() << "\n" 
		   << size << "\n\n[\n";

	for (size_t i = 0; i < size; ++i) 
	{
		output << "\t";
		output.close();
		cpw.writeToFile(cs.getStock()[i].cp, filePathAddr);
		output.open(filePathAddr, std::ios::out | std::ios::app);
	}
	output << "]\n" << cs.getProfit() << "\n";
	output.close();
}