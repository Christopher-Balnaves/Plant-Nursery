
#ifndef GARDENHAND_H
#define GARDENHAND_H

#include <string>
#include "Person.h"
#include "Plant.h"

class GardenHand : public Person
{

plant * plantsingarden;
int currentno;

public:

GardenHand(std::string name, int currentno);
GardenHand(currentno);

//int get_number_to_water(); - depends on how boolean functions work
//int get_number_to_fertilise();

bool water(); //each function returns true if the task needs to be done
bool fertilise();
bool restock(int insection, int capacitysection);
bool relocate(plant planttomove);
bool rake_paths();

};

#endif
