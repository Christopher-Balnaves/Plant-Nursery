#include <string>
#include "GardenHand.h"
#include "Person.h"
#include "Plant.h"

using namespace std;

//constructors
GardenHand::GardenHand(int assignment) : Person ("?", "Garden Hand"){
int assigned_location = assignment;
}


GardenHand::GardenHand(string given_name, int assignment) : Person (given_name, "Garden Hand"){
int assigned_location = assignment;
}

GardenHand::GardenHand() : Person ("?", "Garden Hand"){
int assigned_location = -1;
}

//getters
int GardenHand::get_assigned_location(){
  return assigned_location;
}

//job related methods

bool GardenHand::water(Plant** watering, int currentnumber){  
  
  int successful=0;
  int unsuccessful=0;

  if (currentnumber==0) {
      cout << " There are no plants in this location, so they cannot be watered." << endl;
      return false;
  } else {
    for (int i = 0; i < currentnumber; ++i) {
      if (watering[i]->get_need_watering()==true) {
        successful++;
        watering[i]->set_need_watering(false);
      } else {
        unsuccessful++;
      }
    }
    cout << successful << " plants were watered, " << unsuccessful << " did not need watering." << endl; 
    return true;
    }
    return false;
}

bool GardenHand::fertilise(Plant** fertilizing, int currentnumber){ 
  
  int successful=0;
  int unsuccessful=0;

  if (currentnumber==0) {
      cout << " There are no plants in this location, so they cannot be fertilized." << endl;
      return false;
  } else {
    for (int i = 0; i < currentnumber; ++i) {
      if (fertilizing[i]->get_need_fertilizing()==true) {
        successful++;
        fertilizing[i]->set_need_fertilizing(false);
      } else {
        unsuccessful++;
      }
    }
    cout << successful << " plants were fertilized, " << unsuccessful << " did not need fertilizing." << endl; 
     return true;
    }                   
}
bool GardenHand::restock(Plant* planttorestock, int n){
  return planttorestock->set_current_stock(planttorestock->get_current_stock()+n);
  
}
bool GardenHand::relocate(Plant* planttomove, int new_location){
    return planttomove->set_location(new_location);
}
bool GardenHand::pick_fruit(Plant* planttopick){
    return planttopick->pick_fruit();
}



bool GardenHand::rake_paths(){
  return true;
}


//GardenHand::~GardenHand(){
  //delete [] plantsassignment;
//}