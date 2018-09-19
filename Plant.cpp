#include "Plant.h"
#include <iostream>

// Species_count initialization
int Plant::species_count=0;

// Getters
int Plant::get_species_id() {
	return species_id;
}

int Plant::get_price() {
	return price;
}

int Plant::get_possible_stock() {
	return possible_stock;
}

int Plant::get_current_stock() {
	return current_stock;
}

std::string Plant::get_location() {
	return location;
}

std::string Plant::get_in_or_out() {
	return in_or_out;
}

std::string Plant::get_species() {
	return species;
}

void Plant::print_information() {
	std::cout << "For species " << species << " :" << std::endl;
	std::cout << "\tSpecies ID is " << species_id << "." << std::endl;
	std::cout << "\tPrice is " << price << " dollars." << std::endl;
	std::cout << "\tCurrent stock level is " << current_stock << " of " << possible_stock) << "." << std::endl;
	std::cout << "\tLocation is " << location << "." << std::endl;
	std::cout << "\t" << species << " must be kept " << in_or_out << "." << std::endl;
	return;
}

// Setters
bool Plant::set_current_stock(int stock_level) {
	current_stock=stock_level;
	if (current_stock==stock_level) {
		return true;
	} else {
		return false;
	}
}

bool Plant::set_possible_location(int stock_level) {
	possible_stock=stock_level;
	if (possible_stock==stock_level) {
		return true;
	} else {
		return false;
	}
}

bool Plant::set_location(std::string new_location) {
	location=new_location;
	if (location==new_location) {
		return true;
	} else {
		return false;
	}
}

bool Plant::set_price(int new_price) {
	price=new_price;
	if (price==new_price) {
		return true;
	} else {
		return false;
	}
}

// Virtual functions
void Plant::get_watering_req() {
	std::cout << "Water " << species;
	switch (watering_req) {
		case 1:
			std::cout << " once a week." << endl;
			break;
		case 2:
			std::cout << " twice a week." << endl;
			break;
		case 3:
			std::cout << " three times a week." << endl;
	}
	
}

void Plant::get_fertilizing_req() {
	std::cout << "Fertilize " << species;
	switch (fertilizing_req) {
		case 1:
			std::cout << " once a year." << endl;
			break;
		case 2:
			std::cout << " twice a year." << endl;
	}
	
}
