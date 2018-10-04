#ifndef SHRUBS_H
#define SHRUBS_H value

#include "Plant.h"

class Shrubs : public Plant {

public:
	
	// Constructors
	Shrubs(std::string species);
	Shrubs(std::string species, double price, int current_stock, int possible_stock, std::string location);

	// Redeclaration of virtual functions
	void get_watering_req();
 	void get_fertilizing_req();

	// Destructor
	~Shrubs();

};

#endif

