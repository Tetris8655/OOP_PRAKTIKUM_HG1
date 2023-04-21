#include"ComputerPartWriter.h"

void ComputerPartWriter::writeToFile(const ComputerPart& cp, const char* filePathAddr)
{
	output.open(filePathAddr, std::ios::out | std::ios::app);
	if (!output) throw std::invalid_argument("INVALID FILE PATH!\n");
	
	output << "{";
	switch(cp.getType())
	{
		case 0:
			output << "COMPUTER";
			break;
		case 1:
			output << "LAPTOP";
			break;
		case 2:
			output << "MOUSE";
			break;
		case 3:
			output << "KEYBOARD";
			break;
		case 4:
			output << "MONITOR";
			break;
		case 5:
			output << "HEADPHONES";
			break;
		case 6:
			output << "COMPUTER";
			break;
	};
	output << "|" << cp.getBrand() << "|" << cp.getModel() << "|" << cp.getWarranty() << "|" << cp.getPrice() << "}\n";
	
	output.close();
}