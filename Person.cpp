#include "Person.h"
#include <string>

using namespace std;

Person::Person(){

name="?";
job = "?"; 
working= false;
}

Person::Person(string pname, string pjob, int pexperience){

name=pname;
job=pjob;
experience=pexperience;
working = false;
}

//getters
bool at_work(){
return working;
}
std::string get_name(){
return name;
}

std::string get_job(){
return job;
}

//setters
void set_name(std::string new_name){
name=new_name;
}

void arrive(){
working = true;
}
void leave(){
working = false;
}
