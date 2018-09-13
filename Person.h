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
Person(std::string pname, std::string pjob, int pexperience);

//getters
bool at_work();
std::string get_name();
std::string get_job();

//setters
void set_name(std::string new_name);
void arrive();
void leave();

};

#endif
