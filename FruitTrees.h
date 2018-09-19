#ifndef FRUITTREES_H
#define FRUITTREES_H value

#include "Plant.h"

class FruitTrees : public Plant {

	bool ready_to_pick;

public:
	
	// Constructors
	FruitTrees(std::string species);
	FruitTrees(std::string species, int price, int current_stock, int possible_stock, std::string location);

	// Subclass specific function
	bool pick_fruit();

	// Destructor
	~FruitTrees();

};

#endif

