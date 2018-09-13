#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{

std::string name; //name of worker
std::string job; //job
bool working;  //if they are currently at work

public:

Person();
Person(std::string name, std::string job, int experience);

//getters
bool at_work();
std::string get_name();
std::string get_job();

//setters
void set_name(std::string new_name);
void arrive(int shift_length);
void leave();

}

#endif PERSON_H
