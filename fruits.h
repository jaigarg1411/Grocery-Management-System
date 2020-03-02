#ifndef FRUITS_H
#define FRUITS_H

#include <iostream>
#include <string>

#include "items.h"
using namespace std;

class fruits : public items
{
public:
	fruits(string type1,int x,int y,float calories1,float weight_per_unit1,int price_per_unit1,int units1);
};


#endif

