#include "items.h"
#include <iostream>
using namespace std;

	void items :: print()
	{
		cout << "Type: " << type << endl;
		cout << "Purchase ID: " << purchase_id << endl;
		cout << "Location: " << "(" << location_x << "," << location_y << ")" << endl;
		cout << "Calories: " << calories << endl;
		cout << "Price per unit: " << price_per_unit << endl;
		cout << "Weight per unit: " << weight_per_unit << endl;
		cout << "Available stock: " << units << endl;
	}

	void items :: updatetype(string type1)
	{
		type = type1;
	}
	void items :: updatex(int x1)
	{
		location_x = x1;
	}
	void items :: updatey(int y1)
	{
		location_y = y1;
	}
	void items :: updatecalories(int cal1)
	{
		calories = cal1;
	}
	void items :: updateweight(float weight)
	{
		weight_per_unit = weight;
	}
	void items :: updateprice(int price)
	{
		price_per_unit = price;
	}

	string items :: gettype()
		{return type;}
	long long int items :: getpurchaseid()
		{return purchase_id;}
	int items :: getx()
		{return location_x;}
	int items :: gety()
		{return location_y;}
	int items :: getcalories()
		{return calories;}
	int items :: getweight_per_unit()
		{return weight_per_unit;}
	int items :: getprice_per_unit()
		{return price_per_unit;}
