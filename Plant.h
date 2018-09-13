#ifndef PLANT_H
#define PLANT_H

#include <string>

class Plant {

  static int species_count;     // Count of number of species in nursery - used for inventory array allocation
  int species_id;
  int fertilizing_req;
  int watering_req;
  int price;
  int current_stock;
  int free_space_in_stock;
  std::string location;
  std::string in_or_out;
  std::string species;
  
public:
  int get_current_stock();
  std::string get_location();
  
  bool set_current_stock(int stock_level);
  bool set_location(std::string new_location);
  
  virtual water_plant=0;
  virtual fertilize_plant=0;

};

#endif
