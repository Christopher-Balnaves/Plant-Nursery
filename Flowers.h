#ifndef FLOWERS_H
#define FLOWERS_H value

#include "Plant.h"

class Flowers : public Plant {

public:
	
	// Constructors
	Flowers(std::string species);
	Flowers(std::string species, double price, int current_stock, int location);

	// Redeclaration of virtual functions
	void print_information();

	// Destructor
	~Flowers();

};

#endif

