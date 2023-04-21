#include"ComputerPartWriter.h"
#include"ComputerPartReader.h"
#include"ComputerStoreWriter.h"

int main() 
{
	ComputerPart first(4, 250.0f, "Samsung", "H321D131FR", 5), second(5,350.0f, "PHILLIPS", "N23JSMK4", 3);
	ComputerStore cs("Nig store", "09:00-22:00", 0.0f);
	cs.addItem({ first, 3 });
	cs.addItem({ second, 5 });
	cs.addItem({ first, 2 });
	ComputerStoreWriter csw;
	csw.write(cs, "Store.txt");
	ComputerPartWriter cpw;
	ComputerPartReader cpr;
	cpw.writeToFile(first, "List.txt");
	ComputerPart copy = cpr.readFromFile("List.txt");
	cpw.writeToFile(copy, "ListCopy.txt");
	return 0;
}