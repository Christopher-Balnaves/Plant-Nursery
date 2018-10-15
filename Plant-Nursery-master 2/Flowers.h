#ifndef FLOWERS_H
#define FLOWERS_H value

#include "Plant.h"

class Flowers : public Plant {

public:
	
	// Constructors
	Flowers(std::string species);
	Flowers(std::string species, double price, int current_stock, int possible_stock, std::string location);

	// Redeclaration of virtual functions
	void get_watering_req();
	void get_fertilizing_req();

	// Destructor
	~Flowers();

};

#endif

