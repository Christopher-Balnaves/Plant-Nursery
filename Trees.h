#ifndef TREES_H
#define TREES_H value

#include "Plant.h"

class Trees : public Plant {

public:
	
	// Constructors
	Trees(std::string species);
	Trees(std::string species, double price, int current_stock, int possible_stock, std::string location);

	// Redeclaration of virtual functions
	void get_watering_req();
	void get_fertilizing_req();

	// Destructor
	~Trees();

};

#endif

