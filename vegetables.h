#ifndef VEGETABLES_H
#define VEGETABLES_H

#include <iostream>
#include <string>

#include "items.h"
using namespace std;

class vegetables : public items
{
public:
	vegetables(string type1,int x,int y,float calories1,float volume_per_kg1,int price_per_kg1,int amount1);
};


#endif

