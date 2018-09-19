#include "Succulents.h"

#include <iostream>

// Constructors
Succulents::Succulents(std::string species) {
	species_count++;
	species_id=species_count;
	price=-1;
	current_stock=0;
	possible_stock=-1;
	fertilizing_req=1; 	// Once a MONTH
	watering_req=1;		// Once every 10 DAYS
	location="?";
	in_or_out="Indoor";
	this->species=species;
}

Succulents::Succulents(std::string species, int price, int current_stock, int possible_stock, std::string location) {
	species_count++;
	species_id=species_count;
	this->price=price;
	this->current_stock=current_stock;
	this->possible_stock=possible_stock;
	fertilizing_req=1;
	watering_req=1;
	this->location=location;
	in_or_out="Indoor";
	this->species=species;
}

// Virtual functions
void Succulents::get_watering_req() {
	std::cout << "Water " << species << " once a month." << std::endl;
}

void Succulents::get_fertilizing_req() {
	std::cout << "Fertilize " << species << " once every 10 days." << std::endl;
}

// Destructor
Succulents::~Succulents() {}
