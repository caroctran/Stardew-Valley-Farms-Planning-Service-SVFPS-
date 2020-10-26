/*
Programmer Name: Caroline Tran
Program # : 14
Course: CIS1202
Date: 07/26/2019
Program Description : This program is based on the concept of Stardew Valley, a farm simulation game, and allows players to plan each season 
of the farm (crops, animals, etc.) and how to budget their expenses to make desired profit for the season. 
*/

#include "pch.h"
#include "Vegetable.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

// CONSTRUCTOR
Vegetable::Vegetable()
{
	name = " ";
	days = 0;
	buyPrice = 0.00;
	sellPrice = 0.00;
	quantity = 0;
}

// FUNCTIONS

void storeVegetables(Vegetable, vector<Vegetable> &list)
{	
	string name;
	int days;
	double buyPrice;
	double sellPrice;
	int quantity;
	Vegetable *f1;
	bool n = false;

	while (!n)
	{
		cout << "Enter crop name: ";
		cin >> name;
		cout << "Enter days needed for harvest: ";
		cin >> days;
		cout << "Enter seed cost: ";
		cin >> buyPrice;
		cout << "Enter sell cost of crop: ";
		cin >> sellPrice;
		cout << "Enter quantity to buy: ";
		cin >> quantity;
		cout << "\n";

		f1 = new Vegetable;

		f1->setName(name);
		f1->setDay(days);
		f1->setbuyPrice(buyPrice);
		f1->setsellPrice(sellPrice);
		f1->setQuantity(quantity);

		list.push_back(*f1);

		char answer;
		cout << "Enter another crop? (y/n) ";
		cin >> answer;

		if (answer == 'Y' || answer == 'y')
		{
			n = false;
			cout << "\n";
		}

		else if (answer == 'N' || answer == 'n')
		{
			n = true;
		}

	}

}

void displayVegetableInfo(vector<Vegetable> &list)
{
	vector<Vegetable>::iterator it;

	cout << "Current Planned Spring Crops" << endl;

	for (it = list.begin(); it != list.end(); ++it) {
		// For each friend, print out their info
		it->printVegetableInfo();
		cout << "\n";
	}

}



void Vegetable::printVegetableInfo()
{
	int totalCost = (buyPrice * static_cast<double>(quantity));
	int grossProfit = (sellPrice * static_cast<double>(quantity));
	int netProfit = grossProfit - totalCost;

	cout << "\n";
	cout << "Name: " << name << endl;
	cout << "Harvest Time: " << days << " days" << endl;
	cout << "Total Seed Cost: " << totalCost << "g"  << endl;
	cout << "Gross Profit: " << grossProfit << "g" << endl;
	cout << "Net Profit: " << netProfit << "g" << endl;
}

// MAIN FUNCTION

int main()
{
	Vegetable veggie;
	vector<Vegetable> list;
	bool quit = false;
	int choice;

	while (!quit)
	{
		cout << "Welcome to Stardew Valley Farms Planning Service (SVFPS)" << endl;
		cout << "1. Start my spring plan" << endl;
		cout << "2. View my spring plans" << endl;
		cout << "3. Exit program" << endl;
		cout << "\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1: 
		{
			storeVegetables(veggie, list);
			break;
		}
		
		case 2:
		{
			displayVegetableInfo(list);
			break;
		}

		case 3:
		{
			quit = true;
			break;
		}

		default:
		{
			break;
		}
		}
		
	}

	system("pause");
	return 0;
}




