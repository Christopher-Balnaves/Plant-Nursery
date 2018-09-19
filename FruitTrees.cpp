#include "FruitTrees.h"

// Constructors
FruitTrees::FruitTrees(std::string species) {
	species_count++;
	species_id=species_count;
	price=-1;
	current_stock=0;
	possible_stock=-1;
	fertilizing_req=1; 	// Once a year
	watering_req=2;		// Twice a week
	location="?";
	in_or_out="Outdoors";
	this->species=species;
}

FruitTrees::FruitTrees(std::string species, int price, int current_stock, int possible_stock, std::string location) {
	species_count++;
	species_id=species_count;
	this->price=price;
	this->current_stock=current_stock;
	this->possible_stock=possible_stock;
	fertilizing_req=1; 	// Once a year
	watering_req=2;		// Twice a week
	this->location=location;
	in_or_out="Outdoors";
	this->species=species;
}

// Class specific function
bool FruitTrees::pick_fruit() {
	if (ready_to_pick==true) {
		ready_to_pick=false;
		return true;
	} else {
		return false;
	}
}

// Destructor
FruitTrees::~FruitTrees() {}
