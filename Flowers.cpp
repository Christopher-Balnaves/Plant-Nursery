#include "Flowers.h"

// Constructors
Flowers::Flowers(std::string species) {
	species_count++;
	species_id=species_count;
	class_id=1;
	price=-1;
	current_stock=0;
	need_watering=true;
	need_fertilizing=true;
	location=-1;
	in_or_out="Both";
	this->species=species;
}

Flowers::Flowers(std::string species, double price, int current_stock, int location) {
	species_count++;
	species_id=species_count;
	class_id=1;
	this->price=price;
	this->current_stock=current_stock;
	need_watering=true;
	need_fertilizing=true;
	this->location=location;
	in_or_out="Both";
	this->species=species;
}

/// Virtual function
void Flowers::print_information() {
	std::cout << "For species " << species << " :" << std::endl;
	std::cout << "  Species ID is " << species_id << "." << std::endl;
	std::cout << "  Price is " << price << " dollars." << std::endl;
	std::cout << "  Current stock level is " << current_stock << "." << std::endl;
	std::cout << "  Location reference number is " << location << "." << std::endl;
	std::cout << "  " << species << " is a flower so may be be kept indoors or outdoors." << std::endl;
	std::cout << "  " << species << " is a flower so needs to be watered three times a week." << std::endl;
	std::cout << "  " << species << " is a flower so needs to be fertilized twice a year." << std::endl;
	return;
}

// Destructor
Flowers::~Flowers() {}