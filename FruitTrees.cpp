#include "FruitTrees.h"

// Constructors
FruitTrees::FruitTrees(std::string species) {
	species_count++;
	species_id=species_count;
	class_id=2;
	price=-1;
	current_stock=0;
	need_watering=true;
	need_fertilizing=true;
	location=-1;
	in_or_out="Outdoors";
	this->species=species;
	ready_to_pick=true;
}

FruitTrees::FruitTrees(std::string species, double price, int current_stock, int location) {
	species_count++;
	species_id=species_count;
	class_id=2;
	this->price=price;
	this->current_stock=current_stock;
	need_watering=true;
	need_fertilizing=true;
	this->location=location;
	in_or_out="Outdoors";
	this->species=species;
	ready_to_pick=true;
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

// Virtual function
void FruitTrees::print_information() {
	std::cout << "For species " << species << " :" << std::endl;
	std::cout << "  Species ID is " << species_id << "." << std::endl;
	std::cout << "  Price is " << price << " dollars." << std::endl;
	std::cout << "  Current stock level is " << current_stock << "." << std::endl;
	std::cout << "  Location reference number is " << location << "." << std::endl;
	std::cout << "  " << species << " is a fruit tree so must be kept outdoors." << std::endl;
	std::cout << "  " << species << " is a fruit tree so needs to be watered twice a week." << std::endl;
	std::cout << "  " << species << " is a fruit tree so needs to be fertilized once a year." << std::endl;
	return;
}

// Destructor
FruitTrees::~FruitTrees() {}