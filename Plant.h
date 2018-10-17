#ifndef PLANT_H
#define PLANT_H

#include <string>
#include <iostream>
#include <cmath>

class Plant {

protected:
  static int species_count;     // Count of number of species in nursery - used for inventory array allocation
  int species_id;
  int class_id;
  double price;
  int current_stock;
  int fertilizing_req;
  int watering_req;
  int location;
  std::string in_or_out;
  std::string species;
  
public:

  // No constructors as abstract class

  // Getters
  double get_price();
  int get_class_id();
  int get_species_id();
  int get_current_stock();
  int get_location();
  std::string get_in_or_out();
  std::string get_species();
  

  // Setters
  bool set_current_stock(int stock_level);
  bool set_location(int new_location);
  bool set_price(double new_price);
  
  // Behaviours
  bool water_plant();
  bool fertilize_plant();

  // Virtual function for sub-class specific functions
  virtual bool pick_fruit();

  // Pure virtual functions
  virtual void print_information()=0;

  // No destructors as abstract class

};

#endif