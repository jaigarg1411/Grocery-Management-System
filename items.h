#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
#include <string>
using namespace std;
class items{
	
	string type;
	long long int purchase_id;
	int location_x;
	int location_y;
	int calories;
	float weight_per_unit;
	int price_per_unit;
public:
	int units;

	void print();
	void updatetype(string type1);
	void updatex(int x1);
	void updatey(int y1);
	void updatecalories(int cal1);
	void updateweight(float weight);
	void updateprice(int price);
	string gettype();
	long long int getpurchaseid();
	int getx();
	int gety();
	int getcalories();
	int getweight_per_unit();
	int getprice_per_unit();
	friend class fruits;
	friend class vegetables;
};

#endif
