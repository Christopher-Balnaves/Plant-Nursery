#include "Clerk.h"
#include "GardenHand.h"
#include "Plant.h"
#include "Flowers.h"
#include "FruitTrees.h"
#include "Shrubs.h"
#include "Succulents.h"
#include "Trees.h"

#include <iostream>
#include <vector>

using namespace std;

//g++ -o aout Plant.cpp FruitTrees.cpp Flowers.cpp Shrubs.cpp Succulents.cpp Trees.cpp Person.cpp GardenHand.cpp Clerk.cpp testgardenhand.cpp


int main(void) {

	// Variables related to plants
	vector<Plant*> inventory;
	string plant_type;
	string species;
	string location;
	double price;
	int current_stock;
	int possible_stock;
	bool ans;

	//Construct a fruit tree
	FruitTrees *fruittree = new FruitTrees("Orange", 43.0, 1, 3, "Outdoors");

	//Test watering function
	GardenHand bob("Bob", 5);
	bob.water(5); //should return true
	bob.water(0); //should return false
	

	//Test fertilise function
	bob.fertilise(3);
	bob.fertilise(0);

	//Test restock function
	for (int i = 2; i < 4; ++i)
	{
		ans = bob.restock(fruittree, i);
	
	if(ans==1){
		cout << " Plant was sucessfully restocked. " << endl;
	}
	else if (ans==0) {
		cout << " Plant was not sucessfully restocked. " << endl;
	}
	else{
		cout << " Error. " << endl;
	}
	}
	

	// Test relocate function
	if (bob.relocate(fruittree, "Indoor")==1){
		cout << "Plants were sucessfully relocated." << endl;
	}
	if (bob.relocate(fruittree, "Outdoors")==1){
		cout << "Plants were sucessfully relocated." << endl;
	}

	//Test rake paths function
	
	if (bob.rake_paths()==1){
		cout << "Paths were sucessfully raked." << endl;
	}
	if (bob.rake_paths()==0){
		cout << "Paths were sucessfully raked." << endl;
	}

	
    
	return 0;
}
