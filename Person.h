#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "Plant.h"

class Person
{

std::string name; //name of worker
std::string job; //job
bool working;  //if they are currently at work

public:

Person();
Person(std::string pname, std::string pjob);

//getters
bool at_work();
std::string get_name();
std::string get_job();

//setters
void set_name(std::string new_name);
void arrive();
void leave();

//Virtual functions from GardenHand
virtual bool water(Plant** watering, int currentnumber);
virtual bool fertilise(Plant** fertilizing, int currentnumber);
virtual bool restock(Plant* planttorestock, int n);
virtual bool relocate(Plant* planttomove, int new_location);
virtual bool pick_fruit(Plant* planttopick);
virtual int get_assigned_location();
virtual bool rake_paths();

//Virtual functions from Clerk

virtual bool sell(Plant* planttosell, int n); //each function returns true if the task needs to be done
virtual bool order(Plant* planttoorder, int n);
virtual void get_information(Plant* planttocheck);
virtual int get_current_stock(Plant* planttocheck);
virtual bool set_price(Plant* planttochangeprice, double price);

};

#endif