#ifndef PLANT_H
#define PLANT_H

#include <string>
#include <iostream>
#include <cmath>

class Plant {

protected:
  static int species_count;     // Count of number of species in nursery
  int species_id;
  int class_id;
  double price;
  int current_stock;
  bool need_fertilizing;
  bool need_watering;
  int location;
  std::string in_or_out;
  std::string species;
  
public:

  // No constructors as abstract class

  // Getters
  double get_price();
  int get_class_id();
  int get_species_id();
  int get_species_count();
  int get_current_stock();
  bool get_need_watering();
  bool get_need_fertilizing();
  int get_location();
  std::string get_in_or_out();
  std::string get_species();
  

  // Setters
  bool set_current_stock(int stock_level);
  bool set_location(int new_location);
  bool set_price(double new_price);
  bool set_need_watering(bool boolean);
  bool set_need_fertilizing(bool boolean);
  
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