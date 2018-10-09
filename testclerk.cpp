//WE NEED TO TEST WHEN INCORRECT ARGUMENTS ARE PASSED INTO THE FUNCTION


#include "Person.h"
//#include "Flowers.h"
//#include "FruitTrees.h"
//#include "Shrubs.h"
//#include "Succulents.h"
//#include "Trees.h"
#include "GardenHand.h"
#include "Clerk.h"

#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {

	string command;
	string answer;

	vector<Person*> people; //Note '*' sign this mean this vector now stores pointers to person objects
	string name;
	string job;
	string plant;
	string location;
	bool result=0;
	int number_of_people=0;
	int number;

	cout << "Do you want to create a person?" << endl;
	cin >> answer;

	if (answer=="Yes")
	{
		cout << "Enter their name and job: " << endl;

		cin >> name >> job; //need to make new to prevent object slicing
		people.push_back(new Person(name,job));
		number_of_people++;

		cout << "Do you want to change their name?" << endl;
		cin >> answer;

		if (answer=="Yes")
		{
			people[number_of_people-1]->set_name(name);
		}
		
	}

	people.push_back(new Clerk("Bob"));
	people.push_back(new GardenHand("Josh", 10));

	people[0]->test();

	// Clerk Testing
	
	cout << "Do you have a plant for the Clerk to sell?" << endl;
	cin >> answer;

	if (answer=="Yes")
	{
		cout << "What is the plant? and how many? " << endl;
		cin >> plant >> number;
		people[number_of_people-1]->get_name();//sell(plant, number);
	}
	

	cout << "Do you have a plant for the Clerk to order?" << endl;
	cin >> answer;

	if (answer=="Yes")
	{
		cout << "What is the plant? and how many? " << endl;
		cin >> plant >> number;
		people[number_of_people-1]->get_name();//order(plant, number);
	}
	
	cout << "Do you need current stock for a plant? " << endl;
	cin >> answer;

	if (answer=="Yes")
	{
		cout << "What is the plant? " << endl;
		cin >> plant;
		people[number_of_people-1]->get_name();//get_current_stock(plant, number);
	}
	
	cout << "Do you want the clerk to set a price? " << endl;
	cin >> answer;

	if (answer=="Yes")
	{
		cout << "What is the plant? What is the price? " << endl;
		cin >> plant >> number;
		cout << people[number_of_people-1]->get_name() << endl;//set_price(plant, number);
	}

	cout << "Do you have a plant to move?" << endl;
	cin >> answer;
	
	if (answer=="Yes")
	{
		cout << "What is the plant? What is the new location? " << endl;
		cin >> plant >> location;


		Person *temp = new GardenHand("Tom",2);
		//temp = GardenHand gard("Tom",2);
		result = people[1]->rake_paths();
		//temp->rake_paths();
		//bool result = people[number_of_people-1]->relocate(plant, location);

		if (result==1)
		{
			cout << "Worked" << endl;
		}
		if (result==0)
		{
			cout << "Didn't work" << endl;
		}
		delete temp;

	}

	
	//GardenHand Testing

	/*
	cout << "Testing GardenHand " << endl;
	cout << "Do you want to water a plant?"
	cin >> answer;

	if (answer=="Yes")
	{
		cout << "What is the plant? What is the price?" << endl;
		cin >> plant >> number;
		Bob.set_price(plant, number);
	}
	bool water(); //each function returns true if the task needs to be done
bool fertilise();
bool restock(int insection, int capacitysection);
bool relocate(plant planttomove, std::string new_location);
bool rake_paths();*/


	return 0;
}