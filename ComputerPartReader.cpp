#include"ComputerPartReader.h"


ComputerPart ComputerPartReader::readFromFile(const char* filePathAddr)
{
	input.open(filePathAddr);
	if (!input) throw std::invalid_argument("INVALID FILE PATH!\n");
	input.get();

	char type[11], brand[32], model[32];
	unsigned typeID, warranty;
	float price;
	input.get(type, 11, '|');
	input.get();
	input.get(brand, 32, '|');
	input.get();
	input.get(model, 32, '|');
	input.get();
	input >> warranty;
	input.get();
	input >> price;
	input.get();

	input.close();
	
	if (!strcmp(type, "COMPUTER")) typeID = 0;
	else if (!strcmp(type, "LAPTOP")) typeID = 1;
	else if (!strcmp(type, "MOUSE")) typeID = 2;
	else if (!strcmp(type, "KEYBOARD")) typeID = 3;
	else if (!strcmp(type, "MONITOR")) typeID = 4;
	else if (!strcmp(type, "HEADPHONES")) typeID = 5;
	else if (!strcmp(type, "CAMERA")) typeID = 6;

	ComputerPart cp(typeID, price, brand, model, warranty);
	
	return cp;
}
