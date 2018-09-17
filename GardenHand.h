
#ifndef GARDENHAND_H
#define GARDENHAND_H

#include <string>
#include "Person.h"
#include "Plant.h"

class GardenHand : public Person
{

plant * plantstowater;
plant * plantstofertilise;

public:

//int get_number_to_water(); - depends on how boolean functions work
//int get_number_to_fertilise();

bool water(); //each function returns true if the task needs to be done
bool fertilise();
bool restock();
bool relocate();

};

#endif
