#include "Flowers.h"

// Constructors
Flowers::Flowers(std::string species) {
	species_count++;
	species_id=species_count;
	price=-1;
	current_stock=0;
	possible_stock=-1;
	fertilizing_req=2; 	// Twice a year
	watering_req=3;		// Three times a week
	location="?";
	in_or_out="Both";
	this->species=species;
}

Flowers::Flowers(std::string species, double price, int current_stock, int possible_stock, std::string location) {
	species_count++;
	species_id=species_count;
	this->price=price;
	this->current_stock=current_stock;
	this->possible_stock=possible_stock;
	fertilizing_req=2;
	watering_req=3;
	this->location=location;
	in_or_out="Both";
	this->species=species;
}

// Virtual functions
void Flowers::get_watering_req() {
	std::cout << species << " is a flower so needs to be watered three times a week." << std::endl;
}

void Flowers::get_fertilzing_req() {
	std::cout << species << " is a flower so needs to be fertilized twice a year." << std::endl;
}

// Destructor
Flowers::~Flowers() {}