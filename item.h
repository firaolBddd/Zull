//header file for items 
//asign public var
#include <iostream>
#include <cstring>

#ifndef ADD_H
#define ADD_H

using namespace std;

class Item{
public:
  void setName(char* nameOut);
  void getName(char* nameOut);
  void printItem();
  char name[80];
};
#endif
