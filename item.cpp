//impelnts all of the things for header file




#include <iostream>
#include <cstring>
#include "item.h"

using namespace std;
//sets item name 
void Item::setName(char* nameOut){
  strcpy(name, nameOut);
}
//retrive the other items name

void Item::getName(char* nameOut){
  strcpy(nameOut, name);
}

void Item::printItem(){
  cout << name << endl;
}
