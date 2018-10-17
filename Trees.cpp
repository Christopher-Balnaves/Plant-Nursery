#include "Trees.h"

// Constructors
Trees::Trees(std::string species) {
	species_count++;
	species_id=species_count;
	class_id=5;
	price=-1;
	current_stock=0;
	fertilizing_req=1; 	// Once a year
	watering_req=2;		// Twice a week
	location=-1;
	in_or_out="Outdoors";
	this->species=species;
}

Trees::Trees(std::string species, double price, int current_stock, int location) {
	species_count++;
	species_id=species_count;
	class_id=5;
	this->price=price;
	this->current_stock=current_stock;
	fertilizing_req=1; 	// Once a year
	watering_req=2;		// Twice a week
	this->location=location;
	in_or_out="Outdoors";
	this->species=species;
}

// Virtual function
void Trees::print_information() {
	std::cout << "For species " << species << " :" << std::endl;
	std::cout << "  Species ID is " << species_id << "." << std::endl;
	std::cout << "  Price is " << price << " dollars." << std::endl;
	std::cout << "  Current stock level is " << current_stock << "." << std::endl;
	std::cout << "  Location reference number is " << location << "." << std::endl;
	std::cout << "  " << species << " is a tree so must be kept outdoors." << std::endl;
	std::cout << "  " << species << " is a tree so needs to be watered twice a week." << std::endl;
	std::cout << "  " << species << " is a tree so needs to be fertilized once a year." << std::endl;
	return;
}


// Destructor
Trees::~Trees() {}