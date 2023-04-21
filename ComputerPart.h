#pragma once
#include<iostream>

class ComputerPart
{
public:
	ComputerPart();
	ComputerPart(const unsigned& typeVal, const float& priceVal, const char* brandVal, const char* modelAddr, const unsigned& warrantyVal);
	ComputerPart(const ComputerPart& cp);
	
	unsigned getType() const                      {return type;};
	float getPrice() const						  {return price;};
	const char* getBrand() const                  {return brandAddr;};
	const char* getModel() const                  {return modelAddr;};
	unsigned getWarranty() const                  {return warranty;};
	
	void setPrice(const float& newPrice);
	
	ComputerPart& operator=(const ComputerPart& rhs);
	bool operator==(const ComputerPart& rhs);
	
	~ComputerPart();
private:
	unsigned type;
	float price;
	char* brandAddr;
	char* modelAddr;
	unsigned warranty;

	void copy(const unsigned typeVal, const float priceVal, const char* brandAddr, const char* modelAddr, const unsigned warrantyVal);
	void clear();
};