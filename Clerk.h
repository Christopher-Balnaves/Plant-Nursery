#ifndef CLERK_H
#define CLERK_H

#include <string>
#include "Person.h"
#include "Plant.h"

class Clerk : public Person
{

public:

Clerk(std::string name);
GardenHand();

//methods
bool sell(plant planttosell); //each function returns true if the task needs to be done
bool order(plant planttoorder, int n);
int get_current_stock(plant planttocheck);

//setters
void set_price(plant planttochangeprice);


};

#endif
