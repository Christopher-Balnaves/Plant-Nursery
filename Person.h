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

void test();

//Virtual functions from GardenHand
virtual bool water(); //each function returns true if the task needs to be done
virtual bool fertilise();
virtual bool restock(Plant planttorestock, int n);
virtual bool relocate(Plant planttomove, std::string new_location);
virtual bool rake_paths();

//Virtual functions from Clerk

virtual bool sell(Plant planttosell, int n); //each function returns true if the task needs to be done
virtual bool order(Plant planttoorder, int n);
virtual int get_current_stock(Plant planttocheck);
virtual bool set_price(Plant planttochangeprice, int price);

};

#endif
