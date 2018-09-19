#include "Clerk.h"
#include <string>
#include "Person.h"
#include "Plant.h"


Clerk(std::string pname) : Person (pname, "Clerk"){
}

Clerk() : Person ("?", "Garden Hand"){
}

//methods
bool sell(plant planttosell){
  //SELECT PLANT TO SELL AND DELETE FROM ARRAY
}

bool order(plant planttoorder, int n){
  //ADD ORDERED PLANTS TO ARRAY
}

int get_current_stock(plant planttocheck){
  //SEARCH ARRAY FOR PARTICULAR PLANT
}

//setters
void set_price(plant planttochangeprice){
    //SET PRICE OF PLANT
}
