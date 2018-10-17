#ifndef SUCCULENTS_H
#define SUCCULENTS_H value

#include "Plant.h"

class Succulents : public Plant {

public:
	
	// Constructors
	Succulents(std::string species);
	Succulents(std::string species, double price, int current_stock, int location);

	// Redeclaration of virtual functions
	void print_information();

	// Destructor
	~Succulents();

};

#endif

