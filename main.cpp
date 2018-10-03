#include "Person.h"
#include "Flowers.h"
#include "FruitTrees.h"
#include "Shrubs.h"
#include "Succulents.h"
#include "Trees.h"

#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	string command;
	string answer;

	vector<Person> people;
	string name;
	string job;
	int number_of_people=0;

	cout << "Welcome to the University of Adelaide Garden Nursery!" << endl; 
	cout << "What would you like to do?" << endl;
	getline(cin,command);

	while (command!="Exit") {
		if (command=="Add Person") {
			cout << "Do you know their name and job?" << endl;
			cin >> answer;
			if (answer=="Yes") {
				cout << "Enter their name and job: ";
				cin >> name >> job;
				people.push_back(Person(name,job));
				cout << people[number_of_people].get_job() << " " << people[number_of_people].get_name() << " created." << endl;
				number_of_people++;
			} else if (answer=="No") {
				people.push_back(Person());
				cout << "Person created.";
				number_of_people++;
			} else {
				cout << "That is not a valid response. Please enter \"Yes\" or \"No\"." << endl;
			}
		} else {
			cout << "That is not a valid command. Type \"Help\" to see a list of valid commands." << endl;
		}
		cout << "What would you like to do next?" << endl;
		getline(cin,command);
	}

	return 0;
}
