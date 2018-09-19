#ifndef CLERK_H
#define CLERK_H

#include <string>
#include "Person.h"
#include "Plant.h"

class Clerk : public Person
{

public:

Clerk(std::string pname);
GardenHand();

//methods
bool sell(plant planttosell, int n); //each function returns true if the task needs to be done
bool order(plant planttoorder, int n);
int get_current_stock(plant planttocheck);
bool set_price(plant planttochangeprice, int price);


};

#endif
