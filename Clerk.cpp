
#include "Clerk.h"
#include <string>
#include <iostream>
#include "Person.h"
#include "Plant.h"


Clerk::Clerk(std::string pname) : Person (pname, "Clerk") {
}

Clerk::Clerk() : Person ("?", "Clerk"){
}


//methods
bool Clerk::sell(Plant* planttosell, int n){
  	return planttosell->set_current_stock(planttosell->get_current_stock()-n);
}
bool Clerk::order(Plant* planttoorder, int n){
	return planttoorder->set_current_stock(planttoorder->get_current_stock()+n);

}
void Clerk::get_information(Plant* planttocheck) {
	planttocheck->print_information();
	return;
}
int Clerk::get_current_stock(Plant* planttocheck){
 	return planttocheck->get_current_stock();
}
//setters
bool Clerk::set_price(Plant* planttochangeprice, double price){
    return (planttochangeprice->set_price(price));
} 
