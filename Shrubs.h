#ifndef SHRUBS_H
#define SHRUBS_H value

#include "Plant.h"

class Shrubs : public Plant {

public:
	
	// Constructors
	Shrubs(std::string species);
	Shrubs(std::string species, int price, int current_stock, int possible_stock, std::string location);

	// Destructor
	~Shrubs();

};

#endif

