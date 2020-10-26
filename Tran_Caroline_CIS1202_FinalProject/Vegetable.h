#ifndef VEGETABLE_H
#define VEGETABLE_H
#include <string>

using namespace std;

class Vegetable
{
private:
	string name;
	int days;
	double buyPrice;
	double sellPrice;
	int quantity;

public:
	Vegetable();
	~Vegetable() {}
	void printVegetableInfo();
	void setName(string vegName) { name = vegName; }
	void setDay(int vegDays) { days = vegDays; }
	void setbuyPrice(double vegBuy) { buyPrice = vegBuy; }
	void setsellPrice(double vegSell) { sellPrice = vegSell; }
	void setQuantity(int vegQuantity) { quantity = vegQuantity; }
	void getVegetableInfo(Vegetable &);

};

#endif
