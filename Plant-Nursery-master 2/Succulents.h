#ifndef SUCCULENTS_H
#define SUCCULENTS_H value

#include "Plant.h"

class Succulents : public Plant {

public:
	
	// Constructors
	Succulents(std::string species);
	Succulents(std::string species, double price, int current_stock, int possible_stock, std::string location);

	// Redeclaration of virtual functions
	void get_watering_req();
 	void get_fertilizing_req();

	// Destructor
	~Succulents();

};

#endif

