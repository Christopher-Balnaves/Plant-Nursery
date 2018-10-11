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
	int arr_location;
	bool boolean;
	int amount;

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




	cout << "Welcome to Bridget's Garden Nursery!" << endl; 
	cout << "What would you like to do?" << endl;
	getline(cin,command);

	while (command!="Exit") { 
		if (command=="Add Person") {
			cout << "Do you know their job?" << endl;
			getline(cin,answer);
			if (answer=="Yes") {
				cout << "Enter their job: ";
				getline(cin,job);
				if ((job!="Clerk") && (job!="Garden Hand")){
					cout << "That is not a valid response. Please enter \"Clerk\" or \"Garden Hand\"." << endl;
					getline(cin,job);
				}
				cout << "Do you know their name?" << endl;
				getline(cin,answer);
				if (answer=="Yes") {
					cout << "Enter their name: ";
					getline(cin,name);
					if (job=="Clerk") {
						people.push_back(new Clerk(name));
					} else if (job=="Garden Hand") {
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
		} else if (command=="Update Person Details") {
			cout << "You can't update person details at the moment." << endl;






			s
		} else if (command=="Sell") {
			cout << "Which species do you want to sell?" << endl;
			getline(cin,species);
			boolean=false;
			// Getting vector location of species in question
			for (int i = 0; i < inventory.size(); ++i) {
				if (boolean==true) break;
				if (species==inventory[i]->get_species()) {
					arr_location=i;
					boolean=true;
				}
			}
			if (boolean==false) {
				cout << "There is no species by that name in the nursery." << endl;
			} else {
				if (inventory[arr_location]->get_current_stock()==0) {
					cout << "There is no stock available of this plant." << endl;
				} else {
					cout << "Enter the amount to be sold: " << endl;
					cin >> amount;
					cin.ignore();
					boolean = people[0]->sell(inventory[arr_location],amount);
					if (boolean==true) {
						cout << "Sale successful." << endl;
					} else {
						cout << "Sale unsuccessful." << endl;
					}
				}
			}
		} else if (command=="Order") {
			cout << "Which species do you want to order?" << endl;
			getline(cin,species);
			boolean=false;
			// Getting vector location of species in question
			for (int i = 0; i < inventory.size(); ++i) {
				if (boolean==true) break;
				if (species==inventory[i]->get_species()) {
					arr_location=i;
					boolean=true;
				}
			}
			if (boolean==false) {
				cout << "There is no species by that name in the nursery." << endl;
			} else {
				if (inventory[arr_location]->get_current_stock()==0) {
					cout << "There is no stock available of this plant." << endl;
				} else {
					cout << "Enter the amount to be ordered: " << endl;
					cin >> amount;
					while (amount<0) {
						cout << "You can't order a negative number of plants." << endl;
						cout << "Enter a positive number: " << endl;
						cin >> amount;
					}
					cin.ignore();
					boolean = people[0]->order(inventory[arr_location],amount);
					if (boolean==true) {
						cout << "Order successful." << endl;
					} else {
						cout << "Order unsuccessful." << endl;
					}
				}
			}
		} else if (command=="Garden Hand") {
			boolean = people[0]->restock(inventory[0],1);
			if (boolean==true) {
				cout << "Worked" << endl;
			} else 
			if (boolean==false) {
				cout << "Didn't work" << endl;
			}
		} else if (command=="Add Plant") {
			cout << "What type of plant would you like to add?" << endl;
			getline(cin,plant_type);
			if ((plant_type!="Fruit Tree") && (plant_type!="Tree") && (plant_type!="Flower") && (plant_type!="Succulent") && (plant_type!="Shrub")) {
				cout << "That is not a valid plant type. Type \"Plant Types\" to see a list of valid plant types." << endl;
			} else {
				cout << "Do you know the species?" << endl;
				getline(cin,answer);
				if (answer=="Yes") {
					cout << "Do you know all of the following details?" << endl;
					cout << "  Location" << endl;
					cout << "  Price" << endl;
					cout << "  Current Stock" << endl;
					cout << "  Possible Stock" << endl;
					getline(cin,answer);
					if (answer=="Yes") {
						cout << "Enter the species: ";
						getline(cin,species);
						cout << "Enter the location: ";
						getline(cin,location);
						cout << "Enter the price, current stock level and possible stock level: ";
						cin >> price >> current_stock >> possible_stock;
						cin.ignore();
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
			cout << "  Sell" << endl;
			cout << "  Order" << endl;
			cout << "  Get Current Stock" << endl;
			cout << "  Set Price" << endl;
			cout << "  Garden Hand" << endl;
			cout << "  Add Plant" << endl;
			cout << "  Plant Types" << endl;
			cout << "  List Plants" << endl;
			cout << "  Water" << endl;
			cout << "  Fertilize" << endl;
			cout << "  Pick Fruit" << endl;
			cout << "  Rake Paths" << endl;
			cout << "  Help" << endl;
			cout << "  Exit" << endl;
		} else {
			cout << "That is not a valid command. Type \"Help\" to see a list of valid commands." << endl;
		}
		cout << "What would you like to do next?" << endl;
		getline(cin,command);
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