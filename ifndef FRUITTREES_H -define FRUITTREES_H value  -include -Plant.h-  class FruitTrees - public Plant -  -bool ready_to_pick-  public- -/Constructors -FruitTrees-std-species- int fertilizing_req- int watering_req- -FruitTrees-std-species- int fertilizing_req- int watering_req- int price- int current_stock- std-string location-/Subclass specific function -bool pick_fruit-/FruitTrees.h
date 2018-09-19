#ifndef FRUITTREES_H
#define FRUITTREES_H value

#include "Plant.h"

class FruitTrees : public Plant {

	bool ready_to_pick;

public:
	
	// Constructors
	FruitTrees(std::species, int fertilizing_req, int watering_req);
	FruitTrees(std::species, int fertilizing_req, int watering_req, int price, int current_stock, std::string location);

	// Subclass specific function
	bool pick_fruit();

	// Destructor
	~FruitTrees();

};

#endif

