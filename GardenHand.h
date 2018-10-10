
#ifndef GARDENHAND_H
#define GARDENHAND_H

#include <string>
#include "Person.h"
#include "Plant.h"

class GardenHand : public Person
{

//Plant * plantsingarden;
int currentno;

public:

GardenHand(std::string given_name, int ingarden);
GardenHand();
GardenHand(int ingarden);

// int get_number_to_water(); // depends on how boolean functions work
// int get_number_to_fertilise();

bool water(); //each function returns true if the task needs to be done
bool fertilise();
bool restock(Plant* planttorestock, int n);
bool relocate(Plant* planttomove, std::string new_location);
bool rake_paths();

};

#endif