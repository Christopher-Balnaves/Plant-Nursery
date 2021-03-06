#include "Person.h"
#include "Plant.h"
#include <string>
#include <iostream>

using namespace std;

Person::Person(){

name="?";
job = "?"; 
working= false;
}

Person::Person(string pname, string pjob){

name=pname;
job=pjob;
working = false;
}

//getters
bool Person::at_work(){
return working;
}

string Person::get_name(){
return name;
}

string Person::get_job(){
return job;
}

//setters
void Person::set_name(std::string new_name){
name=new_name;
}

void Person::arrive(){
working = true;
}
void Person::leave(){
working = false;
}


//virtual definitions
bool Person::rake_paths(){
	std::cout << "Clerks cannot rake paths. " << std::endl;
	return false;
}

bool Person::water(Plant** watering, int currentnumber){
	std::cout << "Clerks cannot water plants. " << std::endl;
	return false;
} //each function returns true if the task needs to be done

bool Person::fertilise(Plant** fertilizing, int currentnumber){
	std::cout << "Clerks cannot fertilise plants. " << std::endl;
	return false;
}

bool Person::restock(Plant* planttorestock, int n){
	std::cout << "Clerks cannot restock. " << std::endl;
	return false;
}

bool Person::relocate(Plant* planttomove, int new_location){
	std::cout << "Clerks cannot relocate plants. " << std::endl;
	return false;
}

bool Person::pick_fruit(Plant* planttopick) {
	std::cout << "Clerks cannot pick fruit. " << std::endl;
	return false;	
}

int Person::get_assigned_location() {
	std::cout << "Clerks do not have an assigned location." << std::endl;
	return -1;
}

bool Person::sell(Plant* planttosell, int n){
	std::cout << "Garden hands cannot sell plants. " << std::endl;
	return false;
} 

bool Person::order(Plant* planttoorder, int n){
	std::cout << "Garden hands cannot order plants. " << std::endl;
	return false;
} 

int Person::get_current_stock(Plant* planttocheck){
	std::cout << "Garden hands cannot get current stock. " << std::endl;
	return false;
} 

void Person::get_information(Plant* planttocheck){
	std::cout << "Garden hands cannot get information. " << std::endl;
	return;
}

bool Person::set_price(Plant* planttochangeprice, double price){
	std::cout << "Garden hands cannot set price. " << std::endl;
	return false;
} 