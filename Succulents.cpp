#include "Succulents.h"

#include <iostream>

// Constructors
Succulents::Succulents(std::string species) {
	species_count++;
	species_id=species_count;
	class_id=4;
	price=-1;
	current_stock=0;
	fertilizing_req=1; 	// Once a MONTH
	watering_req=1;		// Once every 10 DAYS
	location=-1;
	in_or_out="Indoor";
	this->species=species;
}

Succulents::Succulents(std::string species, double price, int current_stock, int location) {
	species_count++;
	species_id=species_count;
	class_id=4;
	this->price=price;
	this->current_stock=current_stock;
	fertilizing_req=1;
	watering_req=1;
	this->location=location;
	in_or_out="Indoor";
	this->species=species;
}

// Virtual function
void Succulents::print_information() {
	std::cout << "For species " << species << " :" << std::endl;
	std::cout << "  Species ID is " << species_id << "." << std::endl;
	std::cout << "  Price is " << price << " dollars." << std::endl;
	std::cout << "  Current stock level is " << current_stock << "." << std::endl;
	std::cout << "  Location reference number is " << location << "." << std::endl;
	std::cout << "  " << species << " is a succulent so must be kept indoors." << std::endl;
	std::cout << "  " << species << " is a succulent so needs to be watered once every ten days." << std::endl;
	std::cout << "  " << species << " is a succulent so needs to be fertilized once a month." << std::endl;
	return;
}

// Destructor
Succulents::~Succulents() {}