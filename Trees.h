#ifndef TREES_H
#define TREES_H value

#include "Plant.h"

class Trees : public Plant {

public:
	
	// Constructors
	Trees(std::string species);
	Trees(std::string species, double price, int current_stock, int location);

	// Redeclaration of virtual functions
	void print_information();

	// Destructor
	~Trees();

};

#endif

