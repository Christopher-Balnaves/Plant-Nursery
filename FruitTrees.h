#ifndef FRUITTREES_H
#define FRUITTREES_H value

#include "Plant.h"

class FruitTrees : public Plant {

	bool ready_to_pick;

public:
	
	// Constructors
	FruitTrees(std::string species);
	FruitTrees(std::string species, double price, int current_stock, int location);

	// Subclass specific function
	bool pick_fruit();

	// Redeclaration of virtual functions
	void print_information();

	// Destructor
	~FruitTrees();

};

#endif

