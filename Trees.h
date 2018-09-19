#ifndef TREES_H
#define TREES_H value

#include "Plant.h"

class Trees : public Plant {

public:
	
	// Constructors
	Trees(std::string species);
	Trees(std::string species, int price, int current_stock, int possible_stock, std::string location);

	// Destructor
	~Trees();

};

#endif

