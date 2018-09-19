#include "Plant.h"
#include <iostream>

int Plant::get_species_id() {
	return species_id;
}

int Plant::get_price() {
	return price;
}

int Plant::get_free_space() {
	return free_space_in_stock;
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
	std::cout << "\tCurrent stock level is " << current_stock << " of " << (current_stock+free_space_in_stock) << "." << std::endl;
	std::cout << "\tLocation is " << location << "." << std::endl;
	std::cout << "\t" << species << " must be kept " << in_or_out << "." << std::endl;
	return;
}

bool Plant::set_current_stock(int stock_level) {
	current_stock=stock_level;
	if (current_stock==stock_level) {
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
