#include "Person.h"
#include <string>

using namespace std;

Person::Person(){

name="?";
job = "?"; 
working= false;
}

Person::Person(string pname, string pjob){

name=pname;
job=pjob;
working = false;
}

//getters
bool Person::at_work(){
return working;
}

string Person::get_name(){
return name;
}

string Person::get_job(){
return job;
}

//setters
void Person::set_name(std::string new_name){
name=new_name;
}

void Person::arrive(){
working = true;
}
void Person::leave(){
working = false;
}
