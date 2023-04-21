#pragma once
#include"ComputerPart.h"

struct item 
{
	ComputerPart cp;
	unsigned count = 0;
};

class ComputerStore 
{
public:
	ComputerStore(const char* nameAddr, const char* workTimeAddr, const float& profit);

	const char* getName() const				{ return nameAddr; };
	const char* getWorkTime() const			{ return workTime; };
	float getProfit() const					{ return profit; };
	item* getStock() const					{ return stock; };
	size_t getISize() const					{ return iSize; };

	void addItem(const item& it);
	void removeItem(const item& it);

	void searchComputerParts(unsigned type, const char* brandAddr);

	void inquireProfit() const;

	~ComputerStore();
private:
	char* nameAddr;
	char workTime[12];
	float profit;
	item* stock;

	size_t iSize;
	size_t iCap;
	void iResize();

	bool validateTime(const char* time);
	void clear();
};