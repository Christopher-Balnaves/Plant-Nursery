
#ifndef GARDENHAND_H
#define GARDENHAND_H

#include <string>
#include "Person.h"
#include "Plant.h"

class GardenHand : public Person
{

int currentno;

public:

//Constructors
GardenHand(std::string given_name, int ingarden);
GardenHand();
GardenHand(int ingarden);


//Methods
bool water(int currentnumber); //each function returns true if the task needs to be done
bool fertilise(int currentnumber);
bool restock(Plant* planttorestock, int n);
bool relocate(Plant* planttomove, int new_location);
bool pick_fruit(Plant* planttopick);
bool rake_paths();

};

#endif