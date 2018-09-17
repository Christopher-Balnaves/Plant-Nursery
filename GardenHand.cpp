
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
    plant temp = plantsingarden[i];
      if ((temp.need_water())==true){
      return true;
      }
    }
  return false;                  
}

bool GardenHand::fertilise(){

  bool needfertiliser =false;
  
  if (currentno==0)
    {
    return false;
    }
  
  for (int i=0; i < currentno; i++)
    {
    plant temp = plantsingarden[i];
      if ((temp.need_fertiliser())==true){
      return true;
      }
    }
  return false;                  
}

bool restock(int insection, int capacitysection){
  if (insection < capacitysection){         //need to change to function which returns current number in section and capacity
  
  //
  ADD HERE PLANT INTO SECTION
  //
  
  return true;
  }
  return false;
}

bool relocate(){
  if (insection < capacitysection){
      //
        ADD HERE PLANT INTO SECTION AND DELETE  FROM LAST SECTION
      //
  }
}
