
#ifndef GARDENHAND_H
#define GARDENHAND_H

#include <string>
#include "Person.h"
#include "Plant.h"

class GardenHand : public Person
{

int assigned_location;

public:

//Constructors
GardenHand(int assignment);
GardenHand(std::string given_name, int assignment);

//Getters
int get_assigned_location();

//Methods
bool water(Plant* watering, int currentnumber); //each function returns true if the task needs to be done
bool fertilise(Plant* watering, int currentnumber);
bool restock(Plant* planttorestock, int n);
bool relocate(Plant* planttomove, int new_location);
bool pick_fruit(Plant* planttopick);
bool rake_paths();

};

#endif