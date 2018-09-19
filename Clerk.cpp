#include "Clerk.h"
#include <string>
#include "Person.h"
#include "Plant.h"


Clerk(std::string pname) : Person (pname, "Clerk"){
}

Clerk() : Person ("?", "Garden Hand"){
}

//methods
bool sell(plant planttosell, int n){
  return planttosell.set_current_stock(planttoorder.get_current_stock()-n);
}

bool order(plant planttoorder, int n){
  if (planttoorder.get_possible_stock()+n>=0){
    return planttoorder.set_current_stock(planttoorder.get_current_stock()+n);
  }
  else {
    return false;
  }
}

int get_current_stock(plant planttocheck){
  return planttocheck.get_current_stock();
}

//setters
bool set_price(plant planttochangeprice, int price){
    return (planttochangeprice.set_price(int price);
}
