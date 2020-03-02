#include "vegetables.h"

#include <iostream>
#include <string>

using namespace std;
	vegetables :: vegetables(string type1,int x,int y,float calories1,float volume_per_kg1,int price_per_kg1,int amount1)
	{
		type = type1;
		static int i = 1;
		purchase_id = i;
		i++;
		location_x = x;
		location_y = y;
		calories = calories1;
		weight_per_unit = volume_per_kg1;
		price_per_unit = price_per_kg1;
		units = amount1;
	}	
