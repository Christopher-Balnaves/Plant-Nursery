#include <string>
#include "GardenHand.h"
#include "Person.h"
#include "Plant.h"

using namespace std;

//constructors
GardenHand::GardenHand(int ingarden) : Person ("?", "Garden Hand"){
int currentno = ingarden;
}


GardenHand::GardenHand(string given_name, int ingarden) : Person (given_name, "Garden Hand"){
int currentno = ingarden;
}

GardenHand::GardenHand() : Person ("?", "Garden Hand"){
int currentno = 0;
}


//job related methods

bool GardenHand::water(int currentnumber){  
  
  if (currentnumber==0) {
      cout << " There are no plants in the nursery, so they cannot be watered." << endl;
      return false;
    }
  
  else{
    cout << "There are " << currentnumber << " plants which were sucessfully watered." << endl; 
     return true;
     
    }             
}
bool GardenHand::fertilise(int currentnumber){ 
  
  if (currentnumber==0) {
      cout << " There are no plants in the nursery, so they cannot be fertilised." << endl;
      return false;
    }
  
  else{
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
  //delete [] plantsingarden;
//}