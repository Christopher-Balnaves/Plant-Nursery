
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
	int amount2;
	int avail_stock_in_location[]={10,20,30,40,50};
	const int NO_OF_LOCATIONS=5;

	// Variables related to people
	Person* people[2];
	string name;
	string job;
	int number_of_people=0;

	// Variables related to plants
	vector<Plant*> inventory;
	string plant_type;
	string species;
	int location;
	double price;
	int current_stock;
	int possible_stock;




	cout << "Welcome to Bridget's Garden Nursery!" << endl; 
	cout << "What would you like to do?" << endl;
	getline(cin,command);

	while (command!="Exit") { 

		//Add New Person 
		if (command=="Add Person") {
			if (number_of_people>=2) {
				cout << "The nursery has all the employees it needs.";
			} else {
				cout << "Do you know their job?" << endl;
				getline(cin,answer);
				while ((answer!="Yes") && (answer!="No")){
						cout << "That is not a valid response. Please enter \"Yes\" or \"No\"." << endl;
						getline(cin,answer);
				}
				if (answer=="Yes") {
					cout << "Enter their job: ";
					getline(cin,job);
					while ((job!="Clerk") && (job!="Garden Hand")){
						cout << "That is not a valid response. Please enter \"Clerk\" or \"Garden Hand\"." << endl;
						getline(cin,job);
					}

					//Inputting information about new people
					cout << "Do you know their name?" << endl;
					getline(cin,answer);
					while ((answer!="Yes") && (answer!="No")){
						cout << "That is not a valid response. Please enter \"Yes\" or \"No\"." << endl;
						getline(cin,answer);
					}
					if (answer=="Yes") {
						cout << "Enter their name: ";
						getline(cin,name);
						if (job=="Clerk") {
							people[0]=new Clerk(name);
						} else if (job=="Garden Hand") {
							people[1]=new GardenHand(name,inventory.size());
						} else {
							cout << "Error." << endl;
						}

						// To construct an unnamed person
					} else if (answer=="No") {
						if (job=="Clerk") {
							people[0]=new Clerk();
						} else if (job=="Garden Hand") {
							people[1]=new GardenHand(inventory.size());
						}
					} else {
						cout << "That is not a valid response. Please enter \"Yes\" or \"No\"." << endl;	
					}
					cout << "A " << people[number_of_people]->get_job() << " called " << people[number_of_people]->get_name() << " was created." << endl;
					number_of_people++;

					//To create a person with unknown job and details - job is set for them 
				} else if (answer=="No") {
					if (number_of_people==0) {
						people[0]=new Clerk();
						cout << "A person was created and assigned the job 'Clerk'." << endl;
					} else if (number_of_people==1) {
						people[0]=new GardenHand();
						cout << "A person was created and assigned the job 'Garden Hand'." << endl;
					} else {
						cout << "Error. The nursery has all the employees it needs." << endl;
					}
					number_of_people++;
				} else {
					cout << "That is not a valid response. Please enter \"Yes\" or \"No\"." << endl;
				}
			}

			// Changing a person's name
		} else if (command=="Update Name") {
			cout << "Do you want to update the name of the Clerk or the Garden Hand?" << endl;
			getline(cin,job);
			while ((job!="Clerk") && (job!="Garden Hand")){
				cout << "That is not a valid response. Please enter \"Clerk\" or \"Garden Hand\"." << endl;
				getline(cin,job);
			}
			cout << "Enter the new name: " << endl;
			getline(cin,answer);
			if (job=="Clerk") {
				people[0]->set_name(answer);
			} else if (job=="Garden Hand") {
				people[1]->set_name(answer);
			} else {
				cout << "That is not a valid response. Please enter \"Yes\" or \"No\"." << endl;	
			}
			cout << "The " << job << " has been renamed " << answer << "." << endl;


			//Selling Plants			
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
					//only runs if there is stock
					cout << "Enter the amount to be sold: " << endl;
					cin >> amount;
					cin.ignore();
					boolean = people[0]->sell(inventory[arr_location],amount);
					if (boolean==true) {
						cout << "Sale successful." << endl;
						location=inventory[arr_location]->get_location();
						avail_stock_in_location[location]+=amount;
					} else {
						//incase inadequate stock
						cout << "Sale unsuccessful." << endl;
					}
				}
			}

			// Ordering Plants
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
				location=inventory[arr_location]->get_location();
				if (avail_stock_in_location[location]<=0) {
					cout << "There is no more space at that location for this plant." << endl;
				} else {
					cout << "Enter the amount to be ordered: " << endl;
					cin >> amount;
					while (amount<0) {
						cout << "You can't order a negative number of plants." << endl;
						cout << "Enter a positive number: " << endl;
						cin >> amount;
					}
					while (amount>avail_stock_in_location[location]) {
						cout << "There is only " << avail_stock_in_location[location] << " more spaces available at that location.";
						cin >> amount;
					}
					boolean = people[0]->order(inventory[arr_location],amount);
					if (boolean==true) {
						cout << "Order successful." << endl;
					} else {
						cout << "Order unsuccessful." << endl;
					}
					cin.ignore();
				}
			}

			//Add Plant
		} else if (command=="Add Plant") {
			cout << "What type of plant would you like to add?" << endl;	// Must be one of the valid sub-classes
			getline(cin,plant_type);
			if ((plant_type!="Fruit Tree") && (plant_type!="Tree") && (plant_type!="Flower") && (plant_type!="Succulent") && (plant_type!="Shrub")) {
				cout << "That is not a valid plant type. Type \"Plant Types\" to see a list of valid plant types." << endl;
			} else {
				cout << "Do you know the species?" << endl;		// Required to create a plant
				getline(cin,answer);
				if (answer=="Yes") {
					cout << "Do you know all of the following details?" << endl;	// Need all to use second constructor
					cout << "  Location Reference Number" << endl;
					cout << "  Price" << endl;
					cout << "  Current Stock" << endl;
					getline(cin,answer);
					if (answer=="Yes") {							// Getting the information
						cout << "Enter the species: ";
						getline(cin,species);
						cout << "Enter the location reference number: ";
						cin >> location;
						cout << "Enter the price: ";
						cin >> price;
						cout << "Enter the current stock level: ";
						cin >> current_stock;
						cin.ignore();
						while (current_stock>avail_stock_in_location[location]) {	
							cout << "Error. There is only room for " << avail_stock_in_location[location] << " more plants in that location." << endl; // If try to put more stock in location than possible, 
							cout << "Do you want to change your Stock Level or Location?" << endl;
							getline(cin,answer);
							if (answer=="Stock Level") {																								//must change either the stock level or
								cout << "Enter the current stock level: ";
								cin >> current_stock;
							} else if (answer=="Location") {																							//or location
								cout << "Enter the location reference number: ";
								cin >> location;
							} else {
								cout << "That is not a valid answer. Enter \"Stock Level\" or \"Location\".";
							}
							cin.ignore();
						}	
						if (plant_type=="Fruit Tree") {													// Call appropriate constructor
							inventory.push_back(new FruitTrees(species,price,current_stock,location));
						} else if (plant_type=="Tree") {
							inventory.push_back(new Trees(species,price,current_stock,location));
						} else if (plant_type=="Flower") {
							inventory.push_back(new Flowers(species,price,current_stock,location));
						} else if (plant_type=="Succulent") {
							inventory.push_back(new Succulents(species,price,current_stock,location));
						} else if (plant_type=="Shrub") {
							inventory.push_back(new Shrubs(species,price,current_stock,location));
						} else {
							cout << "You did not originally enter a valid plant type. Apologies for getting you to input additional information." // Error handling, should never reach here.
								" Type \"Plant Types\" to see a list of valid plant types and please try again." << endl;
						}
						avail_stock_in_location[location]-=current_stock;	// Reducing the available amount of stock in the location
					} else if (answer=="No") {					// Don't know all extra details, so use species only constructor
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
			
			// Setting plant price
		} else if (command=="Set Price") {
			cout << "Which species do you want to set the price of?" << endl;
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
				cout << "Enter the new price: " << endl;
				cin >> amount;
				cin.ignore();
				boolean=inventory[arr_location]->set_price(amount);
				if (boolean==true) {
					cout << "Price change successful." << endl;
				} else {
					cout << "Price change unsuccessful." << endl;
				}
			} 

			// Relocating plant
		} else if (command=="Relocate Plant") {
			cout << "Which species do you want to relocate?" << endl;
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
				cout << "Enter the new location reference number: " << endl;
				cin >> location;
				cin.ignore();
				boolean=people[1]->relocate(inventory[arr_location],location);
				if (boolean==true) {
					cout << "Relocation successful." << endl;
				} else {
					cout << "Relocation unsuccessful." << endl;
				}
			} 
			// Restocking plant
		} else if (command=="Restock Plant") {
			cout << "Which species do you want to restock?" << endl;
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
				cout << "Enter the new amount being restocked: " << endl;
				cin >> amount;
				cin.ignore();
				location=inventory[arr_location]->get_location();
				if (avail_stock_in_location[location]<amount) {
					cout << "Cannot restock that many plants into the current area. Either reduce the stock or change the plant location.";
				} else {
					boolean=people[1]->restock(inventory[arr_location],amount);
					if (boolean==true) {
						cout << "Restock successful." << endl;
						avail_stock_in_location[location]-=amount;		// Reducing available space in location
					} else {
						cout << "Restock unsuccessful." << endl;
					}
				}
			} 

			// Command to pick fruit from fruit trees in the nursery
		} else if (command=="Pick Fruit") {
			boolean=false;
			amount=0;
			amount2=0;
			for (int i = 0; i < inventory.size(); ++i) {
				if (boolean==true) break;
				if (inventory[i]->get_class_id()==3) {	// Checking if the plant is a fruit tree
					boolean=people[1]->pick_fruit(inventory[arr_location]); // Checking is fruit on fruit tree is ready to be picked
					if (boolean==true) { 									 // and incrementing amount if true and amount2 if not
						amount++; 	
					} else {
						amount2++;
					}
				}
			}

			if (boolean==false) {
				cout << "There is no fruit trees in the nursery." << endl;
			} else {
				cout << "Fruit picked succuessfully from " << amount << " trees." << endl;
				cout << "The fruit was not ready to be picked from " << amount << " trees.";
			}
			
			// Default Garden Hand Action
		} else if (command=="Rake Paths") {
			boolean=people[1]->rake_paths();
			if (boolean==true) {
				cout << people[1]->get_name() << " raked the paths." << endl;
			} else {
				cout << "The paths were not raked succuessfully";
			}

			// Commands to get information about plants
			// All plants	
		} else if (command=="List Plants") {
			cout << "The plants in the nursery are: " << endl;
			for (int i = 0; i < inventory.size(); ++i) {
				cout << "  " << inventory[i]->get_species() << endl;
			}

			// Specific plants
		} else if (command=="Get Information") {
			cout << "Which species do you want that information for?" << endl;
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
				people[0]->get_information(inventory[arr_location]);	// Will print the information
			}

			// Get info about current space in locations
		} else if (command=="Get Available Space") {
			cout << "Available space for each reference number is as follows: " << endl;
			for (int i = 0; i < NO_OF_LOCATIONS; ++i) {
				cout << i << ": " << avail_stock_in_location[i] << endl;
			}

			// Commands to get information about valid inputs
			// Plant types
		} else if (command=="Plant Types") {
			cout << "Plant types at the UoA Garden Nursery include:" << endl;
			cout << "  Fruit Tree" << endl;
			cout << "  Tree" << endl;
			cout << "  Flower" << endl;
			cout << "  Succulent" << endl;
			cout << "  Shrub" << endl;

			//Valid Commands
		} else if (command=="Help") {
			cout << "Valid commands include:" << endl;
			cout << "  Add Person" << endl;
			cout << "  Update Name" << endl;
			// cout << "  Change Job" << endl;
			cout << "  Sell" << endl;
			cout << "  Order" << endl;
			cout << "  Add Plant" << endl;
			cout << "  Set Price" << endl;
			cout << "  Restock Plant" << endl;
			cout << "  Relocate Plant" << endl;
			cout << "  Pick Fruit" << endl;
			cout << "  Get Information" << endl;
			cout << "  Plant Types" << endl;
			cout << "  List Plants" << endl;
			cout << "  Get Available Space" << endl;
			// cout << "  Water" << endl;
			// cout << "  Fertilize" << endl;
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
	for (int i = 0; i < 2; ++i)	{
		delete people[i];
	}

	for (int i = 0; i < inventory.size(); ++i)	{
		delete inventory[i];
	}

	return 0;
}