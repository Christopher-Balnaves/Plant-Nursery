
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

bool GardenHand::water(){     //need to get current number of plants into this function - maybe pass in a variable? or use vectors? 
                              // also should we maybe specify a section?
    bool needwater =false;
  
  if (currentno==0)
    {
    return false;
    }
  
  for (int i=0; i < currentno; i++)
    {
    //Plant temp = plantsingarden[i];  
     // if ((temp.need_water())==true)} 
     // return true;
     // }
    }
  return false;               
}
bool GardenHand::fertilise(){ 
  bool needfertiliser = false;
  
  if (currentno==0)
    {
    return false;
    }
  
  for (int i=0; i < currentno; i++)
    {
    //Plant temp = plantsingarden[i];    //Same as above you cant really treat objects like varibles this doesnt really make sense
    //  if ((temp.need_fertiliser())==true){
    //  return true;
    //  }
    }
  return false;                  
}
bool GardenHand::restock(Plant* planttorestock, int n){
  
  if (planttorestock->get_possible_stock()+n>=0){         //need to change to function which returns current number in section and capacity
  
    planttorestock->set_current_stock(planttorestock->get_current_stock()+n);
    
  return true;
  }
  return false;
  
}
bool GardenHand::relocate(Plant* planttomove, std::string new_location){
       //return planttomove.set_location(new_location);
  return false;
}




bool GardenHand::rake_paths(){
  return true;
}


//GardenHand::~GardenHand(){
  //delete [] plantsingarden;
//}