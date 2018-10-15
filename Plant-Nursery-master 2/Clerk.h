#ifndef CLERK_H
#define CLERK_H

#include <string>
#include "Person.h"
#include "Plant.h"

class Clerk : public Person
{

public:

Clerk(std::string pname);
Clerk();


//methods
//each function returns true if the task needs to be done

bool sell(Plant* planttosell, int n); 
bool order(Plant* planttoorder, int n);
int get_current_stock(Plant* planttocheck);
bool set_price(Plant* planttochangeprice, double price);

};

#endif