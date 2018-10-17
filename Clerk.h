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


bool sell(Plant* planttosell, int n); //each function returns true if the task needs to be done
bool order(Plant* planttoorder, int n);
void get_information(Plant* planttocheck);
int get_current_stock(Plant* planttocheck);
bool set_price(Plant* planttochangeprice, double price);

};

#endif