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


//getters
int GardenHand::get_assigned_location(){
  return assigned_location;
}

//job related methods

bool GardenHand::water(Plant* watering, int currentnumber){  
  
  if (currentnumber==0) {
      cout << " There are no plants in this location, so they cannot be watered." << endl;
      return false;
    }
  
  else {
    cout << "There are " << currentnumber << " plants which were sucessfully watered." << endl; 
     return true;
     
    }             
}
bool GardenHand::fertilise(Plant* watering, int currentnumber){ 
  
  if (currentnumber==0) {
      cout << " There are no plants in this location, so they cannot be fertilised." << endl;
      return false;
    }
  
  else {
    cout << "There are " << currentnumber << " plants which were sucessfully fertilised." << endl; 
     return true;
     
    }                    
}
bool GardenHand::restock(Plant* planttorestock, int n){
  //first check if there is the room to put in the number of plants to be restocked
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