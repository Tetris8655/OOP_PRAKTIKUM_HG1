#include"ComputerStore.h"
#include<cstring>

ComputerStore::ComputerStore(const char* nameAddr, const char* workTimeAddr, const float& profit) 
{
	if (profit < 0.0f) throw std::invalid_argument("NEGATIVE VALUE FOR PROFIT IS INVALID!");
	if (!validateTime(workTimeAddr)) throw std::invalid_argument("INVALID WORK TIME!(VALID FORMAT: \"HH:MM-HH:MM\"");

	this->nameAddr = new char[strlen(nameAddr) + 1];
	strcpy_s(this->nameAddr,strlen(nameAddr) + 1, nameAddr);

	strcpy_s(workTime, 12, workTimeAddr);
	this->profit = profit;

	iSize = 0;
	iCap = 2;

	stock = new item[iCap];
}	

/*
* Since it is not specified, I assume that adding an item in a practical sense
* means that we get a delivery, which constists of a Computer part, as well as
* its ammount, which is why I think that passing the structure "item" is the best
* implementation for this function.
*/
void ComputerStore::addItem(const item& it)
{
	/*
	First we have to check if we have this type of computer part already in stock,
	in which case we just add the ammount of the provided computer part to the ammount
	of the already available computer part.
	*/
	for (size_t i = 0; i < iSize; ++i)
	{
		if (stock[i].cp == it.cp) 
		{
			stock[i].count += it.count;
			return;
		}
	}

	//If such a computer part is not available in stock, we add it to the array of items.
	if (iSize >= iCap) iResize();

	stock[iSize] = it;
	iSize++;
}

/*
* Since it is not specified, I assume that removing an item in a practical sense
* means that a customer makes an order, which constists of a Computer part, as well as
* its ammount, which is why I think that passing the structure "item" is the best
* implementation for this function.
*/
void ComputerStore::removeItem(const item& it)
{
	for (size_t i = 0; i < iSize; ++i)
	{
		if (stock[i].cp == it.cp)
		{
			//If we have enough of the computer part, we just remove the ammount that the customer needs.
			if (stock[i].count < it.count) stock[i].count -= it.count;
			//If we do not have enough, we inform the client.
			else if (stock[i].count > it.count) std::cout << "Not enough items of this type in stock! Current ammount in stock: " << stock[i].count << "\n";
			//If the customer orders all of the available computer parts of the asked type, we remove this type from the array altogether.
			else 
			{
				stock[i] = stock[iSize - 1];
				iSize--;
			}
			return;
		}
	}
}

ComputerStore::~ComputerStore() 
{
	clear();
}

void ComputerStore::searchComputerParts(unsigned type, const char* brandAddr) 
{
	for (size_t i = 0; i < iSize; ++i) 
	{
		if (stock[i].cp.getType() == type && !strcmp(stock[i].cp.getBrand(), brandAddr)) 
		{
			std::cout << "Type: ";
			switch (type)
			{
			case 0:
				std::cout << "COMPUTER";
				break;
			case 1:
				std::cout << "LAPTOP";
				break;
			case 2:
				std::cout << "MOUSE";
				break;
			case 3:
				std::cout << "KEYBOARD";
				break;
			case 4:
				std::cout << "MONITOR";
				break;
			case 5:
				std::cout << "HEADPHONES";
				break;
			case 6:
				std::cout << "COMPUTER";
				break;
			};
			std::cout << "\nBrand: " << brandAddr << "\nModel: " << stock[i].cp.getModel() << "\nWarranty: " << stock[i].cp.getWarranty() << "\nPrice: " << stock[i].cp.getPrice() << "\nAmmount In Stock: " << stock[i].count << "\n";
		}
		//We do not have a return statement, since there could be parts of the same type and brand, but different models!
	}
}

void ComputerStore::inquireProfit() const
{
	std::cout << "Profit of the store: " << profit << "\n";
}

void ComputerStore::iResize() 
{
	iCap *= 2;
	item* tmp = new item[iCap];

	for (size_t i = 0; i < iSize; ++i) tmp[i] = stock[i];
	delete[] stock;
	stock = tmp;
}

bool ComputerStore::validateTime(const char* time)
{
	if (strlen(time) != 11 || time[2] != ':' || time[5] != '-' || time[8] != ':') return false;

	int numOfNaN = 0;
	for (size_t i = 0; i < 11; ++i)
		if (time[i] < '0' || time[i] > '9') numOfNaN++;
	if (numOfNaN > 3) return false;

	int h1, h2, m1, m2;
	h1 = (time[0] - '0') * 10 + time[1] - '0';
	h2 = (time[6] - '0') * 10 + time[7] - '0';
	m1 = (time[3] - '0') * 10 + time[4] - '0';
	m2 = (time[9] - '0') * 10 + time[10] - '0';
	if (h1 > 23 || h1 < 0 || h2 > 23 || h2 < 0
		|| m1 < 0 || m1 > 59 || m2 < 0 || m2 > 59) return false;

	return true;
}


void ComputerStore::clear()
{
	delete[] nameAddr;
	delete[] stock;
}