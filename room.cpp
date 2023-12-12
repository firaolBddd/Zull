//file that make all the function form the header file work
//all usable for entreting extiting ect.


#include <iostream>
#include <cstring>
#include "room.h"
#include "item.h"
#include <map>

using namespace std;
//proly use vector to account for size 
//adds an item using vector 

void Room::addItem(char* nameOut){
  //adds item to room
  Item* itemNew = new Item();
  itemNew->setName(nameOut);
  roomItems.push_back(itemNew);
}

void Room::giveItems(vector<Item*>& playerInv, char* nameOut){
  //adds item to player inv, erases from room
  for(int i = 0; i < roomItems.size(); i++){
    roomItems[i]->getName(charInput);
    if(strcmp(nameOut, charInput) == 0){
      playerInv.push_back(roomItems[i]);
      roomItems.erase(roomItems.begin() +i);
    }
  }
}

void Room::takeItems(vector<Item*>& playerInv, char* nameOut){
  //erases item from player inv, adds to room
  for(int i = 0; i < playerInv.size(); i++){
    playerInv[i]->getName(charInput);
    if(strcmp(nameOut, charInput) == 0){
      roomItems.push_back(playerInv[i]);
      playerInv.erase(playerInv.begin() +i);
    }
  }
}

//setters & getters
void Room::setName(char* nameOut){
  strcpy(name, nameOut);
}

void Room::getName(char* charIn){
  strcpy(charIn, name);
}

void Room::setExit(char* dir, Room* roomExit){
  mymap.insert(pair<char*, Room*>(dir, roomExit));
}

void Room::getExit(char* dir, Room*& roomCurrent){
  for(it = mymap.begin(); it != mymap.end(); it++){
    //cout << dir << " | " << it->first << endl;
    if(strcmp(dir, it->first) == 0){
      roomCurrent = it->second;
    }
  }
}

void Room::printDesc(char* output){
  cout << "You are in " << name << endl;
  cout << "Items: " << endl;
  if(roomItems.size() > 0){
    for(int i = 0; i < roomItems.size(); i++){
      roomItems[i]->getName(output);
      cout << " " << output << endl;
    }
  }else{
    cout << " N/A" << endl;
 }
  cout << "Exits: " << endl;
  for(it = mymap.begin(); it!= mymap.end(); it++){
    if(strcmp("North", it->first) == 0){
      cout << " North,";
    }
    if (strcmp("East", it->first) == 0){
      cout << " East,";
    }
    if(strcmp("South", it->first) == 0){
      cout << " South,";
    }
    if(strcmp("West", it->first) == 0){
      cout << " West,";
    }
  }
  cout << endl;
}

