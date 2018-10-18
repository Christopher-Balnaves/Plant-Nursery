#include "Plant.h"
#include <iostream>
#include <cmath>

// Species_count initialization
int Plant::species_count=0;

// Getters
int Plant::get_class_id() {
	return class_id;
} 

int Plant::get_species_id() {
	return species_id;
}

double Plant::get_price() {
	return price;
}

int Plant::get_current_stock() {
	return current_stock;
}

int Plant::get_species_count() {
	return species_count;
}

int Plant::get_location() {
	return location;
}

std::string Plant::get_in_or_out() {
	return in_or_out;
}

std::string Plant::get_species() {
	return species;
}

bool Plant::get_need_watering() {
	return need_watering;
}

bool Plant::get_need_fertilizing() {
	return need_fertilizing;
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

bool Plant::set_location(int new_location) {
	location=new_location;
	if (location==new_location) {
		return true;
	} else {
		return false;
	}
}

bool Plant::set_price(double new_price) {
	price=new_price;
	if (price==new_price) {
		return true;
	} else {
		return false;
	}
}

bool Plant::set_need_watering(bool boolean) {
	need_watering=boolean;
	if (need_watering==boolean){
		return true;
	} else {
		return false;
	}
}

bool Plant::set_need_fertilizing(bool boolean) {
	need_fertilizing=boolean;
	if (need_fertilizing==boolean){
		return true;
	} else {
		return false;
	}
}

bool Plant::pick_fruit(){
	std::cout << "You may only pick fruit from a fruit tree." << std::endl;
	return false;
}
