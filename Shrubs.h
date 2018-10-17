#ifndef SHRUBS_H
#define SHRUBS_H value

#include "Plant.h"

class Shrubs : public Plant {

public:
	
	// Constructors
	Shrubs(std::string species);
	Shrubs(std::string species, double price, int current_stock, int location);

	// Redeclaration of virtual functions
	void print_information();

	// Destructor
	~Shrubs();

};

#endif

