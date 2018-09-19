#ifndef FLOWERS_H
#define FLOWERS_H value

#include "Plant.h"

class Flowers : public Plant {

public:
	
	// Constructors
	Flowers(std::string species);
	Flowers(std::string species, int price, int current_stock, int possible_stock, std::string location);

	// Destructor
	~Flowers();

};

#endif

