#ifndef PLANT_H
#define PLANT_H

#include <string>
#include <iostream>
#include <cmath>

class Plant {

protected:
  static int species_count;     // Count of number of species in nursery - used for inventory array allocation
  int species_id;
  double price;
  int current_stock;
  int possible_stock;
  int fertilizing_req;
  int watering_req;
  std::string location;
  std::string in_or_out;
  std::string species;
  
public:

  // No constructors as abstract class

  // Getters
  double get_price();
  int get_species_id();
  int get_possible_stock();
  int get_current_stock();
  std::string get_location();
  std::string get_in_or_out();
  std::string get_species();
  void print_information();

  // Setters
  bool set_current_stock(int stock_level);
  bool set_location(std::string new_location);
  bool set_possible_stock(int stock_level);
  bool set_price(double new_price);
  
  // Behaviours
  bool water_plant();
  bool fertilize_plant();

  // Pure virtual functions
  virtual void get_watering_req()=0;
  virtual void get_fertilizing_req()=0;

  // No destructors as abstract class

};

#endif