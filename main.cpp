#include "Clerk.h"
#include "GardenHand.h"
#include "Flowers.h"
#include "FruitTrees.h"
#include "Shrubs.h"
#include "Succulents.h"
#include "Trees.h"

#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	// Variables controlling running of nursery
	string command;
	string answer;
	int result;

	// Variables related to people
	vector<Person*> people;
	string name;
	string job;
	int number_of_people=0;

	// Variables related to plants
	vector<Plant*> inventory;
	string plant_type;
	string species;
	string location;
	double price;
	int current_stock;
	int possible_stock;




	cout << "Welcome to the University of Adelaide Garden Nursery!" << endl; 
	cout << "What would you like to do?" << endl;
	

	while (command!="Exit") {
		// cin.ignore();
		getline(cin,command); 
		if (command=="Add Person") {
			cout << "Do you know their job?" << endl;
			cin >> answer;
			if (answer=="Yes") {
				cout << "Enter their job: ";
				cin.ignore();
				getline(cin,job);
				if ((job!="Clerk") && (job!="Garden Hand")){
					cout << "That is not a valid response. Please enter \"Clerk\" or \"Garden Hand\"." << endl;
					getline(cin,job);
				}
				cout << "Do you know their name?" << endl;
				cin >> answer;
				if (answer=="Yes") {
					cout << "Enter their name: ";
					cin.ignore();
					getline(cin,name);
					if (job=="Clerk") {
						people.push_back(new Clerk(name));
					} 
					if (job=="Garden Hand") {
						people.push_back(new GardenHand(name,5));
					} else {
						cout << "Error." << endl;
					}
				} else if (answer=="No") {
					if (job=="Clerk") {
						people.push_back(new Clerk());
					} else if (job=="Garden Hand") {
						people.push_back(new GardenHand(5));
					}
				} else {
					cout << "That is not a valid response. Please enter \"Yes\" or \"No\"." << endl;	
				}
				cout << "A " << people[number_of_people]->get_job() << " called " << people[number_of_people]->get_name() << " was created." << endl;
				number_of_people++;
			} else if (answer=="No") {
				people.push_back(new Person());
				cout << "Person created."<< endl;
				number_of_people++;
			} else {
				cout << "That is not a valid response. Please enter \"Yes\" or \"No\"." << endl;
			}
		} else if (command=="Clerk") {
			result = people[0]->sell(inventory[0],1);
			if (result==1) {
				cout << "Worked" << endl;
			} else 
			if (result==0) {
				cout << "Didn't work" << endl;
			}
		} else if (command=="Garden Hand") {
			result = people[0]->restock(inventory[0],1);
			if (result==1) {
				cout << "Worked" << endl;
			} else 
			if (result==0) {
				cout << "Didn't work" << endl;
			}
		} else if (command=="Add Plant") {
			cout << "What type of plant would you like to add?" << endl;
			cin >> plant_type;
			if ((plant_type!="Fruit Tree") && (plant_type!="Tree") && (plant_type!="Flower") && (plant_type!="Succulent") && (plant_type!="Shrub")) {
				cout << "That is not a valid plant type. Type \"Plant Types\" to see a list of valid plant types." << endl;
			} else {
				cout << "Do you know the species?" << endl;
				cin >> answer;
				if (answer=="Yes") {
					cout << "Do you know all of the following details?" << endl;
					cout << "  Location" << endl;
					cout << "  Price" << endl;
					cout << "  Current Stock" << endl;
					cout << "  Possible Stock" << endl;
					cin >> answer;
					if (answer=="Yes") {
						cin.ignore();
						cout << "Enter the species: ";
						getline(cin,species);
						cout << "Enter the location: ";
						getline(cin,location);
						cout << "Enter the price, current_stock and possible_stock: ";
						cin >> price >> current_stock >> possible_stock;
						if (plant_type=="Fruit Tree") {
							inventory.push_back(new FruitTrees(species,price,current_stock,possible_stock,location));
						} else if (plant_type=="Tree") {
							inventory.push_back(new Trees(species,price,current_stock,possible_stock,location));
						} else if (plant_type=="Flower") {
							inventory.push_back(new Flowers(species,price,current_stock,possible_stock,location));
						} else if (plant_type=="Succulent") {
							inventory.push_back(new Succulents(species,price,current_stock,possible_stock,location));
						} else if (plant_type=="Shrub") {
							inventory.push_back(new Shrubs(species,price,current_stock,possible_stock,location));
						} else {
							cout << "You did not originally enter a valid plant type. Apologies for getting you to input additional information."
								" Type \"Plant Types\" to see a list of valid plant types and please try again." << endl;
						}
					} else if (answer=="No") {
						cin.ignore();
						cout << "Enter the species: ";
						getline(cin,species);
						if (plant_type=="Fruit Tree") {
							inventory.push_back(new FruitTrees(species));
						} else if (plant_type=="Tree") {
							inventory.push_back(new Trees(species));
						} else if (plant_type=="Flower") {
							inventory.push_back(new Flowers(species));
						} else if (plant_type=="Succulent") {
							inventory.push_back(new Succulents(species));
						} else if (plant_type=="Shrub") {
							inventory.push_back(new Shrubs(species));
						}

					} else {
						cout << "You did not originally enter a valid plant type. Apologies for getting you to input additional information."
							" Type \"Plant Types\" to see a list of valid plant types and please try again." << endl;	
					}
				} else if (answer=="No") {
					cout << "You must know the species to create a plant. Plant creation unsuccessful." << endl;
				} else {
					cout << "That is not a valid response. Please enter \"Yes\" or \"No\"." << endl;	
				}
			}

		} else if (command=="Plant Types") {
			cout << "Plant types at the UoA Garden Nursery include:" << endl;
			cout << "  Fruit Tree" << endl;
			cout << "  Tree" << endl;
			cout << "  Flower" << endl;
			cout << "  Succulent" << endl;
			cout << "  Shrub" << endl;
		} else if (command=="Help") {
			cout << "Valid commands include:" << endl;
			cout << "  Add Person" << endl;
			cout << "  Update Person Details" << endl;
			cout << "  Help" << endl;
			cout << "  Exit" << endl;
		} else {
			cout << "That is not a valid command. Type \"Help\" to see a list of valid commands." << endl;
		}
		cout << "What would you like to do next?" << endl;
	}


	// Deleting created people and plants
	for (int i = 0; i < people.size(); ++i)	{
		delete people[i];
	}

	for (int i = 0; i < inventory.size(); ++i)	{
		delete inventory[i];
	}

	return 0;
}