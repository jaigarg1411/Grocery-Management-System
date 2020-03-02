#include "fruits.h"
#include <iostream>
#include <string>

using namespace std;
	fruits :: fruits(string type1,int x,int y,float calories1,float weight_per_unit1,int price_per_unit1,int units1)
	{
		type = type1;
		static int i = 1;
		purchase_id = i;
		i++;
		location_x = x;
		location_y = y;
		calories = calories1;
		weight_per_unit = weight_per_unit1;
		price_per_unit = price_per_unit1;
		units = units1;
	}

