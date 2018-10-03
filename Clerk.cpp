#include "Clerk.h"
#include <string>
#include <iostream>
#include "Person.h"
//#include "Plant.h"


Clerk::Clerk(std::string pname) : Person (pname, "Clerk") {
}

Clerk::Clerk() : Person ("?", "Clerk"){
}

/*
//methods
bool sell(Plant planttosell, int n){
  return planttosell.set_current_stock(planttoorder.get_current_stock()-n);
}

bool order(Plant planttoorder, int n){
  if (planttoorder.get_possible_stock()+n>=0){
    return planttoorder.set_current_stock(planttoorder.get_current_stock()+n);
  }
  else {
    return false;
  }
}

int get_current_stock(Plant planttocheck){
  return planttocheck.get_current_stock();
}

//setters
bool set_price(Plant planttochangeprice, int price){
    return (planttochangeprice.set_price(int price);
}
*/



