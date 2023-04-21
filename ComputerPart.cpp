#include"ComputerPart.h"
#include<cstring>

ComputerPart::ComputerPart()
{
	copy(0, 0, "\0", "\0", 0);
}

ComputerPart::ComputerPart(const unsigned& typeVal, const float& priceVal, const char* brandAddr, const char* modelAddr, const unsigned& warrantyVal)
{
	if(typeVal > 6) throw std::invalid_argument("INVALID TYPE!\n");
	if (priceVal < 0.0f) throw std::invalid_argument("INVALID PRICE!\n");
	
	copy(typeVal, priceVal, brandAddr, modelAddr, warrantyVal);
}

ComputerPart::ComputerPart(const ComputerPart& other)
{
	copy(other.type, other.price, other.brandAddr, other.modelAddr, other.warranty);
}

void ComputerPart::setPrice(const float& newPrice)
{
	if (newPrice < 0.0f) throw std::invalid_argument("INVALID PRICE!\n");

	price = newPrice;
}

ComputerPart& ComputerPart::operator=(const ComputerPart& other)
{
	if(this != &other)
	{
		clear();
		copy(other.type, other.price, other.brandAddr, other.modelAddr, other.warranty);
	}
	
	return *this;
}

bool ComputerPart::operator==(const ComputerPart& rhs) 
{
	return type == rhs.type
		&& price == rhs.price
		&& !strcmp(brandAddr, rhs.brandAddr)
		&& !strcmp(modelAddr, rhs.modelAddr)
		&& warranty == rhs.warranty;
}

ComputerPart::~ComputerPart()
{
	clear();
}

void ComputerPart::copy(const unsigned typeVal, const float priceVal, const char* brandAddr, const char* modelAddr, const unsigned warrantyVal)
{
	this->brandAddr = new char[strlen(brandAddr) + 1];
	this->modelAddr = new char[strlen(modelAddr) + 1];
	
	type = typeVal;
	price = priceVal;
	strcpy_s(this->brandAddr, strlen(brandAddr) + 1, brandAddr);
	strcpy_s(this->modelAddr, strlen(modelAddr) + 1, modelAddr);
	warranty = warrantyVal;
}


void ComputerPart::clear()
{
	delete[] brandAddr;
	delete[] modelAddr;
}